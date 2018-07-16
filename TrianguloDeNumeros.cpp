/*************************************************
* Programa: TrianguloDeNumeros
*
* Descripci�n:
*  Este programa escribe unn tri�ngulo de d�gitos.
*  La altura se lee comodato y debe ser menor de 10
***************************************************/
#include <stdio.h>

int main() {
  const int centro = 35;   /* Posici�n del eje del triangulo */
  const int inicial = 1;   /* D�gito inicial, superior y laterales */
  int nivel;

  /*-- Leer los datos --*/ {
    printf( "�Altura del tri�ngulo? " );
    scanf( "%d", &nivel);
  }
  /*-- Una iteraci�n por cada l�nea del tri�ngulo  --*/
  for ( int altura = inicial; altura <= nivel; altura++) {

    /* Paso 1�: Situar el primer n�mero de cada l�nea --*/ {
      for (int indice = 1; indice <= centro-altura; indice++) {
        printf( " ");
      }
      printf( "%d", inicial );
    }
    /*-- Paso 2�: Primera mitad de la l�nea del tri�ngulo
         Escribir n�meros consecutivos hasta altura --*/ {
      for (int indice = inicial + 1; indice <= altura; indice++) {
        printf( "%1d", indice );
      }
    }
    /*-- Paso 3�: Segunda mitad de la l�nea del tri�ngulo.
         Escribir n�meros descendientes hasta Inicial --*/ {
      for (int indice = altura - 1; indice >= inicial; indice--) {
        printf( "%1d", indice );
      }
    }
    /*-- Paso4�: Saltar a una nueva l�nea --*/ {
      printf( "\n" );
    }
  }
}
