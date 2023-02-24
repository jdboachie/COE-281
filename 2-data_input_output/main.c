#include <stdio.h>
#include <stdlib.h>

int main()
{
	// printf("Hello, User!\n");

	// // Ask user to enter name
	// char name[20];
	// printf("Enter your name: ");
	// scanf("%s", name);	// scanf stops reading when it encounters a space

	// // Ask user to enter weight
	// char weight[20];
	// printf("Enter your weight in kg: ");
	// scanf("%s", weight);

	// // Ask user to enter height
	// char height [20];
	// printf("Enter your height in m:  ");
	// scanf("%s", height);

	// // Display the values the user entered using puts
	// puts(weight);
	// puts(height);

	// // Calculate their BMI and display it
	// float bmi = atoi(weight) / (atoi(height) * atoi(height));
	// printf("%s, your BMI is %f\n", name, bmi);

	// Receive a character from the user using getchar
	// printf("[INFO] BMI calculation complete. Press any key to continue \n");
	// printf("%c\n", getchar());

	// Display the character using putchar
	char a = getchar();
	putchar(a);
	putchar('\n');

	// printf("Examples of programming languages:\n\t1. Java\n\t2. C\n\t3. C++\n\"What other languages do you know?\"");

	return 0;
}
