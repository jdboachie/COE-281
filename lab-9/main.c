#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Shop
{
	char shopName[30];
	/*long long int provides 8 bytes of memory so my phone number can be more than 10 digits.
	 *unsigned means my number cannot be negative.
	*/
	unsigned long long int shopPhoneNumber;
};
struct Clothing
{
	unsigned int code;
	unsigned int year;
	struct Shop shopSelling; // Shop selling clothe(It has a name & phone number).
	struct Price
	{
		char currencyUsed[10];
		float amountSelling;
	}price;
	union Size
	{
		int digit;
		char letter;
		char word[30];
	}size;
	int sizetype;
};

struct Shop shopArray[10];
struct Clothing clotheArray[15];
int shopCount = 0, clothesCount = 0;

void showShops(void);
void showDetails(int arrayIndex);
void showClothes(void);
void showClothesDetails(int arrayIndex);
void addClothing(void);

int main()
{
	// Two variables of type struct Shop.
	struct Shop shop1 = {.shopName ="Excellence Boutique",.shopPhoneNumber = 233204676251};
	struct Shop shop2 = {.shopName ="ST PHILIPS", .shopPhoneNumber = 233504168149};

	// Passing the two variables(shop 1 & shop 2 to the shopArray[]).
	shopArray[0] = shop1;
	shopArray[1] = shop2;
	shopCount = 2;
	// 4 variables of data type, struct Clothing and initializing them.
	struct Clothing clothes_1 = {.sizetype = 3,.size.letter = 'L',.size.word = "BLACK JEANS", .shopSelling.shopPhoneNumber = shop1.shopPhoneNumber, .code = 4356, .year = 2019, .price.currencyUsed = "USD", .price.amountSelling   = 90};
	struct Clothing clothes_2 = {.sizetype = 3,.size.letter = 'M',.size.word = "SWEAT PANTS", .shopSelling.shopPhoneNumber = shop1.shopPhoneNumber, .code = 4366, .year = 2020, .price.currencyUsed = "EUR" , .price.amountSelling = 100};
	struct Clothing clothes_3 = {.sizetype = 3,.size.letter = 'S',.size.word = "LACOSTE TOP", .shopSelling.shopPhoneNumber = shop1.shopPhoneNumber, .code = 4376, .year = 2021, .price.currencyUsed = "BPS",  .price.amountSelling  = 120};
	struct Clothing clothes_4 = {.sizetype = 3,.size.letter = 'L',.size.word = "ARARE SHIRT", .shopSelling.shopPhoneNumber = shop2.shopPhoneNumber, .code = 5028, .year = 2021, .price.currencyUsed = "CFA",   .price.amountSelling = 150};
	strcpy(clothes_1.shopSelling.shopName , shop1.shopName);
	strcpy(clothes_2.shopSelling.shopName , shop1.shopName);
	strcpy(clothes_3.shopSelling.shopName , shop1.shopName);
	strcpy(clothes_4.shopSelling.shopName , shop2.shopName);
	/*
	*I'm assuming the first 3 clothes are sold in shop 1 and the 4th clothe in shop 2.
	*I'm using .size.word to represent name of the clothe.
	*And .size.letter to represnt the size(S,M,L).
	*And .size.digit to represnt
	*.sizetype will determine which size member is initialized.
	*If.sizetype = 1, then I will initialize .size.digit, else if .sizetype = 2, then I will initialize .size.letter, else if .sizetype = 3, then I will initialize .size.word
	*/

	// Passing the four variables(clothes_1,clothes_2, etc to clotheArray[]).
	clotheArray[0] = clothes_1;
	clotheArray[1] = clothes_2;
	clotheArray[2] = clothes_3;
	clotheArray[3] = clothes_4;
	clothesCount = 4;
	int looping = 0;
	do
	{
		printf("CLOTHING MALL\n1.Visit Shop\t2.Add Clothing\t3.Exit\n");
		int option;
		scanf(" %d", &looping);
		switch(looping)
		{
		case 1:
			{
				showShops();
				scanf(" %d", &option);
				showDetails(option - 1);
				showClothes();
				scanf(" %d", &option);
				showClothesDetails(option - 1);
				break;
			}
		case 2:
			{
				addClothing();
				break;
			}
		case 3:
			{
				looping = 0; // looping = 0 will make our condition false and we will break out of the do-while loop.
				printf("Thanks for shopping :)");
				break;
			}
		default:
			{
				printf("Invalid choice\n");
				break;
			}

		}

	}while(looping > 0);


	return 0;
}

void showShops(void)
{
	printf("\n1. Shop 1\n2. Shop 2\n");
	printf("Added shops by user.\n");
	printf("3. User shop 1\n4. User shop 2\n5. User shop 3\n6. User shop 3\n7. User shop 4\n");
}

void showDetails(int arrayIndex)
{
	printf("Shop name is %s\nShop number is %llu\n",shopArray[arrayIndex].shopName, shopArray[arrayIndex].shopPhoneNumber);
}

void showClothes(void)
{
	printf("\nAvailable clothes.\n");
	printf("1. Clothe 1\n2. Clothe 2\n3. Clothe 3\n4. Clothe 4\n5. User's first clothe\n6. User's second clothe\n7. User's third clothe\n8. User's fourth clothe\n9. User's five clothe\n");
}

void showClothesDetails(int arrayIndex)
{
	printf("\nClothe details.\n");
	printf("Clothe is %s\n", clotheArray[arrayIndex].size.word);
	printf("Available size is %c\n", clotheArray[arrayIndex].size.letter);
	printf("Currently available at %s\nShop's phone number is %llu\n",clotheArray[arrayIndex].shopSelling.shopName,clotheArray[arrayIndex].shopSelling.shopPhoneNumber);
	printf("Code for clothe: %u\nYear clothe was made: %u\n",clotheArray[arrayIndex].code,clotheArray[arrayIndex].year);
	printf("Accepted currency: %s\nPrice of item: %.2f\n",clotheArray[arrayIndex].price.currencyUsed,clotheArray[arrayIndex].price.amountSelling);
}

void addClothing(void)
{
	int userClothesCount = 0;
	printf("Add your own clothes.\n");
	printf("How many clothes would you want to add?\n");
	scanf(" %d", &userClothesCount);
	for(int i = 0; i < userClothesCount; ++i)
	{
		struct Shop userShop;
		struct Clothing userAddedClothe;
		fflush(stdin);
		printf("Add your clothe to a new shop or choose an existing shop.\n");
		gets(userShop.shopName);
		/*
		* I will ask the user if he/she wishes to add the clothes to already exisiting shops.
		* Or he/she would want to add clothes to a new shop.
		* If he/she chooses an already existing shop (shop 1 or 2) then the shop details are copied from the shop array.
		* Else we take the name and phone number of the new shop user wants to add the clothes.
		* And we proceed to take the details of the clothes based on the number of clothes the user wants to add.
		*/
	if(strcmp(userShop.shopName,"shop 1")== 0)
	{
		// Copy shop 1 details here. (shopNmae, shopPhoneNumber).
		strcpy(userShop.shopName,shopArray[0].shopName);
		userShop.shopPhoneNumber = shopArray[0].shopPhoneNumber;
		// Index 0 and 1 of shopArray has already been filled with details of shop 1 and shop 2 already so we have to use the indexes after.
		shopArray[i+2] = userShop;
	}
	else if(strcmp(userShop.shopName,"shop 2")== 0)
	{
		strcpy(userShop.shopName,shopArray[1].shopName);
		userShop.shopPhoneNumber = shopArray[1].shopPhoneNumber;
		// Index 0 and 1 of shopArray has already been filled with details of shop 1 and shop 2 already so we have to use the indexes after.
		shopArray[i+2] = userShop;
	}
	else
	{
		printf("Add your shop's phone number\n");
		scanf(" %llu",&userShop.shopPhoneNumber);
		shopArray[i+2] = userShop;
	}
	fflush(stdin);
	printf("Add the name of the clothe.eg: X JEANS\n");
	gets(userAddedClothe.size.word);
	printf("Add the unique code for the clothe.\n");
	scanf(" %u", &userAddedClothe.code);
	printf("Add the year the clothe was made.\n");
	scanf(" %u", &userAddedClothe.year);
	printf("Add the accepted currency.\n");
	scanf(" %s", userAddedClothe.price.currencyUsed);
	printf("Add the cost of the clothe.\n");
	scanf(" %f", &userAddedClothe.price.amountSelling);
	strcpy(userAddedClothe.shopSelling.shopName,userShop.shopName);
	userAddedClothe.shopSelling.shopPhoneNumber = userShop.shopPhoneNumber;
	// Index 0,1,2,3 of clotheArray has already been filled with details of clothes 1,2,3 and 4 already so we have to use the indexes after.
	clotheArray[i+4] = userAddedClothe;
	}
}
