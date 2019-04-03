#include <stdio.h>
#include "sound.h"
#include <math.h>

void showID(char *idname,char *id){
	int i;
	printf("%s: ",idname);
	for(i=0;i<4;i++) printf("%c",id[i]);
	puts("");
}
//this funtion gets one second of samples (!&===) , and calculates 
//80 pieces of decibels value, we know we need to calculate one decil
//value from 200 samples, decibevalue is callated by RMS formula
void displayWAVDATA(short s[]){
	double rms[80];
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
		printf("rms[%d] = %f\n",i , rms[i]);
	}
}
void displayWAVHDR(struct WAVHDR h){
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

}
