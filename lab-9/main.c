#include <stdio.h>

struct Shop
{
	char shopName[20];
	unsigned long long int shopNumber;
};

struct Price
{
	char currency[3];
	float amount;
};

union Size
{
	int digit;
	char letter;
	char word[10];
};

struct Clothing
{
	char code[10];
	int year;
	int sizetype;
	struct Shop shop;
	struct Price price;
	union Size size;
};

// Global variables
struct Shop shopArray[10];
struct Clothing clothingArray[15];
int shopCount = 0;
int clothingCount = 0;


void showShops()
{
	printf("Shops\n");
	for(int i=0; i<shopCount; i++)
	{
		printf("%d. %s\n", i+1, shopArray[i].shopName);
	}
}

void showDetails(int shopIndex)
{
	printf("Shop Details\n");
	printf("Name: %s\n", shopArray[shopIndex].shopName);
	printf("Number: %llu\n", shopArray[shopIndex].shopNumber);
}

void showClothes(int shopIndex)
{
	printf("Clothes\n");
	for(int i=0; i<clothingCount; i++)
	{
		if(clothingArray[i].shop.shopNumber == shopArray[shopIndex].shopNumber)
		{
			printf("%d. %s\n", i+1, clothingArray[i].code);
		}
	}
}

void addClothing()
{
	printf("Add Clothing\n");
	printf("Code: ");
	scanf(" %s", clothingArray[clothingCount].code);
	printf("Year: ");
	scanf(" %d", &clothingArray[clothingCount].year);
	printf("Size Type: ");
	scanf(" %d", &clothingArray[clothingCount].sizetype);
	printf("Shop Name: ");
	scanf(" %s", clothingArray[clothingCount].shop.shopName);
	printf("Shop Number: ");
	scanf(" %llu", &clothingArray[clothingCount].shop.shopNumber);
	printf("Price Currency: ");
	scanf(" %s", clothingArray[clothingCount].price.currency);
	printf("Price Amount: ");
	scanf(" %f", &clothingArray[clothingCount].price.amount);

	if(clothingArray[clothingCount].sizetype == 1)
	{
		printf("Size Digit: ");
		scanf(" %d", &clothingArray[clothingCount].size.digit);
	}
	else if(clothingArray[clothingCount].sizetype == 2)
	{
		printf("Size Letter: ");
		scanf(" %c", &clothingArray[clothingCount].size.letter);
	}
	else if(clothingArray[clothingCount].sizetype == 3)
	{
		printf("Size Word: ");
		scanf(" %s", clothingArray[clothingCount].size.word);
	}
	clothingCount++;
}

int main()
{
	struct Shop shop1 = {"Shop1", 1234567890};
	struct Shop shop2 = {"Shop2", 1234567891};

	shopArray[0] = shop1;
	shopArray[1] = shop2;
	shopCount = 2;

	struct Clothing clothing1 = {"CLOTH1", 2019, 1, shop1, {"USD", 10.0}, {10}};
	struct Clothing clothing2 = {"CLOTH2", 2019, 2, shop2, {"USD", 20.0}, {'A'}};
	struct Clothing clothing3 = {"CLOTH3", 2019, 3, shop1, {"USD", 30.0}, {"WORD"}};
	struct Clothing clothing4 = {"CLOTH4", 2019, 1, shop2, {"USD", 40.0}, {40}};

	clothingArray[0] = clothing1;
	clothingArray[1] = clothing2;
	clothingArray[2] = clothing3;
	clothingArray[3] = clothing4;
	clothingCount = 4;
	return 0;

	int looping=0;
	do{
		printf("CLOTHING MALL\n1.Visit Shop\t2.Add Clothing\t3.Exit\n");
		int option;
		scanf(" %d", &looping);
		switch(looping){
			case 1:
				showShops();
				scanf(" %d", &option);
				showDetails(option-1);
				showClothes(option-1);
				break;
			case 2:
				addClothing();
				break;
			case 3:
				looping = 0;
				printf("Thanks for shopping :)");
				break;
			default:
				printf("Invalid choice\n");
				break;
		}
	}while(looping>0);
}
