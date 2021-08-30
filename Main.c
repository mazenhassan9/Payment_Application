#include"Data.h"
#include <stdio.h>
#include<string.h>

#define Y 1
#define N 0
int main()
{
    St_accountBalance_t DataServer[] = {
        {"123456789",100},{"234567891",6000},{"567891234",3250.25},
        {"456789123",1500.12},{"258649173",500},{"654823719",2100},
        {"971362485",0},{"793148625",1},{"123123456",10.12},{"456789321",.55}
    }; //Intialzing the server.
    size_t size = sizeof DataServer / sizeof DataServer[0];

    int start = Y;
while (start == 1)
{

    EN_transStat_t Transaction_Status = DECLINED;
    ST_cardData_t card_data = readCardData(); //Getting The Card Info.
    ST_terminalData_t Terminal_Data = GetInputAmount(card_data.cardExpirationDate); //Getting the Terminal Data
    if(strcasecmp(Terminal_Data.transactionDate,"0")==0)
    {
        printf("The Transaction is DECLINED.\n");
        printf("The Transaction Amount Exceeded The Maximum Transaction\n");
        Transaction_Status = DECLINED;
    }
    else if (strcasecmp(Terminal_Data.transactionDate,"-1")==0)
    {
        printf("The Transaction is DECLINED.\n");
        printf("Your Card is Expiered\n");
        Transaction_Status = DECLINED;
    }
    else
    {
        printf("Verifying Data from the server...");
        int index = linearsearch(DataServer,card_data.primaryAccountNumber,size);
        if (index == -1)
        {
            printf("The Transaction is DECLINED.\n");
            printf("Your Primary Account Number Doesn't Exist\n");
            Transaction_Status = DECLINED;
        }
        else
        {
            float Useramount = DataServer[index].balance;
            if (Useramount < Terminal_Data.transAmount)
            {
                printf("The Transaction is DECLINED.\n");
                printf("No Enough Balance\n");
                Transaction_Status = DECLINED;
            }
            else
            {
                printf("The Transaction is Approved.\n");
                Transaction_Status = APPROVED;
            }
        }
    }
    printf("Do You want to Continue (Y/N)\n");
    scanf("%s",&start);
    if(start == 0)
    {
        printf("Thanks for using our Payment Application\n")
    }
}
}
