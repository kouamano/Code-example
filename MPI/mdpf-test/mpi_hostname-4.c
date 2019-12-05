#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <mpi.h>

int main(int argc, char **argv){
        int my_rank;
        int p;
        int source;
        int dest;
        int tag = 0;
	int i = 0;
        char message[100];

        //printf("prog:mpi-test:\n");

        MPI_Status status;
        MPI_Init(&argc, &argv);
        MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
        MPI_Comm_size(MPI_COMM_WORLD, &p);

	for(i=0;i<100;i++){
		i + 1;
	}
	char hostname[128];
	gethostname(hostname, sizeof(hostname));

        printf("rank:%d/%d:@%s\n",my_rank,p,hostname);
        //printf("p:%d:\n",p);

        MPI_Finalize();

}

