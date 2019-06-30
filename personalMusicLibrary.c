// 
// This is a program written to maintain a personal music library,
// using a linked list to hold the songs in the library.
//

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

typedef struct node {
	char * artist;
	char * songName;
	char * genre;
	struct node * next;
} Node;

typedef struct linkedList {
	Node * head;
} LinkedList;

void insertSong(LinkedList * playList, char * songName, char * artistName, char * genre);
void printPlaylist(LinkedList * playList);
void searchLinkedList(LinkedList * playList, char * songName);
void deleteSong(LinkedList * playList, char * songName);
void quit(LinkedList * playList);

void inputStringFromUser(char * prompt, char * s, int arraySize);
void songNameDuplicate(char * songName);
void songNameFound(char * songName);
void songNameNotFound(char * songName);
void songNameDeleted(char * songName);
void artistFound(char * artist);
void artistNotFound(char * artist);
void printMusicLibraryEmpty(void);
void printMusicLibraryTitle(void);

const int MAX_LENGTH = 1024;

int main(void) {
	LinkedList playList;
	playList.head = NULL;

	printf("Personal Music Library.\n\n");
	printf("%s", "Commands are I (insert), D (delete), S (search by song name),\n"
	"P (print), Q (quit).\n");

	char response;
	char input[MAX_LENGTH + 1];
	do {
		inputStringFromUser("\nCommand", input, MAX_LENGTH);

		// Response is the first character entered by user.
		// Convert to uppercase to simplify later comparisons.
		response = toupper(input[0]);

		if (response == 'I') {
			char songName[MAX_LENGTH + 1], artistName[MAX_LENGTH + 1], genreName[MAX_LENGTH + 1];

			char * promptName = "Song name";
			char * promptArtist = "Artist";
			char * promptGenre = "Genre";

			inputStringFromUser(promptName, songName, MAX_LENGTH);
			inputStringFromUser(promptArtist, artistName, MAX_LENGTH);
			inputStringFromUser(promptGenre, genreName, MAX_LENGTH);

			insertSong(&playList, songName, artistName, genreName);
		} else if (response == 'D') {
			// Delete a song from the list.

			char * prompt = "\nEnter the name of the song to be deleted";
			inputStringFromUser(prompt, input, MAX_LENGTH);
			deleteSong(&playList, input);
			
		} else if (response == 'S') {

			char * prompt = "\nEnter the name of the song to search for";
			inputStringFromUser(prompt, input, MAX_LENGTH);

			searchLinkedList(&playList, input);

		} else if (response == 'P') {
			// Print the music library.
			printPlaylist(&playList);

		} else if (response == 'Q') {
			; // do nothing
			quit(&playList);
		} else {
			// do this if no command matched ...
			printf("\nInvalid command.\n");
		}
	} while (response != 'Q');
	
	return 0;
}

// Prompt the user for a string safely, without buffer overflow
void inputStringFromUser(char * prompt, char * s, int maxStrLength) {
	int i = 0;
	char c;

	printf("%s --> ", prompt);
	while (i < maxStrLength && (c = getchar()) != '\n')
		s[i++] = c;
	s[i] = '\0';
}

// Function to call when the user is trying to insert a song name
// that is already in the personal music library.
void songNameDuplicate(char * songName) {
	printf("\nA song with the name '%s' is already in the music library.\n" 
	"No new song entered.\n", songName);
}

// Function to call when a song name was found in the personal music library.
void songNameFound(char * songName) {
	printf("\nThe song name '%s' was found in the music library.\n", songName);
}

// Function to call when a song name was not found in the personal music library.
void songNameNotFound(char * songName) {
	printf("\nThe song name '%s' was not found in the music library.\n", songName);
}

// Function to call when a song name that is to be deleted
// was found in the personal music library.
void songNameDeleted(char * songName) {
	printf("\nDeleting a song with name '%s' from the music library.\n", songName);
}

// Function to call when printing an empty music library.
void printMusicLibraryEmpty(void) {
	printf("\nThe music library is empty.\n");
}

// Function to call to print a title when the entire music library is printed.
void printMusicLibraryTitle(void) {
	printf("\nMy Personal Music Library: \n");
}

// Prints out each node of music playlist
void printPlaylist(LinkedList * playList) {
	if (playList->head == NULL) {
		printf("The music library is empty.\n\n");
		return;
	}
	printf("My Personal Music Library:\n\n");
	Node * currNode = playList->head;
	while (currNode != NULL) {
		printf("%s\n%s\n%s\n\n", currNode->songName, currNode->artist, currNode->genre);
		currNode = currNode->next;
	}
}

// Inserts a new song 
void insertSong(LinkedList * playList, char * songName, char * artistName, char * genre) {
	Node * temp = (Node *) malloc(sizeof(Node));

	// Allocating space for temp variable 
	temp->songName = (char *)malloc((MAX_LENGTH + 1) * sizeof(char));
	temp->artist = (char *)malloc((MAX_LENGTH + 1) * sizeof(char));
	temp->genre = (char *)malloc((MAX_LENGTH + 1) * sizeof(char));

	// Copying info
	strcpy(temp->songName, songName);
	strcpy(temp->artist, artistName);
	strcpy(temp->genre, genre);

	if (playList->head == NULL) {
		temp->next = NULL;
		playList->head = temp;
	} else if (strcmp(playList->head->songName, songName) > 0) {
		temp->next = playList->head;
		playList->head = temp;
	} else if (strcmp(playList->head->songName, songName) == 0) {
		songNameDuplicate(songName);
	} else {
		Node * currNode = playList->head;
		while (currNode->next != NULL && strcmp(currNode->next->songName, songName) < 0) {
			currNode = currNode->next;
		}
		if (currNode->next == NULL) {
			temp->next = NULL;
			currNode->next = temp;
		} else if (strcmp(currNode->next->songName, songName) == 0) {
			songNameDuplicate(songName);
		} else {
			temp->next = currNode->next;
			currNode->next = temp;
		}
	}
}

// Searchs for a match or no match from the playlist
void searchLinkedList(LinkedList * playList, char * songName) {
	Node * currNode = playList->head;

	while (currNode != NULL) {
		if (strcmp(currNode->songName, songName) == 0)
			songNameFound(songName);
		return;
	}
	songNameNotFound(songName);
}

// Deletes the desired song from the playlist
void deleteSong(LinkedList * playList, char * songName) {
	bool flag = false;
	Node * curr = playList->head;
	if (playList->head == NULL) {
		printMusicLibraryEmpty();
		return;
	}
	if (strcmp(playList->head->songName, songName) == 0) {
		Node * temp = playList->head;
		playList->head = playList->head->next;
		free(temp->songName);
		free(temp->artist);
		free(temp->genre);
		free(temp);
		flag = true;
	}
	while (curr->next != NULL) {
		if (strcmp(curr->next->songName, songName) == 0) {
			Node * temp = curr->next;
			curr->next = temp->next;
			songNameDeleted(temp->songName);
			free(temp->songName);
			free(temp->artist);
			free(temp->genre);
			free(temp);
			flag = true;
		} else {
			curr = curr->next;
		}
	}
	if (flag == false) {
		songNameNotFound(songName);
	}
}

// Quits the program and frees all memory 
void quit(LinkedList * playList) {
	Node * ptr = playList->head;
	while (ptr != NULL) {
		playList->head = playList->head->next;
		songNameDeleted(ptr->songName);

		free(ptr->songName);
		free(ptr->artist);
		free(ptr->genre);
		free(ptr);

		ptr = playList->head;
	}
	printMusicLibraryEmpty();
}