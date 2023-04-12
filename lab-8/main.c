#include <stdio.h>

void add(float *res, float operand)
{
	printf("%f + %f", *res, operand);
	*res += operand;
	printf(" = %f", *res);
	return (res);
};

void mult(float *res, float operand)
{
	printf("%f * %f", *res, operand);
	*res *= operand;
	printf(" = %f", *res);
	return (res);
};

void div(float *res, float operand)
{
	printf("%f / %f", *res, operand);
	*res /= operand;
	printf(" = %f", *res);
	return (res);
};

void sub(float *res, float operand)
{
	printf("%f - %f", *res, operand);
	*res -= operand;
	printf(" = %f", *res);
	return (res);
};

int main()
{
	float a, b; // a = first operand, b = second operand

	printf("\n");
	printf("\t0\t1\t2\t3\t4\t5\t6\t7\t8\t\9\n\n");
	printf("\t+\t-\t*\t/\t@\t#\n\n");

	float *res = &a; // result
	char op; // operation
	int isOn = 1; // 1 = on, 0 = off

	start:
	printf("Start calculations :)\n");
	printf("Enter the first number: ");scanf(" %f", &a);

	do {
		printf("\nEnter the operation: ");scanf(" %c", &op);
		printf("\nEnter the second number: ");scanf(" %f", &b);

		switch (op) {
			case '+':
				add(res, b);
				break;
			case '-':
				sub(res, b);
				break;
			case '*':
				mult(res, b);
				break;
			case '/':
				div(res, b);
				break;
			case '@':
				goto start;
				break;
			case '#':
				printf("Bye bye!\n");
				isOn = 0;
				break;
			default:
				printf("Invalid operation!\n");
				break;
		}
	} while (isOn);
	return 0;
}
