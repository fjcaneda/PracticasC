/*************************************************
* Programa: TrianguloDeNumeros
*
* Descripción:
*  Este programa escribe unn triángulo de dígitos.
*  La altura se lee comodato y debe ser menor de 10
***************************************************/
#include <stdio.h>

int main() {
  const int centro = 35;   /* Posición del eje del triangulo */
  const int inicial = 1;   /* Dígito inicial, superior y laterales */
  int nivel;

  /*-- Leer los datos --*/ {
    printf( "¿Altura del triángulo? " );
    scanf( "%d", &nivel);
  }
  /*-- Una iteración por cada línea del triángulo  --*/
  for ( int altura = inicial; altura <= nivel; altura++) {

    /* Paso 1º: Situar el primer número de cada línea --*/ {
      for (int indice = 1; indice <= centro-altura; indice++) {
        printf( " ");
      }
      printf( "%d", inicial );
    }
    /*-- Paso 2º: Primera mitad de la línea del triángulo
         Escribir números consecutivos hasta altura --*/ {
      for (int indice = inicial + 1; indice <= altura; indice++) {
        printf( "%1d", indice );
      }
    }
    /*-- Paso 3º: Segunda mitad de la línea del triángulo.
         Escribir números descendientes hasta Inicial --*/ {
      for (int indice = altura - 1; indice >= inicial; indice--) {
        printf( "%1d", indice );
      }
    }
    /*-- Paso4º: Saltar a una nueva línea --*/ {
      printf( "\n" );
    }
  }
}
