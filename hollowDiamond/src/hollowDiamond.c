/*
 ============================================================================
 Name        : diamond.c
 Author      : James Giroux
 Version     : V1
 Copyright   : Copyright James Giroux
 Description : Prints diamond of * based on num of lines from user
 ============================================================================
 */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>



void printDiamond(int num);
void printStars(int row);
void printTopPyramid(int row, int top, int col);
void printBottomPyramid(int row, int bottom, int col);
int yes(void);
void clearBuffer(void);

int outline = 0;

int main(void) {

	int num = 0, again;
	do{
		printf("Enter the number of lines: ");
		scanf(" %d", &num);

		printf("Do you want a hollow pyramid? (y or n) ");
		if(yes()){
			printf("Enter the thickness of border: (%d - %d): ", 1, (num / 2 -1));
			scanf(" %d", &outline);
		}

		printDiamond(num);

		printf("Do you want to go again? (y or n): ");

		if(yes()){
			again = 1;
			outline = 0;
			printf("\n");
		} else {
			again = 0;
		}

	} while (again >= 1);

	return 0;
}

void printStars(int row){
	int i;
	for(i = 1; i <= row * 2 - 1; i++){
		if (outline != 0){
			if (i <= outline){
				printf("* ");
			} else if (i > (row * 2 -1) - outline){
				printf("* ");
			} else {
				printf("  ");
			}
		} else {
			for(i = 1; i <= row * 2 - 1; i++){
				printf("* ");
			}
		}
	}
}

void printDiamond(int num){
	int row = 1;
	int col = 1;
	int top = num / 2;
	int bottom = num /2;

	printf("\n");
	printTopPyramid(row, top, col);
	printBottomPyramid(row, bottom, col);
	printf("\n");

}
void printTopPyramid(int row, int top, int col){
	// top

	for (row = 1; row <= top; row++){

		for (col = 1; col <= top - row; col++){
			printf("  ");
		}

		printStars(row);

		printf("\n");
	}
}

//bottom
void printBottomPyramid(int row, int bottom, int col){
	for (row = bottom; row > 1; row--){

		for (col = 1; col <= bottom - row + 1; col++){
			printf("  ");
		}

		printStars(row - 1);

		printf("\n");
	}
}
void clearBuffer(void){
	while(getchar() != '\n'){
		;
	}
}

int yes(void){
	int res = -1;
	char choice;
	char nl;

	do {// validate that user enters (y or n) or (Y or N)
		clearBuffer();
		scanf(" %c%c", &choice, &nl);
		if (nl == '\n') {
			if (choice == 'n' || choice == 'N'){
				res = 0;
			} else if (choice == 'y' || choice == 'Y'){
				res = 1;
			}
		}
		if (res == -1) {
			printf("*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: ");//Invalid characters
			clearBuffer();
		}
	} while (res < 0);


	return res; // 1 true for y and Y, 0 false for n or N
}
