/** Programa: Recibo */
/* C�lculo e impresion de un recibo */

#include <stdio.h>

int main() {
  int cantidad, IVA;
  char codigo;
  float precio, totalIVA, subtotal, total;
  printf( "�C�digo del producto? " );
  scanf( "%c", &codigo);
  printf( "�Cantidad? " );
  scanf( "%d", &cantidad );
  printf( "�Precio unitario? " );
  scanf( "%f", &precio );
  printf( "�IVA aplicable? ");
  scanf( "%d", &IVA );
  subtotal = float(cantidad) * precio;
  totalIVA = subtotal * float(IVA) /100.0;
  total = subtotal + totalIVA;
  printf( "\n               RECIBO DE COMPRA\n\n" );
  printf( "Cantidad    Concepto    Euros/unidad    Total\n" );
  printf( "%5d     Procucto: %c  %12.2f%12.2f\n\n", cantidad, codigo, precio, subtotal );
  printf( "%28d%% IVA  %12.2f\n\n", IVA, totalIVA );
  /* Se ha codificado un %% para imprimir literalmente un % */
  printf( "                               TOTAL%14.2f\n", total );
}
