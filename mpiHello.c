//HT 2
// PARALELA
// Daniela Villamar
// Fernando Hengstenberg

#include <mpi.h>     // Incluimos la bibloteca básica para MPI
#include <string.h>
#include <stdio.h>
#define MESSTAG 0
#define MAXLEN 100
int
main (int argc, char **argv)
{
  //**** INICIO DEL ENTORNO ****//
  MPI_Init (&argc, &argv);

  //**** CAPTURA DE DATOS DEL COMUNICADOR ****//
  int rank, num, i;
  MPI_Comm_rank (MPI_COMM_WORLD, &rank);
  MPI_Comm_size (MPI_COMM_WORLD, &num);
  
  //**** DISTRIBUCION DEL TRABAJO **** //
  printf ("Hello from process %i of %i\n", rank, num);

  //**** FINALIZACION DEL ENTORNO ****//
  MPI_Finalize ();
  return 0;
}