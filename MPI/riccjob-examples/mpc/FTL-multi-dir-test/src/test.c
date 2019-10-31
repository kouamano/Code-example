#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <mpi.h>

int
main(int argc, char *argv[]) {
    FILE *r_fp, *w_fp;
    char inputfile[BUFSIZ];
    char outputfile[BUFSIZ];
    char buf[BUFSIZ];
    int rank;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    /* read input file */
    sprintf(inputfile, "data/data.%d", rank);
    if (NULL == (r_fp = fopen(inputfile, "r"))) {
        MPI_Abort(MPI_COMM_WORLD, 1);
    }
    fgets(buf, BUFSIZ, r_fp);
    buf[strlen(buf)-1] = '\0';
    fclose(r_fp);

    /* write output file */
    sprintf(outputfile, "data.%d.out", rank);
    if (NULL == (w_fp = fopen(outputfile, "w"))) {
        MPI_Abort(MPI_COMM_WORLD, 1);
    }
    fprintf(w_fp, "%s %s\n", buf, buf);
    fclose(w_fp);

    MPI_Barrier(MPI_COMM_WORLD);
    MPI_Finalize();
}
