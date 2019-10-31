#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mpi.h>

int main(int argc, char **argv){
        int my_rank;
        int np;
        int source;
        int dest;
        int tag = 0;
        char *message;
        char *rcv;
	if((message = malloc(sizeof(char) * 100)) == NULL){
		perror("[F]\n");
		exit(1);
	}
	message[0] = '\0';
	if((rcv = malloc(sizeof(char) * 100)) == NULL){
		perror("[F]\n");
		exit(1);
	}
	rcv[0] = '\0';

        printf("prog:mpi-test:\n");

        MPI_Status status;
        MPI_Init(&argc, &argv);
        MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
        MPI_Comm_size(MPI_COMM_WORLD, &np);

        printf("rank:%d:\n",my_rank);
        printf("nproc:%d:\n",np);

	sprintf(message,"From %d",my_rank);
	dest = 0;
	if(my_rank != 0){
		MPI_Send(message,strlen(message)+1,MPI_CHAR,dest,tag,MPI_COMM_WORLD);
	}
	if(my_rank == 0){
		for(source=1;source<np;source++){
			//MPI_Recv(rcv,100,MPI_CHAR,source,tag,MPI_COMM_WORLD,&status);
			MPI_Recv(rcv,100,MPI_CHAR,source,tag,MPI_COMM_WORLD,&status);
			printf("%s\n",rcv);
		}
	}

        MPI_Finalize();

}

