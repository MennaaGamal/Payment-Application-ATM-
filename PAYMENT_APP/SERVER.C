#include "SERVER.H"

int Account_DB;

ST_accountsDB_t DB[5] = { { 5000 , "1234567891234567" },
                          { 30000 , "0100375635201003" },
                          { 80000 , "9876543219876543" },
                          { 3000  , "1472583691472583" },
                          { 65000 , "1234567899876543" } };

ST_transaction_t T_DB[255] = { 0 };

uint32_t sequence_Num = 1;


EN_serverError_t isValidAccount(ST_cardData_t* cardData) {
    

    for (int i = 0; i < 5; i++) {
        
        if (strcmp(cardData->primaryAccountNumber, DB[i].primaryAccountNumber))
        {
            continue;
        }
        else
        {
            Account_DB = i;

            return OK;
        }
            
    }

    return ACCOUNT_NOT_FOUND;
}

EN_serverError_t isAmountAvailable(ST_terminalData_t* termData) {

    if (DB[Account_DB].balance > termData->transAmount)
    {
        return OK;
    }
    else
    {
        return LOW_BALANCE;
    }
}

EN_transState_t recieveTransactionData(ST_transaction_t* transData) {

    transData->cardHolderData = card;
    transData->terminalData = term;

    int temp=isValidAccount(&transData->cardHolderData);

    if (temp == OK)
    
    {
        temp = isAmountAvailable(&transData->terminalData);

        if (temp == OK)
        {
            DB[Account_DB].balance -= transData->terminalData.transAmount;
            
            transData->transState = APPROVED;

            printf("TRANSACTION APPROVED\n");

            printf("YOUR REMAINING BALANCE : %.2f \n", DB[Account_DB].balance);
            
        }
        else
        {
            transData->transState = DECLINED_INSUFFECIENT_FUND;

            printf("DECLINED INSUFFECIENT FUND \n");
        }
    }
    else
    {
        transData->transState = DECLINED_STOLEN_CARD;

        printf("DECLINED STOLEN CARD\n");
    }
}

EN_serverError_t saveTransaction(ST_transaction_t* transData) {

    transData->transactionSequenceNumber = sequence_Num;

    T_DB[sequence_Num - 1] = trans;

    printf("transaction saved : \n %s \n", T_DB[sequence_Num - 1].cardHolderData.cardExpirationDate);

    sequence_Num++;
    
   
}