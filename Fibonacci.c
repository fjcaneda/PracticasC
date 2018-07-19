/* obtenemos el enésimo número de la serie de Fibonacci */
#include <stdio.h>

/* Prototipo de la función */
long fibonacci (long n);

/* Funci�n main - Inicio del programa */
int main() {
    long resultado; //Almacena el resultado de la operación
    long numero;   //número que introducimos por teclado

    /* Pedimos al usuario que introduzca un entero */
    printf ("Introduzca un numero entero: ");
    scanf ("%ld", &numero);

    /* Calculamos el valor fibonacci del número introducido por el usuario */
    resultado = fibonacci (numero);

    /* Imprimimos el resultado */
    printf ("Fibonacci (%ld) = %ld\n", numero, resultado);
    return 0;
} /* Fin del main */

/* Definición de la función fibonacci */
long fibonacci (long n) {
    /*caso base */
    if (n == 0 || n == 1) {
        return n;
    } else {   // paso recursivo
        return fibonacci (n - 1) + fibonacci (n - 2);
    } /* fin del else */
} /* Fin de la función */
