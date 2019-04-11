#include <stdio.h>
#include "sound.h"
#include <math.h>
#include "screen.h"

void showID(char *idname,char *id){
	int i;
	printf("%s: ",idname);
	for(i=0;i<4;i++) printf("%c",id[i]);
	puts("");
}
//this function ionly called by displayWAVDATA(), so no need to put
//a declation in sound.h. The function finds how many peaks from 80 pieces of 
//decibel value
int findPeaks(int d[]){
		int c=0;
		for(int i=1;i<80;i++){
			if(d[i] >= 75 && d[i-1] <75) c++;
		}
		if(d[0] >= 75) c++;
		return c;
}

//this funtion gets one second of samples (!&===) , and calculates 
//80 pieces of decibels value, we know we need to calculate one decil
//value from 200 samples, decibevalue is callated by RMS formula
void displayWAVDATA(short s[]){
	double rms[80];
	int dB[80];
	short *ptr=s ;	//we use pointer to pointind to he beginning of the array
	int i,j;		//for nested loop counters, outer loop repeat 80 times
					//inner loop repeat 200 times
	for(i=0;i<80;i++){
		double sum=0;		//accumulate sum of squares
		for(j=0;j<200;j++){
			sum += (*ptr) * (*ptr);
			ptr++;
		}
		rms[i] = sqrt(sum/200);
#ifdef DEBUG
		printf("rms[%d] = %f\n",i , rms[i]);
#endif
		dB[i] = 20*log10(rms[i]);
	}
#ifndef DEBUG	
		barChart(dB);
		int peaks = findPeaks(dB);
		setColors(WHITE, bg(BLACK));
		printf("\033[1;61H");
		printf("Peaks: %d	\n",peaks);
#endif

}

void displayWAVHDR(struct WAVHDR h){
#ifdef DEBUG
	showID("ChunkID",h.ChunkID);
	printf("Chunk size: %d\n",h.ChunkSize);
	showID("format",h.Format);
	showID("Subchunk1ID",h.Subchunk1ID);
	printf("Subchunk1 size: %d\n",h.Subchunk1Size);
	printf("Audio format: %d\n",h.AudioFormat);
	printf("Num. of Channels; &d\n", h.NumChannels);
	printf("Sample rate; %d\n", h.SampleRate);
	printf("Byte rate; %d\n", h.ByteRate);
	printf("Block align: %d\n",h.BlockAlign);
	printf("Bits per sample: %d\n",h.BitsPerSample);
	showID("Subchunk2ID",h.Subchunk2ID);
	printf("Subchunk2ID size : %d\n",h.Subchunk2Size);
	//to be continue for other fields
#else
	setColors(WHITE,bg(RED));
	printf("\033[1;1H");
	printf("test.wav	");
	setColors(YELLOW, bg(BLUE));
	printf("\033[1;21H");
	printf("Sample rate:%dHz	",h.SampleRate);
	setColors(CYAN,bg(MAGENTA));
	printf("\033[1;41H");
	printf("Duration:%.2fsec	",(float)h.Subchunk2Size/h.ByteRate);
	setColors(RED,bg(YELLOW));


#endif
}



