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

	printf("Please Enter the Primary Account Number:\n");
	gets(x.primaryAccountNumber);

	printf("Please card Expiry Date:\n");
	gets(x.cardExpirationDate);

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
    if(data.transAmount > data.maxTransAmount)
    {
        return data;
    }
    printf("Please Enter transaction Date 'DD/MM/YYYY':\n");
    char date[10];
    scanf("%s",&date);
    const char s[2] = "/"; //"String Seperator"

    int Transaction_DD = atoi(strtok(date, s));
    int Transaction_MM = atoi(strtok(NULL, s));
    int Transaction_YY = atoi(strtok(NULL, s));

    int Card_MM = atoi(strtok(cardExpirationDate, s));
    int Card_YY = atoi(strtok(NULL, s)) + 2000;
    if( Transaction_YY <= Card_YY && Transaction_MM <= Card_MM)
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
