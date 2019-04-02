#include<stdio.h>
#include<stdlib.h>
#include "screen.h"
#include<time.h>
#include "sound.h"

int main(){
	FILE *f;
	short sd[80000];
	for(;;){
		system(RCMD);
		f =fopen("test.wav","r");
		if(f== NULL){
			printf("Can not open the file\n");
			return 1;
		}

		clearScreen();
		setColors(BLUE, bg(WHITE));
		struct WAVHDR hdr;
		fread(&hdr, sizeof(hdr), 1, f);		//read WAV header
		fread(&sd, sizeof(sd), 1 ,f);		//read WAV data
		fclose(f);
		displayWAVHDR(hdr);
	}
	resetColors();
	getchar();
}

