/******************************************************
* Programa: sumaPares
* Descripci�n: este  programa imprime el resultado de
* la suma de n�meros pares entre 0 y 100.
* Autor: Francisco Jos� Caneda Iglesias
* E-male: fjcaneda@gmail.com
********************************************************/
#include <stdio.h>
int main() {
    int sumaTotal = 0;     //Almacena la suma total
    int numero;

    for (numero = 0; numero <= 100; numero++) {
        /* comprobamos si el n�mero es par */
        if (numero % 2 == 0) {
            sumaTotal = sumaTotal + numero;
        }
    }
    /* Imprimimos los resultados */
    printf ("La suma de los n�meros pares entre 0 y 100 es: %d\n", sumaTotal);
}
