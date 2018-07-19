/******************************************************
* Programa: sumaPares
* Descripción: este  programa imprime el resultado de
* la suma de números pares entre 0 y 100.
* Autor: Francisco José Caneda Iglesias
* E-male: fjcaneda@gmail.com
********************************************************/
#include <stdio.h>
int main() {
    int sumaTotal = 0;     //Almacena la suma total
    int numero;

    for (numero = 0; numero <= 100; numero++) {
        /* comprobamos si el número es par */
        if (numero % 2 == 0) {
            sumaTotal = sumaTotal + numero;
        }
    }
    /* Imprimimos los resultados */
    printf ("La suma de los números pares entre 0 y 100 es: %d\n", sumaTotal);
}
