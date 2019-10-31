#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mpi.h>
#include "/home/amano/include/alloc.c"
#include "/home/amano/include/data_read.c"
#include "/home/amano/include/math_base.c"
#define STRSIZE 256
#define STRSIZE_LARGE 1024

int main(int argc, char **argv){
	int i,j;
	int mpi_rank;
	int mpi_size;
	char *file_name_head;
	char *mpi_target_file_name;
	char *mpi_rank_str;
	int mpi_c;
	int mpi_sample_dim = 0;
	int mpi_sample_num = 0;
	int *mpi_sample_num_list;
	float *mpi_sample_ave_vec;
	float **mpi_sample_ave_mat;
	double *total_sample_ave_vec;
	double total_sample_num;
	char **mpi_sample_head;
	float **mpi_sample_mat;
	int *mpi_reccount_list;
	int *mpi_displs;
	FILE *mpi_target_fp;

	file_name_head = c_alloc_vec(STRSIZE_LARGE);

	sscanf(argv[1],"%s",file_name_head);

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

	/* (* file: open */
	printf("[%d/%d] file: open\n",mpi_rank,mpi_size);
	if((mpi_target_fp = fopen(mpi_target_file_name,"r")) == NULL){
		perror(mpi_target_file_name);
		exit(0);
	}
	read_ilist_from_stream(1,mpi_target_fp,&mpi_sample_dim);
	read_ilist_from_stream(1,mpi_target_fp,&mpi_sample_num);

	mpi_sample_head = c_alloc_mat(mpi_sample_num,STRSIZE);
	mpi_sample_mat = f_alloc_mat(mpi_sample_num,mpi_sample_dim);
	mpi_sample_ave_vec = f_calloc_vec(mpi_sample_dim);
	mpi_sample_ave_mat = f_calloc_mat(mpi_size,mpi_sample_dim);
	total_sample_ave_vec = d_calloc_vec(mpi_sample_dim);

	read_ID_ftable_from_stream(mpi_sample_num,mpi_sample_dim,mpi_target_fp,mpi_sample_mat,mpi_sample_head);
	
	fclose(mpi_target_fp);
	printf("[%d/%d] file: close\n",mpi_rank,mpi_size);
	/* *) */

	/* (* check */
	printf("[%d/%d] ave:start:",mpi_rank,mpi_size);
		for(j=0;j<mpi_sample_dim;j++){
			printf(" %lf",mpi_sample_ave_vec[j]);
		}
	printf("\n");
	/* *) */

	/* (* rank vec mean */
	for(i=0;i<mpi_sample_num;i++){
		for(j=0;j<mpi_sample_dim;j++){
			mpi_sample_ave_vec[j] += mpi_sample_mat[i][j];
		}
	}
		for(j=0;j<mpi_sample_dim;j++){
			mpi_sample_ave_vec[j] = mpi_sample_ave_vec[j]/mpi_sample_num;
		}
	/* *) */

	/* (* check */
	for(i=0;i<mpi_sample_num;i++){
		printf("%s",mpi_sample_head[i]);
		for(j=0;j<mpi_sample_dim;j++){
			printf(" %lf",mpi_sample_mat[i][j]);
		}
		printf("\n");
	}
	printf("[%d/%d] ave:end:",mpi_rank,mpi_size);
		for(j=0;j<mpi_sample_dim;j++){
			printf(" %lf",mpi_sample_ave_vec[j]);
		}
	printf("\n");
	/* *) */

	/* (* allgather num */
	for(i=0;i<mpi_size;i++){
		mpi_reccount_list[i] = 1;	//recieve from size:1 each rank
	}
	for(i=0;i<mpi_size;i++){
		mpi_displs[i] = i;
	}
	MPI_Allgatherv(&mpi_sample_num, 1, MPI_INT, mpi_sample_num_list, mpi_reccount_list, mpi_displs, MPI_INT, MPI_COMM_WORLD );
	fprintf(stdout,"[%d/%d] sample dimensions:%d:\n",mpi_rank,mpi_size,mpi_sample_dim);

	fprintf(stdout,"[%d/%d] num samples:%d:\n",mpi_rank,mpi_size,mpi_sample_num);
	for(i=0;i<mpi_size;i++){
		fprintf(stdout,"[%d/%d]mpi_sample_num_list[%d]:%d:\n",mpi_rank,mpi_size,i,mpi_sample_num_list[i]);
	}
	/* *) */

	/* (* allgather ave_mat */
	for(i=0;i<mpi_size;i++){
		mpi_reccount_list[i] = mpi_sample_dim;	//recieve sizes:mpi_sample_dim from each rank
	}
	for(i=0;i<mpi_size;i++){
		mpi_displs[i] = i*mpi_sample_dim;	//recieve pointers for each rank
	}
	MPI_Allgatherv(mpi_sample_ave_vec,mpi_sample_dim,MPI_FLOAT,mpi_sample_ave_mat[0],mpi_reccount_list,mpi_displs,MPI_FLOAT,MPI_COMM_WORLD);	//????
	//MPI_Allgatherv(mpi_sample_ave_vec,mpi_sample_dim,MPI_FLOAT,&mpi_sample_ave_mat[0][0],mpi_reccount_list,mpi_displs,MPI_FLOAT,MPI_COMM_WORLD);	//????
	for(i=0;i<mpi_size;i++){
		for(j=0;j<mpi_sample_dim;j++){
			printf(" [%d/%d:%d:%d]:%f",mpi_rank,mpi_size,i,j,mpi_sample_ave_mat[i][j]);
		}
		printf("\n");
	}
	/* *) */

	/* (* total mean */
	total_sample_num = 0;
	for(i=0;i<mpi_size;i++){
		total_sample_num += mpi_sample_num_list[i];
	}
	printf("[%d/%d] total_sample_num:%d:\n",mpi_rank,mpi_size,total_sample_num);
	for(i=0;i<mpi_size;i++){
		for(j=0;j<mpi_sample_dim;j++){
			total_sample_ave_vec[j] += (double)(mpi_sample_ave_mat[i][j] * mpi_sample_num_list[i]);
		}
	}
		for(j=0;j<mpi_sample_dim;j++){
			total_sample_ave_vec[j] = total_sample_ave_vec[j]/total_sample_num;
		}
		for(j=0;j<mpi_sample_dim;j++){
			printf(" [%d/%d]total_sample_ave_vec[%d]:%lf",mpi_rank,mpi_size,j,total_sample_ave_vec[j]);
		}
		printf("\n");
	/* *) */


	MPI_Finalize();

	fprintf(stdout,"\n[%d/%d] END\n",mpi_rank,mpi_size);

	return(0);

}
