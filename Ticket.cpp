/****************************************************
* Programa: Ticket
*
* Descripción:
*  Este programa elabora el ticket de entrada y los
*  resumenes de recaudación de un espectacúlo.
*  El precio de ticket depende de la edad del
*  espectador (Niño, Joven, Adulto o Jubilado)
******************************************************/
#include <stdio.h>

int main() {
  const float PrecioBase = 6.0;  /* Precio de la butaca */
  int butacas = 0;               /* Número de butacas vendidas */
  int edad;                      /* Edad del cliente */
  float totalEuros = 0.0;        /* Total de euros recaudados */
  float precio;                  /* Preciio de cada butaca */
  char opcion = ' ';             /* Opción del programa */
  char tecla = ' ';              /* tecla Si/No */

  /*-- Bucle hasta opción F de fin --*/
  while (opcion != 'F') {
    printf( "Opcion (Ticket, Resumen o Fin) ? ");
    opcion = ' ';
    while ((opcion != 'T') && (opcion != 'R') && (opcion != 'F')) {
      scanf( "%c", &opcion );
    }

    /*========================
       Elaboración del Ticket
      ========================*/
    if (opcion == 'T') {
      tecla = 'S';
      while (tecla == 'S') {
        printf( "Edad? " );
        scanf( "%d", &edad );
        butacas++;
        printf( "-------------------------------.\n" );
        printf( "|      TICKET DE ENTRADA      |.\n" );
        if (edad < 6) {            /* Niño, gratis */
          printf( "|Gratis  " );
          precio = 0.0;
        } else if (edad < 18) {    /*Joven 50% */
          printf( "|Joven   " );
          precio = PrecioBase / 2.0;
        } else if (edad < 65) {    /* Adulto, tarifa completa */
          printf( "|Adulto   " );
          precio = PrecioBase;
        } else {                   /*Jubilado, 25% */
          printf( "|Jubilado   " );
          precio = PrecioBase / 4.0;
        }
        totalEuros = totalEuros + precio;
        printf( "         Precio: %4.2f|\n", precio);
        printf( "------------------------------\n\n" );
        printf( "Otro Ticket(S/N)? " );
        tecla = ' ';
        while ((tecla != 'S') && (tecla != 'N')) {
          scanf( "%c", &tecla );
        }
      }
    }
    /*===========================================
       Elaboración del resumen de la recaudación
      ===========================================*/

    if (opcion == 'R') {
      printf( "   RESUMEN DE VENTAS \n" );
      printf( "   ----------------- \n" );
      printf( "%4d Butacas \n", butacas );
      printf("Total Recaudado = %10.2f\n\n", totalEuros );
    }
  }
}
