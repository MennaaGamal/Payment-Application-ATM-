#include"APP.H"

void appStart(void) {

	while (1)
	{
		if (getCardHolderName(&card))
		{
			printf("WRONG_NAME \n");
		}
		else
		{
			if (getCardExpiryDate(&card))
			{
				printf("WRONG_EXP_DATE \n");
			}
			else
			{
				if (getCardPAN(&card))
				{
					printf("WRONG_PAN \n");
				}
				else
				{
					if (getTransactionDate(&term))
					{
						printf("WRONG_DATE \n");
					}
					else
					{
						if (isCardExpired(&card, &term))
						{
							printf("EXPIRED_CARD \n");
						}
						else
						{
							if (getTransactionAmount(&term))
							{
								printf("INVALID_AMOUNT \n");
							}
							else
							{
								if (setMaxAmount(&term))
								{
									printf("INVALID_MAX_AMOUNT \n");
								}
								else
								{
									if (isBelowMaxAmount(&term))
									{
										printf("EXCEED_MAX_AMOUNT \n");
									}
									else
									{
										recieveTransactionData(&trans);
									}
								}
							}
						}

					}
				}
			}

		}	
		saveTransaction(&trans);

	}
}








