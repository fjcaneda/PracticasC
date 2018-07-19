/******************************************************************************
* Programa: ticket
*
* Descripción: Elabora tickets de entrada
* y nos ofrece un resumen de la recaudación
* hasta el momento.
* Los tickets tendrán precios diferentes según
* la edad del cliente.
* infantil menor de 6 años gratis.
* juvenil de 6 años hasta 18 incluidos: 50%.
* adulto de 18 a 65 inclusive: precio completo.
* jubilados mayores de 65: 25%.
* Autor: Francisco José Caneda
* Email: fjcaneda@gmail.com
* Fecha de creación: 30/09/2013
*******************************************************************************/
#include <stdio.h>

int main() {
   const float PRECIO_COMPLETO = 6.0;      //Precio de la butaca
   int butacasVendidas = 0;              //Numero de butacas vendidas
   int edad;                             //Edad del cliente
   float totalRecaudado = 0.0;           //El total de la recaudación
   float precioAPagar;                   //Precio de la butaca
   char opcion = ' ';                    //Opció del programa (T. R o F)
   char tecla = ' ';                     //Tecla Si / No

   /* bucle para confirmar la opción */
   while (opcion != 'F') {
      printf ("Opcion (Ticket, Resumen o Fin): ");
      opcion = ' ';
      while ((opcion != 'T') && (opcion != 'R') && (opcion != 'F')) {
         scanf ("%c", &opcion);
      }

      /*=======================================
               ELABORACIÓN DEL TICKET
        =======================================*/
      /* comprobamos la opción elegda, si es así, decimos al programa que queremos continuar
      con la impresión */
      if (opcion == 'T') {
         tecla = 'S';
         /* Mientras pulsemos Si, imprimimos tickets, preguntamos edad, calculamos precio,
         incrementamos el número de butaacas vendidas e imprimimos el ticket*/
          while (tecla == 'S') {
            printf ("Edad: ");
            scanf ("%d", &edad);
            butacasVendidas++;
            printf (".---------------------------------------.\n");
            printf ("|           TICKET DE ENTRADA           |\n");
            if (edad < 6) {                           //Entrada gratis
               printf ("|ENTRADA GRATUITA: ");
               precioAPagar = 0.0;
            } else if ((edad >= 6) && (edad <= 18)) {   //Descuento 50%
               printf ("|TARIFA JUVENIL: ");
               precioAPagar = PRECIO_COMPLETO / 2.0;
            } else if ((edad >=18) && (edad <=65)) {    //Precio adulto
               printf ("|TARIFA DE ADULTO: ");
               precioAPagar = PRECIO_COMPLETO;
            } else {                                  //Precio de jubilado
               printf ("|TARIFA DE JUBILADO: ");
               precioAPagar = PRECIO_COMPLETO / 4.0;
            }

            totalRecaudado = totalRecaudado + precioAPagar;
            printf ("Precio: %4.2f euros     \n", precioAPagar);
            printf ("'---------------------------------------'\n\n");
            printf ("Otro ticket (S /N): ");
            tecla = ' ';
            while ((tecla != 'S') && (tecla != 'N')) {
               scanf ("%c", &tecla);
            }
          }
      }

      /*=======================================
            RESUMEN DE LA RECAUDACIÓN
        =======================================*/
      if (opcion == 'R') {
         printf ("    \n\nRESUMEN DE VENTAS \n");
         printf ("        ----------------- \n");
         printf ("%4d Entradas vendidas \n", butacasVendidas);
         printf ("Total recaudado: %10.2f euros\n\n", totalRecaudado);
      }
   }
}
