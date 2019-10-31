#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<mpi.h>

int main(int argc, char **argv){
	int mpi_rank;
	int mpi_size;
	int i;

	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &mpi_rank);
	MPI_Comm_size(MPI_COMM_WORLD, &mpi_size);

	for(i=0; i<argc; i++){
		printf("[%d/%d][%d]:%s:\n",mpi_rank,mpi_size,i,argv[i]);
	}

	MPI_Finalize();

	return(0);
}
