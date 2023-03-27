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
  char mess[] = "Hello World Daniela and Fernando :)";
  MPI_Status status;

  for (i = 0; i < num; i += 2) {
    if (rank == i) {
      printf("%i sent %s to %i\n", rank, mess, rank + 1);
      MPI_Send(mess, strlen(mess) + 1, MPI_CHAR, rank + 1, MESSTAG, MPI_COMM_WORLD);
    } else if (rank == i + 1 && rank < num - 1) {
      MPI_Recv(mess, MAXLEN, MPI_CHAR, rank - 1, MESSTAG, MPI_COMM_WORLD, &status);
      printf("%i received %s from %i\n", rank, mess, rank - 1);
      MPI_Send(mess, strlen(mess) + 1, MPI_CHAR, rank - 1, MESSTAG, MPI_COMM_WORLD);
    }
  }

  //**** FINALIZACION DEL ENTORNO ****//
  MPI_Finalize ();
  return 0;
}