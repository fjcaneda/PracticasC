/** Programa: SumarNumeros */
/* Este programa calcula e imprime la suma
 de los n�meros correlativos desde 4 hasta 45

 El algoritmo empleado es el utilizado para
 calcular la suma de una progresi�n aritm�tica:
 Suma = (Final - Inicial + 1) * (Inicial + Final) / 2 */

#include <stdio.h>

int main() {
  printf( "La suma de los n�meros desde 4 hasta 45\n" );
  printf( "es igual a: ");
  printf( "%5d\n", (45 - 4 + 1) * (45 + 4) / 2 );
}
