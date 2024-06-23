#if MPI_APP == 1
#include <mpi.h>
#endif

#include "Circle.h"

int main(int argc, char *argv[])
{
#if MPI_APP == 1
    MPI_Init(&argc, &argv);

    int rank, size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
#endif

    kinematics::Circle1 myCircle;
    myCircle.run();

#if MPI_APP == 1
    MPI_Finalize();
#endif
    return 0;
}
