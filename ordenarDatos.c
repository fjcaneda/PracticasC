/****************************************
* Programa: ordenarDatos
*
* Descripción: Este programa ordena
* tres datos numéricos de menor a mayor
* Autor: Francisco José Caneda
* Email: fjcaneda@gmail.com
* Fecha de creación: 30/09/2013
******************************************/
#include <stdio.h>

int main () {
   int valor1, valor2, valor3, aux;

   /* Leemos los datos */
   printf ("Introduce los datos: ");
   scanf ("%d %d %d", &valor1, &valor2, &valor3);

   /* Ordenamos los dos primeros datos */
   if (valor1 > valor2) {
      aux = valor1;
      valor1 = valor2;
      valor2 = aux;
   }

   /* Ponemos en su sitio el tercer dato */
   if (valor3 < valor1) {
      aux = valor3;
      valor3 = valor2;
      valor2 = valor1;
      valor1 = aux;
   } else if (valor3 < valor2) {
      aux = valor2;
      valor2 = valor3;
      valor3 = aux;
   }

   /* Imprimimos los resultados por pantalla */
   printf ("\nLos datos de menor a mayor son: %5d %5d %5d\n", valor1, valor2, valor3);
}

