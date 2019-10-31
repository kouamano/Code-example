#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mpi.h>
#include "/home/amano/include/alloc.c"
#include "/home/amano/include/data_read.c"
#define STRSIZE 256
#define STRSIZE_LARGE 1024

int main(int argc, char **argv){
	int i;
	int mpi_rank;
	int mpi_size;
	char *file_name_head;
	char *mpi_target_file_name;
	char *mpi_rank_str;
	int mpi_c;
	int mpi_sample_dim = 0;
	int mpi_sample_num = 0;
	int *mpi_sample_num_list;
	int *mpi_reccount_list;
	int *mpi_displs;
	FILE *mpi_target_fp;

	file_name_head = c_alloc_vec(STRSIZE_LARGE);

	sscanf(argv[1],"%s",file_name_head);

	//printf("\nprog:mpi-test:\n");
	//printf("file_head:%s:\n",file_name_head);

	MPI_Status status;
	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &mpi_rank);
	MPI_Comm_size(MPI_COMM_WORLD, &mpi_size);

	mpi_rank_str = c_calloc_vec(STRSIZE);

	mpi_target_file_name = c_calloc_vec(STRSIZE_LARGE);

	mpi_sample_num_list = i_alloc_vec(mpi_size);

	mpi_reccount_list = i_alloc_vec(mpi_size);

	mpi_displs = i_alloc_vec(mpi_size);

	sprintf(mpi_rank_str,"%d",mpi_rank);
	sprintf(mpi_target_file_name,"%s",file_name_head);
	strcat(mpi_target_file_name,".");
	strcat(mpi_target_file_name,mpi_rank_str);
	if((mpi_target_fp = fopen(mpi_target_file_name,"r")) == NULL){
		perror(mpi_target_file_name);
		exit(0);
	}
	printf("-----\n");
	/*
	while((mpi_c = fgetc(mpi_target_fp)) != EOF){
		printf("%c",(char)mpi_c);
	}
	*/
	read_ilist_from_stream(1,mpi_target_fp,&mpi_sample_dim);
	read_ilist_from_stream(1,mpi_target_fp,&mpi_sample_num);
	fclose(mpi_target_fp);

	for(i=0;i<mpi_size;i++){
		mpi_reccount_list[i] = 1;
		//reciev from size:1 each rank
	}
	for(i=0;i<mpi_size;i++){
		mpi_displs[i] = i;
	}
	MPI_Allgatherv(&mpi_sample_num, 1, MPI_INT, mpi_sample_num_list, mpi_reccount_list, mpi_displs, MPI_INT, MPI_COMM_WORLD );
	fprintf(stdout,"[%d/%d]sample dimensions:%d:\n",mpi_rank,mpi_size,mpi_sample_dim);

	fprintf(stdout,"[%d/%d]num samples:%d:\n",mpi_rank,mpi_size,mpi_sample_num);
	printf("\n-----\n");

	MPI_Finalize();
	fprintf(stdout,"[%d/%d]",mpi_rank,mpi_size);
	for(i=0;i<mpi_size;i++){
		fprintf(stdout," %d",mpi_sample_num_list[i]);
	}
	fprintf(stdout,"\n");
	fprintf(stdout,"END\n");

}
