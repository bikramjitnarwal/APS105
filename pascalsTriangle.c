#include <stdio.h>

//Computes the factorial of a number by using a for loop
int factorial(int n){
	int fact = 1;
	
	//Factorial of 0 is 1
	if(n == 0){
		return 1;
	} else {
		for(int i = 1; i <= n; i++){
			fact = fact * i;
		}
		return fact;
	}
}

//Computes the n choose r 
int choose(int n, int r){
    int answer;
    
	//The calculation is assigned to an answer variable
    answer = (factorial(n))/((factorial(r))*(factorial(n-r)));
    return answer;
}

void triangle(int numOfRows) {
    for(int n = 0; n < numOfRows; n++) {
        for(int i = 1; i < numOfRows-n; i++) {
            printf("   ");
        }
        for(int r = 0; r <= n; r++) {
           printf(r == 0 ? "%d " : "%5d ", choose(n, r));
        }
        printf("\n");
    }
}

int main(int argc, char **argv){
	int rows;
	printf("Enter the number of rows: ");
	scanf("%d", &rows);
	
	//Loops while user enters number between 0 (not inclusive) and 13 (inclusive)
	while(rows > 0 && rows <=13){
		
		//Goes into triangle function where it will print out the triangle
		triangle(rows);
		
		//Next prompt 
		printf("Enter the number of rows: ");
		scanf("%d", &rows);
	}
	return 0;
}
