/***********************************************************
* Programa: craps.c
* Descripci�n: Este programa emula el juego de dados
* llamado "craps"
* Autor: Francisco Jos� Caneda Iglesias.
* E-male: fjcaneda@gmail.com
***************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* constantes enumeradas que almacenan el estado actual del juego*/
enum status {CONTINUA, GANA, PIERDE};
/* Prototipo de la funci�n tiraDados */
int tiraDados (void);
/* Funci�n main */
int main () {
    int suma;
    int miPunto;

    enum status  statusJuego;

    /*Randomizamos el generador de n�meros mediante las funciones srand () y time () */
    srand (time (NULL));
    suma = tiraDados();

    /* Determina el estado del juego bas�ndose en la suma de los dados */
    switch (suma) {
        /* El jugador gana en el primer tiro */
        case 7:
        case 11:
            statusJuego = GANA;
        break;

        /* El jugador pierde en el primer tiro */
        case 2:
        case 3:
        case 12:
            statusJuego = PIERDE;
        break;

        /* El jugador continua */
        default:
            statusJuego = CONTINUA;
            miPunto = suma;
            printf ("Su punto es %d\n",miPunto);
        break;
    } /* Fin del switch */

    /* Mientras el juego no se complete */
    while (statusJuego == CONTINUA) {
        suma = tiraDados ();

        /* Determinamos el estado del juego */
        if (suma == miPunto) {
            statusJuego = GANA;
        } else if (suma == 7) {
            statusJuego = PIERDE;
        }
    } /* Fin del while */

    /* Despliega el mensaje ve vencedor o derrotado */
    if (statusJuego == GANA) {
        printf ("Enhorabuena, el jugador gana\n");
    } else {
        printf ("Lo siento el jugador pierde\n");
    }
    return 0; /* Indica que el programa terminaa con �xito */
} /* Final del bloque main */

/* Declaraci�n de la funci�n tiraDados */
int tiraDados (void) {
    int dado1;
    int dado2;
    int sumaTemp;

    dado1 = 1 + rand() % 6;
    dado2 = 1 + rand() % 6;
    sumaTemp = dado1 + dado2;

    /* Imprimimos los resultados del tiro de dados */
    printf ( "El jugador ha obtenido una putuacion de %d + %d = %d\n", dado1, dado2, sumaTemp);
    return sumaTemp;
} /* Fin de la funci�n tiraDados */
