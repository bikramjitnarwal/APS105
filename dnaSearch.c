//
// C program that searches through the an array that contains a sequence of numbers in an array 
// (these numbers are restricted to be 1, 2, 3 or 4, which I will use instead of the letters A,G,T and C)
//

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void readString(int length, int string[])
{
	int num;
	printf("Enter %d characters (one of 12345) as a search string: ", length);
	// Gets the numbers into the string array
	for(int i=0; i<length; i++){
		scanf(" %1d", &num);
		string[i]=num;
	}
}

// Function checks for valid input 
bool checkValid(int length, int string[])
{
	for(int i=0;i<length;i++){
		//Checks for valid numbers
		if((string[i]!=1)&&(string[i]!=2)&&(string[i]!=3)&&(string[i]!=4)&&(string[i]!=5)){
			printf("Erroneous character input '%d' exiting\n", string[i]);
			printf("Goodbye\n");
			return true;
		}
	}
	// Only comes here if string[i] is a valid number
	return false;
}

// Searches and prints the matches 
void search(int length, int string[])
{
	int DNA[] = {1, 2, 4, 2, 2, 2, 1, 4, 4, 2, 3, 4, 4, 4, 2, 1, 4,
	1, 3, 3, 2, 1, 3, 2, 1, 1, 2, 2, 2, 3, 4, 1, 3, 1, 2, 1, 4,
	4, 4, 1, 1, 3, 1, 4, 2, 4, 4, 1, 4, 4, 1, 4, 4, 4, 4, 1, 1,
	2, 3, 3, 3, 3, 4, 4, 3, 2, 3, 2, 3, 4, 3, 3, 4, 4, 1, 3, 3,
	2, 1, 2, 3, 1, 2, 1, 3, 3, 2, 1, 4, 1, 4, 3, 4, 4, 4, 1, 2,
	1, 3, 2, 0};

	for(int i=0;i<=100-length;i++){
		bool match = true;
		for(int j=0;j<length;j++){
			// Compares & checks match  // Accounts for wildcard #5
			if((string[j]!= DNA[i+j]) && (string[j]!= 5))
				match = false;
		}
		// If there is a match (match = true), then print it 
		if(match){
			printf("Match of search string found at element %d\n", i);
		}
	}
}

int main()
{
	int length, *searchString;

	printf("Enter length of DNA string to match: ");
	scanf("%d", &length);

	while(length >= 1 && length <= 5){
		searchString = (int *)malloc(length*sizeof(int));

		readString(length,searchString);
		
		// If the functions returns true (when it is not valid) then go into the if statement and return 0;
		if(checkValid(length,searchString)){
			return 0;
		}

		search(length,searchString);

		free(searchString);

		printf("Enter length of DNA string to match: ");
		scanf("%d", &length);
	}
	printf("Goodbye\n");
	return 0;
}