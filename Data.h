//Header file to the Sturcutres and Functions

//Stucture of the Credit Card Info.
typedef struct ST_cardData_t
{
	char cardHolderName[25], primaryAccountNumber[20], cardExpirationDate[6];
} ST_cardData_t;

//Structure of the Terminal Data.
typedef struct ST_terminalData_t
{
    char* transactionDate;
    float transAmount;
    float maxTransAmount;

}ST_terminalData_t;

//Struture of the account balance at the server.
typedef struct ST_accountBalance_t
{
	char primaryAccountNumber[20];
    float balance;
}St_accountBalance_t;

//Enum for the Transacation State
typedef enum EN_transStat_t
{
    DECLINED,
    APPROVED
}EN_transStat_t;

//Structure of The Transaction Data.
typedef struct ST_transaction_t
{
    ST_cardData_t cardHolderData;
    ST_terminalData_t transData;
    EN_transStat_t transStat;
}ST_transaction;

// Defining Getting Inputs Function.

//1- Getting the Data Card Input.
ST_cardData_t readCardData();

//2- Getting the Terminal Data Input.
ST_terminalData_t GetInputAmount(char cardExpirationDate[6]);


//3- Binary Search in the Server to return the place of the PAN in the data otherwise -1.
int linearsearch(St_accountBalance_t *Database,char *PAN,int Size);
