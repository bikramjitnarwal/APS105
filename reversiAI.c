//
// C program where a human can play against the computer, with the computer making 
// intelligent decisions about where to place its tiles in the Reversi game
//

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void printBoard(char board[][26], int n){
	
	printf("  ");
	for(char c = 0; c < n; c++){
		printf("%c", 'a'+c);
	}
	printf("\n");

	for(int i = 0; i<n ;i++){
		printf("%c ", 'a'+(char)i);
		for (int j = 0; j<n ;j++)
			printf("%c",board[i][j]);
		printf("\n");
	}
}

bool positionInBounds(int n, int row, int col){
	if(row < n && col < n && row >= 0 && col >= 0){
		return true;
	} 
	else { 
		return false;
	}
}

// Sets up the positioning
void enterConfiguration(char board[][26], char player, char row, char col, int n){
	if (positionInBounds(n, (int)row - 'a', (int)col - 'a')){
		board[(int)row - 'a'][(int)col - 'a'] = player;
	}
	
}

void readConfiguration(char board[][26], int n){

	char player = 'W';
	char row = 'b';
	char col = 'c';
	
	scanf("\n%c%c%c", &player, &row, &col);
	while(player != '!'){ //|| row != '!' || col != '!'){
		enterConfiguration(board, player, row, col, n);
		scanf("\n%c%c%c", &player, &row, &col);
	}
}


// checks whether (row, col) is a legal position for a tile of colour by “looking” in the
// direction specified by deltaRow and deltaCol. 
bool checkLegalInDirection(char board[][26], int n, int row, int col, char colour, int deltaRow, int deltaCol){
	int i = row  + deltaRow;
	int j = col + deltaCol;
	while(positionInBounds(n, i, j)){
		if(board[i][j] == colour)
			return true;
		else if(board[i][j] =='U')
			return false;
		i = deltaRow + i;
		j = deltaCol + j;
	}
	return false;
}

void availableMoves(char board[][26], int n, char colour){
	printf("Available moves for %c:\n", colour);
	
	for(int i= 0; i<n; i++){
		for(int j = 0; j <n; j++){
			if(board[i][j] == 'U'){
				for(int x = i-1; x < i + 2; x++){
					for(int y= j-1; y < j + 2; y++){
						if(x != i || y!=j){
							if(positionInBounds(n, x, y)){
								if(board[x][y] != 'U' && board[x][y] != colour){
									if (checkLegalInDirection(board, n, x, y, colour, x - i, y - j)){
										
										printf("%c%c\n", (char)i + 'a', (char)j + 'a');
									}
								}
							}
						}
					}
				}
			}
		}
	}
}

bool availableMoves2(char board[][26], int n, char colour){
	for(int i= 0; i<n; i++){
		for(int j = 0; j <n; j++){
			if(board[i][j] == 'U'){
				for(int x = i-1; x < i + 2; x++){
					for(int y= j-1; y < j + 2; y++){
						if(x != i || y!=j){
							if(positionInBounds(n, x, y)){
								if(board[x][y] != 'U' && board[x][y] != colour){
									if (checkLegalInDirection(board, n, x, y, colour, x - i, y - j)){
										return true;
									}
								}
							}
						}
					}
				}
			}
		}
	}
	return false;
}

bool movesLeft(char board[][26], int n){
	if(availableMoves2(board, n, 'B')){
		return true;
	} else if (availableMoves2(board, n, 'W')){
		return true;
	}
	else 
		return false;		
}

void initializeBoard(char board[][26], int n){
	for(int i = 0; i < n; i ++){
		for(int j = 0; j < n; j++)
			board[i][j] = 'U';
	}
	board[n/2][n/2] = 'W';
	board[n/2 - 1][n/2 - 1] = 'W';
	board[n/2 - 1][n/2] = 'B';
	board[n/2][n/2 - 1] = 'B';
}

bool move(char board[][26], int n, char colour){
	int flipX, flipY;
	bool flag = true;
	int row, col;
	
	char crd1, crd2;
	printf("Enter move for colour %c (RowCol): ", colour);
	scanf("\n%c%c", &crd1, &crd2);
	
	row = (int)(crd1 -'a');
	col = (int)(crd2 -'a');
	
	if(positionInBounds(n, row, col)){
		if(board[row][col] == 'U'){
			for(int x = row-1; x < row + 2; x++){
				for(int y= col-1; y < col + 2; y++){
					if(x != row || y!=col){
						if(positionInBounds(n, x, y)){
							if(board[x][y] != 'U' && board[x][y] != colour){
								if (checkLegalInDirection(board, n, x, y, colour, x - row, y - col)){
									// If we come here it means we got a valid move
									flag = false;
									flipX = row;
									flipY = col;
									while(board[flipX][flipY] != colour){
										board[flipX][flipY] = colour; 
										flipX +=x - row;
										flipY +=y - col;
									}
								}
							}
						}
					}
				}
			}
		}
	}
	if(flag){
		printf("Invalid move.\n");
		return false;
	}
	return true;
}

//tell u how many moves the player has
int moveScore(char board[][26],int n, char colour, int row, int col){
	//use new bool move function to count number of flips and add it to max score variable 
	int score = 0;
	if(board[row][col] == 'U'){
		for(int x = row-1; x < row + 2; x++){
			for(int y= col-1; y < col + 2; y++){
				if(x != row || y!=col){
					if(positionInBounds(n, x, y)){
						if(board[x][y] != 'U' && board[x][y] != colour){
							if (checkLegalInDirection(board, n, x, y, colour, x - row, y - col)){
								// If we come here it means we got a valid move
								int flipX = row;
								int flipY = col;
								while(board[flipX][flipY] != colour){
									score = score + 1;
									flipX +=x - row;
									flipY +=y - col;
								}
							}
						}
					}
				}
			}
		}
	}
	return score;
}

void computerMove(char board[][26], int n, char colour){
	int maxScore = 0;
	int maxRow = 0;
	int maxCol = 0;
	int temp;
	
	for(int i =0; i< n; i++){
		for(int j =0; j< n; j++){
			temp = moveScore(board, n, colour, i, j);
			if (temp > maxScore){
				maxScore = temp;
				maxRow = i;
				maxCol = j;
			}
		}
	}
	printf("Computer places %c at %c%c.\n", colour, maxRow + 'a', maxCol + 'a');
	for(int x = maxRow-1; x < maxRow + 2; x++){
		for(int y= maxCol-1; y < maxCol + 2; y++){
			if(x != maxRow || y!=maxCol){
				if(positionInBounds(n, x, y)){
					if(board[x][y] != 'U' && board[x][y] != colour){
						board[maxRow][maxCol]=colour;
						if (checkLegalInDirection(board, n, x, y, colour, x - maxRow, y - maxCol)){
							// If we come here it means we got a valid move
							int flipX = x;
							int flipY = y;
							while(board[flipX][flipY] != colour){
								board[flipX][flipY] = colour; 
								flipX +=x - maxRow;
								flipY +=y - maxCol;
							}
						}
					}
				}
			}
		}
	}
}

void checkWinner(char board[][26], int n){
	int WCounter = 0;
	int BCounter = 0;
	
	for(int i=0; i < n; i++){
		for(int j=0; j< n; j++){
			if(board[i][j] == 'W'){
				WCounter += 1;
			}
			if(board[i][j] == 'B'){
				BCounter += 1;
			}
		}
	}
	if(WCounter > BCounter){
		printf("W player wins.\n");
	
	} else if(BCounter > WCounter){
		printf("B player wins.\n");
	}
	else {
		printf("Draw!\n");
	}
}

void playGame(char board[][26], int n, char computerCol){
	char curPlayer = 'B';

	while(movesLeft(board, n)){
		if(availableMoves2(board, n , curPlayer)){
			if (curPlayer == computerCol){
			//computer plays
			computerMove(board, n, computerCol);
			}
			else {
				if(!move(board, n, curPlayer)){
					printf("%c player wins.\n", computerCol);
					return;
				}
			}
		}
		else {
			printf("%c player has no valid move.\n", curPlayer);
		}
			printBoard(board, n);
		//swithes turns 
		curPlayer = 'B' + 'W' - curPlayer;
	}
		
	checkWinner(board, n);
}


int main(int argc, char **argv)
{
	int n = 0;
	char computerCol;
	char board[26][26];
	printf("Enter the board dimension: ");
	scanf("%d", &n);
	
	printf("Computer plays (B/W): ");
	scanf("\n%c", &computerCol);
	
	
	initializeBoard(board, n);
	printBoard(board, n);
	
	playGame(board, n, computerCol);
	return 0;
}