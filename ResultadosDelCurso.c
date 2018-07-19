/********************************************************************
* Programa: resultadosDelCurso.
* Descripciòn: Analiza los resultados de un curso academico.
* El programa pedirá una a una la nota del curso de cada uno
* de los estudiantes hasta diez (las notas serán en formato número
* de 0 a 10), posteriormente se calculará la nota media de todos los
* estudiantes del curso y la consecución de objetivos, siendo la
* condición para que se cumpla el objetivo que haya mas de cinco
* estudiantes aprobados en el curso.
* Autor: Francisco José Caneda Iglesias.
* E-male: fjcaneda@gmail.com
*********************************************************************/
#include <stdio.h>
/* Declaramos la función main de entrada al programa */
int main() {
   int numAprobados = 0;                //número de aprobados
   int numSuspensos = 0;                //número de suspensos
   int numeroDeEstudiantes = 1;         //Contador del número de estudiantes
   float totalNotas = 0.0;              //Total numérico de las notas del curso
   float mediaDelCurso = 0.0;           //Media del curso
   float nota = 0.0;                    //Nota del estudiante

   /*===============================================================
               Introducimos las notas de los estudiantes
   =================================================================*/
   /* Indicamos al usuario que introduzca las notas de los estudiantes */
   while (numeroDeEstudiantes <= 10) {
      printf ("Nota numero %d: ", numeroDeEstudiantes);
      scanf ("%f", &nota);
      /* comprobamos si el estudiante está aprobado o suspenso */
      if (nota >= 5.0) {
         numAprobados++;              // Incrementa en uno el número de aprobados
      } else {
         numSuspensos++;              // Incrementa en uno el número de suspensos
      }
      totalNotas = totalNotas + nota; //Almacenamos el total de la nota hasta el momento
      numeroDeEstudiantes++;
   }
   /*=====================================================================
                     Calculamos la media del curso
   =======================================================================*/
   mediaDelCurso = totalNotas / numeroDeEstudiantes;
   printf ("La nota media del curso ha sido: %2.2f\n", mediaDelCurso);
   /*======================================================================
                 Objetivo del curso
   ========================================================================*/
   printf ("Numero de aprobados: %d\n", numAprobados);
   printf ("Numero de suspensos: %d\n", numSuspensos);
   if (numAprobados >= 5) {
      printf ("Se ha cumplido el objetivo del curso\n");
   } else {
      printf ("No se ha cumplido con el objetivo del curso\n");
   }
}
