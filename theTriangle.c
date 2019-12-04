//
// C program that uses the * character to draw a triangle of a given number of rows.
//

#include <stdio.h>

void drawTriangle(rows){
	int rowCounter, colCounter;

	// Loop for the entire triangle being printed
	for(rowCounter = 1; rowCounter <= rows; rowCounter++){
		//Prints * for the triangle, not including the last row
		if(rowCounter < rows){
			for(colCounter = 1; colCounter <= (2 * rows - 1); colCounter++){
				//Prints left side of triangle              Prints right side of triangle
				if(colCounter == (rows - rowCounter + 1) || colCounter == (2 * rows - 1 - (rows - rowCounter))){
					printf("*");
				} else if (colCounter == 2 * rows - 1){
					//Goes to new line of triangle
					printf(" \n");
				} else {
					printf(" ");
				}
			}

		// Prints the last row of *
		} else if(rowCounter == rows){
			for(colCounter = 1; colCounter <= (2 * rows - 1); colCounter++){
				printf("*");
			}
		}
	}
	printf("\n");
}

int main(void){
	int numRows;

	printf("Enter the number of rows in the triangle: ");
	scanf("%d", &numRows);

	drawTriangle(numRows);

	return 0;
}
