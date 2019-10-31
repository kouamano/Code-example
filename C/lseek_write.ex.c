#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <cdntl.h>
#include <unistd.h>
#define STR_LEN 1024
#define SEEK_BYTE 1024

int main(int argc, char **argv){
	char fname[STR_LEN];
	FILE *fp;

	sscanf(argv[1],"%s",fname);
	//fp = fopen(fname,"w");
	fp = open(fname,O_APPEND);
	fprintf(fp,"%s","start");
	//fseek(fp,SEEK_BYTE,SEEK_CUR);
	lseek(fp,SEEK_BYTE,SEEK_CUR);
	fprintf(fp,"%s"," end\n");
	close(fp);
	return(0);
}
