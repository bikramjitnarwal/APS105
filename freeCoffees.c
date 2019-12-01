//
// Calculating how many free coffees one can get with an amount of coupons. 
//

#include <stdio.h>
#include <math.h>

int main(int argc, char ** argv) 
{
	double costOfCoffee;
	double couponsInput;
	int couponsRequired;
	double spendingMoney;

	printf("How much does a coffee cost?\n");
	scanf("%lf", &costOfCoffee);

	if(costOfCoffee < 0.01){
		printf("Invalid Input.\n");
		return 0;
	}

	printf("How many coupons does it take to get a free coffee?\n");
	scanf("%lf", &couponsInput);

	// Coupon cannot be a decimal
	if((floor(couponsInput) < couponsInput && couponsInput < ceil(couponsInput)) || (int) couponsInput <= 0){
		printf("Invalid Input.\n");
		return 0;
	}

	couponsRequired = couponsInput;

	printf("How much money do you have to spend on coffee this month?\n");
	scanf("%lf", &spendingMoney);

	if(spendingMoney < 0){
		printf("Invalid Input.\n");
		return 0;
	}

	int purchasableCoffees = spendingMoney / costOfCoffee;
	double moneyRemained = spendingMoney - purchasableCoffees * costOfCoffee;

	printf("This month, you can purchase %d coffees at $%.2lf each.\n", purchasableCoffees, costOfCoffee);

	int numCoffee = purchasableCoffees;
	int currentNumCoffees = 0;
	int couponLeftover = numCoffee;
	int newCoffees = 0;

	// To check if left over coupons is able to get a new coffee.
	while(couponLeftover >= couponsRequired){
		currentNumCoffees = couponLeftover / couponsRequired;
		numCoffee += currentNumCoffees;
		newCoffees += currentNumCoffees;
		couponLeftover = couponLeftover % couponsRequired + currentNumCoffees;
	}

	if(newCoffees == 0){
		printf("You will not be able to redeem any additional coffees from coupons this month.\n");
	} else {
		printf("You will be able to redeem an additional %d coffee(s) from coupons.\n", newCoffees);
	}

	printf("At the end of the month, you will have $%.2lf and %d coupon(s) remaining.\n", moneyRemained, couponLeftover);

	if(numCoffee == 0){
		printf("On average, you spent $0.00 on each cup of coffee this month.\n");
	} else {
		double averagePrice = (purchasableCoffees * costOfCoffee) / numCoffee;
		printf("On average, you spent $%.2lf on each cup of coffee this month.\n", averagePrice);
	}
	return 0;
}
