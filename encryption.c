//
// The program asks the user to enter an encrypted 3-digit code and then prints the real 3-digit code.
//

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(void){
	int code, firstDigit, lastDigit, middleDigit, newMiddleDigit, exponent;

	//Prompts user to enter code
	printf("Enter an encrypted 3-digit code: ");
	scanf("%d", &code);

	//Determines the exponent for which the number should be divided by
	if(code < 100){
		exponent = 1;
	} else {
		exponent = 2;
	}

	//Checks if there the first number is 0
	if(code < 100){
		firstDigit = 0;
	} else {
		firstDigit = code / pow(10, exponent);
	}

	//Gets the last number 
	lastDigit = code % 10;

	//Gets the middle number 
	middleDigit = (code / 10) % 10;
	newMiddleDigit = abs(middleDigit - 9);

	//Prints the code
	printf("The real 3-digit code is: %d%d%d\n", lastDigit, newMiddleDigit, firstDigit);
	return 0;
}
