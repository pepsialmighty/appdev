// this file contain screeb fubction . They are use toisplay 
//sound lel on the putty as the bar chart

#include<stdio.h>
#include "screen.h"

void barChart(int dB[]){
	int i,j;
	for(i=0;i<COL;i++){ 			//for 80 columns
		for(j=0;j<dB[i]/3;j++){
			if(dB[i]>60 && j>20){
				setColors(WHITE, bg(YELLOW));
			}
			else setColors(BLUE,bg(YELLOW));
			printf("\033[%d;%dH",35-j,i+1);
#ifdef UNICODE 			//conditional compilation
			printf("%s",BAR);
#else 
			printf("%c",'*');
#endif
		}
	}
}
void clearScreen(void){
	printf("\033[2J");
	fflush(stdout);		// for remote terminal such as PUTTY 

}


void setColors(short bg, short fg){
	printf("\033[%d;%d;1m",bg,fg);
	fflush(stdout);
}


void resetColors(void){
	printf("\033[0m");
	fflush(stdout);
}
