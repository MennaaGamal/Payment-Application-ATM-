#include"TERMINAL.H"



EN_terminalError_t getTransactionDate(ST_terminalData_t* termData) {

	printf("Enter Transaction Date ( DD/MM/YYYY )\n");

	gets(termData->transactionDate);

	if (strlen(termData->transactionDate) == 10 && termData->transactionDate[2] == '/' && termData->transactionDate[5] == '/')
	{
		return OK;
	}
	else
	{
		return WRONG_DATE;
	}
}

EN_terminalError_t isCardExpired(ST_cardData_t* cardData, ST_terminalData_t* termData) {

	if ((termData->transactionDate[8] * 10) + termData->transactionDate[9] > (cardData->cardExpirationDate[3] * 10) + cardData->cardExpirationDate[4])
	{
		return EXPIRED_CARD;
	}
	else if ((termData->transactionDate[8] * 10) + termData->transactionDate[9] < (cardData->cardExpirationDate[3] * 10) + cardData->cardExpirationDate[4])
	{
		return OK; 
	}
	else
	{
		if ((termData->transactionDate[3] * 10) + termData->transactionDate[4] >= (cardData->cardExpirationDate[0] * 10) + cardData->cardExpirationDate[1])
		{
			return EXPIRED_CARD;
	    }
		else if ((termData->transactionDate[3] * 10) + termData->transactionDate[4] < (cardData->cardExpirationDate[0] * 10) + cardData->cardExpirationDate[1])
		{
			return OK;
		}
	}

}

EN_terminalError_t getTransactionAmount(ST_terminalData_t* termData) {

	printf("Enter Transaction Amount\n");

	scanf_s("%f", &termData->transAmount);

	getchar();

	if (termData->transAmount <= 0) {
		return INVALID_AMOUNT;
	}
	else {
		return OK;
	}
}
EN_terminalError_t setMaxAmount(ST_terminalData_t* termData) {

	termData->maxTransAmount = MAX_AMOUNT;

	if (termData->maxTransAmount <= 0) {
		return INVALID_MAX_AMOUNT;
	}
	else {
		return OK;
	}
}

EN_terminalError_t isBelowMaxAmount(ST_terminalData_t* termData) {

	if (termData->transAmount > termData->maxTransAmount) {
		return EXCEED_MAX_AMOUNT;
	}
	else
	{
		return OK;
	}
}