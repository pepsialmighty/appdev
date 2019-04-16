#include<stdio.h>
#include<stdlib.h>
#include "screen.h"
#include "sound.h"
#include <signal.h>
#include"comm.h"
int main(int argc, char **argv){
	if(argc>1){			//if the user given some command line argument
		printf("Test tone generation\n");
		int fR, fL, ch;
		float duration;
		printf("No. of channels (1 or 2): ");
		scanf("%d", &ch);
		if(ch == 1){
			printf("Mono Frequency: ");
			scanf("%d ", &fL);
		}
		else if (ch == 2){
			printf("Give me Left and Right fq: ");
			scanf("%d %d", &fL, &fR);
		}
		else{
			printf("Wrong number of channels\n");
			return 1;
		}
		printf("Duration of sound: ");
		scanf("%f", &duration);
		testTone(ch, fL, fR, duration);
		return 0;
	}
	FILE *f;
	short sd[RATE];
	for(;;){
		int ret = system(RCMD);
		if(ret == SIGINT) break;
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
		displayWAVDATA(sd);
		sendDATA(sd);
	}
	resetColors();
}

