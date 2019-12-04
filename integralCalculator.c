// The following C program that makes use of a loop to numerically compute
// the integral of a polynomial function f(x) = 2*x^(2) - 7*x - 2 with a user defined
// boundary and number of rectangles. 

#include <stdio.h>
#include <math.h>
#include <stdbool.h>

bool validateInput(double left, double right, int n){
	if(right < left || left == right || n <= 0 || left < -10 || right > 10){
		return false;
	} else {
		return true;
	}
}

// Function for the integral calculation
double evalFunc(double x){
	return 2 * pow(x, 2) - 7 * x - 2;
}

int main(int argc, char ** argv){
	int n = 0;
	double left = 0.0, right = 0.0, deltaX = 0.0;
	double aL, aM, aR;
	double xL, xM, xR;
	double sL, sM, sR;

	printf("Enter the Left boundary: a, Right boundary: b, and No. of rectangles to use.\n");
	printf("To exit enter 0 0 0\n");
	scanf("%lf %lf %d", &left, &right, &n);

	if(left == 0 && right == 0 && n == 0){
		printf("Invalid inputs...\n\n");
		printf("Terminate main!\n");

		return 0;
	}

	// Keep asking for user input while input is not valid
	while(validateInput(left, right, n) != 1){
		printf("Invalid inputs...\n\n");
		printf("Enter the Left boundary: a, Right boundary: b, and No. of rectangles to use.\n");
		printf("To exit enter 0 0 0\n");
		scanf("%lf %lf %d", &left, &right, &n);
	}

	// The following for loop calculates midpoint, left and right evaluations of each subinterval. 
	// It also calculates the height of the rectangle. Area = Height * subinterval 
	// The loop also sums up the area between the left and right bounds of the integral. 

	deltaX = (right - left) / n;
	sL = sM = sR = 0.0;

	xL = left;
	xM = xL + deltaX / 2.0;
	xR = xL + deltaX;

	for(int i = 1; i <= n; i++){
		aL = evalFunc(xL) * deltaX;
		aM = evalFunc(xM) * deltaX;
		aR = evalFunc(xR) * deltaX;

		sL += aL;
		sM += aM;
		sR += aR;

		xL += deltaX;
		xM += deltaX;
		xR += deltaX;
	}

	printf("With Step Size: %.4lf\n", deltaX);
	printf("The approximate integral of the f(x) = 2(x^2)-7x-2\n");
	printf("Bound between %.2lf and %.2lf, using %d rectangles is as follows\n\n", left, right, n);

	printf("Mid point evaluation approximate: %.4lf\n", sM);
	printf("Left point evaluation approximate: %.4lf\n", sL);
	printf("Right point evaluation approximate: %.4lf\n", sR);

	return 0;
}
