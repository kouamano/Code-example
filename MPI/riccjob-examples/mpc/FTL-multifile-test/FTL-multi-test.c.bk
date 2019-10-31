#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mpi.h>
#include "/home/amano/include/alloc.c"
#define STRSIZE 256
#define STRSIZE_LARGE 1024

int main(int argc, char **argv){
	int my_rank;
	int p;
	int source;
	int dest;
	int tag = 0;
	char *file_name_head;
	char *mpi_target_file_name;
	char *mpi_rank_str;
	int mpi_c;
	FILE *mpi_target_fp;

	file_name_head = c_alloc_vec(STRSIZE_LARGE);

	sscanf(argv[1],"%s",file_name_head);

	printf("\nprog:mpi-test:\n");
	printf("file_head:%s:\n",file_name_head);
	//printf("%s",system("/usr/bin/ls"));

	MPI_Status status;
	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
	MPI_Comm_size(MPI_COMM_WORLD, &p);

	mpi_rank_str = c_calloc_vec(STRSIZE);

	mpi_target_file_name = c_calloc_vec(STRSIZE_LARGE);

	sprintf(mpi_rank_str,"%d",my_rank);
	sprintf(mpi_target_file_name,"%s",file_name_head);
	strcat(mpi_target_file_name,".");
	strcat(mpi_target_file_name,mpi_rank_str);
	printf("rank/proc:%d/%d:\n",my_rank,p);
	printf("targetfile:%s:\n",mpi_target_file_name);
	if((mpi_target_fp = fopen(mpi_target_file_name,"r")) == NULL){
		perror(mpi_target_file_name);
		exit(0);
	}
	printf("-----\n");
	while((mpi_c = fgetc(mpi_target_fp)) != EOF){
		printf("%c",(char)mpi_c);
	}
	fclose(mpi_target_fp);
	printf("\n-----\n");

	MPI_Finalize();

}
