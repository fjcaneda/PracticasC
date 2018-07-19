/***********************************************************
* Programa: triangulo de asteriscos.
* Descripción: Este programa dibuja en la consola un
* triángulo de asteriscos como se muestra a continuación,
* siendo la altura del triángulo de 20 lineas como máximo.
*                          *
*                         ***
*                        *****
*                         ***
*                          *
* Autor: Francisco José Caneda Iglesias.
* E-male: fjcaneda@gmail.com
***************************************************************/
#include<stdio.h>

int main() {

    int lado;        //Indica el lado del rombo (lo preguntamos por pantalla)
    int fila;        //fila del rombo
    int columna;     //Columna del rombo

    printf("Lado del rombo? ");
    scanf("%d",&lado);
    printf("\n");


    if ((lado >= 1) && ( lado <= 20)) { //lado minimo = 1, máximo = 20


        /*====================================================================
                    Triángulo superior izquierdo del rombo
          ====================================================================*/

        for (fila = 1; fila <= lado; fila++) {      //Empieza a contar filas

            /*-- Espacios en blanco parte superior --*/
            for (columna = 1; columna <= lado - fila; columna++) {
                printf(" ");
            }

            /*-- Impresión asteriscos --*/
            for (columna = 1; columna <= fila; columna++) {
                printf ("*");
            }

            /*====================================================================
                        Triángulo superior derecho del rombo
              ====================================================================*/

            for (columna = 1; columna <= fila - 1; columna++) {
                printf ("*");
            }
            printf("\n");
        }

        /*====================================================================
                    Triángulo inferior izquierdo del rombo
          ====================================================================*/

        for (fila = lado; fila >= lado - fila - lado; fila--) { //Empieza a contar filas

            /*-- Espacios en blanco parte inferior --*/
            for (int columna = lado - 1; columna >= fila - 1; columna--) {
                printf(" ");
            }

            /* Imprimimos asteriscos */
            for (columna = 1; columna <= fila - 1; columna++) {
                printf ("*");
            }

            /*====================================================================
                                Triángulo inferior derecho del rombo
              =====================================================================*/

            for (columna = 2; columna <= fila - 1; columna++) {
                printf ("*");
            }
            printf("\n");
        }
    }
}
