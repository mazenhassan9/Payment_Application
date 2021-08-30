#include"Data.h"
#include <stdio.h>
#include <stdint.h>
#include <string.h>

//Function Used to read Data input.
ST_cardData_t readCardData()
{
	ST_cardData_t x;

	printf("Please Enter Card Data:\nPlease Enter the Card Holder Name:\n");
	gets(x.cardHolderName);
	fflush(stdin);

	printf("Please Enter the Primary Account Number:\n");
	gets(x.primaryAccountNumber);
	fflush(stdin);

	printf("Please card Expiry Date:\n");
	gets(x.cardExpirationDate);
	fflush(stdin);
	return x;
}

//Function Used to Read the Terminal Data Input. //Return Transaction State "Declined or Approved"
ST_terminalData_t GetInputAmount(char cardExpirationDate[6])
{
    ST_terminalData_t data;
    data.maxTransAmount = 5000;
    data.transactionDate = "0"; //intializing to zero to check if the maxTransamount exceeded or not.
	printf("Please Enter The Terminal Data:\n");
    printf("Please Enter The Transaction Amount:\n");
    scanf("%f",&data.transAmount);
    fflush(stdin);
    if(data.transAmount > data.maxTransAmount)
    {
        return data;
    }
    printf("Please Enter transaction Date 'DD/MM/YYYY':\n");
    char date[10];
    scanf("%s",&date);
    fflush(stdin);
    const char s[2] = "/"; //"String Seperator"

    int Transaction_DD = atoi(strtok(date, s));
    int Transaction_MM = atoi(strtok(NULL, s));
    int Transaction_YY = atoi(strtok(NULL, s));

    int Card_MM = atoi(strtok(cardExpirationDate, s));
    int Card_YY = atoi(strtok(NULL, s)) + 2000;
    if( Transaction_YY <= Card_YY || Transaction_YY == Card_YY && Transaction_MM <= Card_MM)
    {
        data.transactionDate = date;
    }
    else
    {
        data.transactionDate = "-1"; //Indication Value that the Card is Expiered.
    }
    return data;
}
//Search for the index of
int linearsearch(St_accountBalance_t *Database,char *PAN,int Size)
{
    for (int i =0; i < Size;i++)
    {
        if(strcmp(Database[i].primaryAccountNumber,PAN) == 0)
        {
            return i;
        }
    }
    return -1;
}

//add Transaction to the Transacions Database
int add_transaction(ST_transaction_t *Transactions, ST_transaction_t entry, int num_items)
{
    if (num_items < 100)
    {
        Transactions[num_items] = entry;
        num_items += 1;
        return 1;
    }
    return 0;
}
