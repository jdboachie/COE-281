#include <stdio.h>

/**
 * main - Entry point
 * Return: Always 0 (Success)
*/
int main()
{
	//1. Print a character by typing printf("G");
	printf("G\n");

	//2. Create a char variable
	char char_var;

	//3. Assign to the variable a character, say "G".
	char_var = 'G';

	//4. Create a char variable with an identifier of auto and note what happens.
	// auto a; // cannot use auto as a variable name

	//5. Create a variable with data type integer.
	int i;

	//6. Change the value of the integer.
	i = 5;

	//7. Create two integer variables a and b
	int a;
	int b;

	//8. Assign a number to each variable.
	a = 5;
	b = 10;

	//9. Create a third integer variable, c
	int c;

	//10. Add a and b and assign the result to c
	c = a + b;

	//11. Perform multiplication, division, subtraction, and modulo on a and b and store the results in different variables.
	int w, x, y, z;
	w = a * b;
	x = a / b;
	y = a - b;
	z = a % b;

	//12. Create two new sets of integer variables (d and e) with numbers assigned to each
	int d, e;
	d = 5;
	e = 10;

	//13. Using an assignment and addition operator, assign the sum of d and e to d.
	d += e;

	//14. Repeat step 12 varying the assignment operator (e.g. -=, *=, /=, %=)
	d = 5;
	e = 10;
	
	d -= e;
	d *= e;
	d /= e;
	d %= e;
}
