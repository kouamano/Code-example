#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STR_LEN 1024
#define SEEK_BYTE 1024

int main(int argc, char **argv){
	char fname[STR_LEN];
	FILE *fp;

	sscanf(argv[1],"%s",fname);
	fp = fopen(fname,"w");
	fprintf(fp,"%s","start");
	fseek(fp,SEEK_BYTE,SEEK_CUR);
	fprintf(fp,"%s"," end\n");
	fclose(fp);
	return(0);
}
