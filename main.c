#include<stdio.h>
#include<stdlib.h>
#include "screen.h"
#include<time.h>
int main(){
	int dec[COL],i;		//80-PIECES OF SOUND DECIBELS
	srand(time(NULL));
	for(i=0; i<COL; i++) dec[i] = rand()%70+30;
	clearScreen();
	setColors(BLUE, bg(WHITE));
	barChart(dec);
	resetColors();
	getchar();
}
