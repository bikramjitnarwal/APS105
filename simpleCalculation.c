//
// Basic C program to calculate different fees 
//

#include <stdio.h>
#include <math.h>

int main(int argc, char ** argv){
	//Variables are declared that will be included in some calculations. 
	double priceOfItem, yearlyInterest, numberOfMonths;

	//User is asked for purchase price, where the printf displays the command to the user and scanf gets the command from the keyboard.
	printf("Enter the purchase price of the item: ");
	scanf("%lf", &priceOfItem);

	//User is asked for interest rate per year, where the printf displays the command to the user and scanf gets the command from the keyboard.
	printf("Enter the interest rate per year as a percentage: ");
	scanf("%lf", &yearlyInterest);

	//A monthly percentage constant is made since in the equation we need interest rate per month (divide by 100 for % and 12 for number of months). 
	const double monthlyPercentage = 100 * 12;

	//Monthly interest rate equation. 
	double monthlyInterestRate = yearlyInterest / monthlyPercentage;

	//User is asked for number of months for repayment, where the printf displays the command to the user and scanf gets the command from the keyboard.
	printf("Enter the number of months for repayment: ");
	scanf("%lf", &numberOfMonths);

	//The following equation gets the value for monthly payment by using an equation. 
	double monthlyPayment = (priceOfItem * monthlyInterestRate) / (1 - pow(1 + monthlyInterestRate, -numberOfMonths));

	//Total cost is based on the number of months multiplied by the monthly payment. 
	double totalCost = numberOfMonths * monthlyPayment;

	//The final expression is displayed to the user with 2 decimal places.
	printf("The monthly payment is: %.2lf\n""The total cost of the purchase is: %.2lf\n", monthlyPayment, totalCost);

	return 0;
}
