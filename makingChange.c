// This C program will makes change for amounts less than one dollar. 
// It determine the number and amount of coins that can make up a specific number of cents.
//

#include <stdio.h>

void grammer(int quarter, int dime, int nickle, int penny) 
{
  // We have to make sure it does not equal 0 because if user enters in 5, it prints 0 quarter, 0 dime and etc 
	if(quarter != 0){
		if(quarter > 1){
			printf("%d quarters", quarter);
		} else {
			printf("%d quarter", quarter);
		}
		if(dime == 0 && nickle == 0 && penny == 0){
			printf(".");
		} else {
			printf(", ");
		}
	}

	if(dime != 0){
		if(dime > 1){
			printf("%d dimes", dime);
		} else {
			printf("%d dime", dime);
		}
		if(nickle == 0 && penny == 0){
			printf(".");
		} else {
			printf(", ");
		}
	}

	if(nickle != 0){
		if(nickle > 1){
			printf("%d nickles", nickle);
		} else {
			printf("%d nickle", nickle);
		}
		if(penny == 0){
			printf(".");
		} else {
			printf(", ");
		}
	}

	if(penny != 0){
		if(penny > 1){
			printf("%d cents.", penny);
		} else {
		printf("%d cent.", penny);
		}
	}
}

int main(int argc, char ** argv)
{
	int totalCents;

	printf("Please give an amount in cents less than 100: ");
	scanf("%d", &totalCents);

	// Repeating while loop when user is entering correct number
	while(totalCents > 0 && totalCents < 100){
		int quarters, dimes, nickles, cents;

		printf("%d cents: ", totalCents);

		quarters = totalCents / 25;
		dimes = (totalCents - (quarters * 25)) / 10;
		nickles = (totalCents - (quarters * 25) - (dimes * 10)) / 5;
		cents = (totalCents - (quarters * 25) - (dimes * 10) - (nickles * 5));

		// Goes to function
		grammer(quarters, dimes, nickles, cents);

		// Next prompt 
		printf("\nPlease give an amount in cents less than 100: ");
		scanf("%d", &totalCents);
	}

	printf("Goodbye.\n");

	return 0;
}