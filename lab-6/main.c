#include <stdio.h>

float balance = 0.00;

int authenticate(int pin)
{
	if (pin == 8907)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

float requestAmount()
{
	float amount;
	printf("Enter the amount you want to withdraw: ");
	scanf("%f", &amount);
	return amount;
}

void deposit()
{
	float amount = requestAmount();
	balance += amount;
	printf("Your new balance is %g\n", balance);
}

void withDraw(float amount)
{
	if (amount > balance)
	{
		printf("Insufficient funds\n");
	}
	else
	{
		balance -= amount;
		printf("Your new balance is %g\n", balance);
	}
}

void transfer()
{
	int account_number;
	printf("Enter the account number of the recipient: ");
	scanf("%d", &account_number);
	float amount = requestAmount();
	if (amount > balance)
	{
		printf("Insufficient funds\n");
	}
	else
	{
		balance -= amount;
		printf("Your new balance is %g\n", balance);
	}
}

int main()
{
	int tries = 0;

	start:
	printf("WELCOME TO ABC BANK\nEnter your four digit pin\n");
	int pin = 0;
	scanf("%d", &pin);

	menu:

	if (authenticate(pin) && tries < 4)
	{
		int menu_item;

		printf("Select an option\n1. Check Balance\n2. Withdrawal\n3. Deposit\n4. Transfer\n");
		scanf("%d", &menu_item);
		switch (menu_item)
		{
		case 1:
			printf("%g\n", balance);
			break;
		case 2:
			withDraw(requestAmount());
			break;
		case 3:
			deposit();
			break;
		case 4:
			transfer();
		}
	}
	else
	{
		++tries;
		if (tries < 4)
		{

			printf("Invalid pin after %d tries\n", tries);
			goto start;
		}
		else
		{
			printf("Invalid pin after %d tries\n", tries);
			printf("You have exceeded the number of tries\n");
			return 1;
		}
	}

	int response;
	printf("Would you like to perform another transaction?\n1. Yes\n2. No\n");
	scanf("%d", &response);
	if (response == 1)
	{
		goto menu;
	}

	printf("Thank you for banking with us.\n");
	return 0;
}
