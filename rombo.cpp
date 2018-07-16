#include <stdio.h>

int main() {

  int lado;
  int posicion;


  printf("Lado del rombo?");
  scanf("%d",&lado);
  printf("\n");


  if ((lado >= 1)&&(lado <= 20)) {

    /* Triangulo superior izquierdo del rombo */
    for (int altura = 1;altura <= lado; altura++) {

      /* Espacios en blanco parte superior */
      for (int indice = 1; indice <= lado - altura; indice++) {
        printf(" ");
      }
      posicion = 4;
      for (int indice = 1; indice <= altura; indice++) {
        if (posicion % 4 == 0) {
          printf ("@");
        } else if ((posicion % 4 == 1)||(posicion % 4 == 3)) {
          printf (".");
        } else {
          printf ("o");
        }
        posicion++;

      }
 /* Triangulo superior derecho del rombo */

      posicion = altura;
      for (int indice = 1; indice <= altura-1; indice++) {
        if (posicion % 4 == 0) {
          printf ("o");
        } else if ((posicion %4 == 1)||(posicion % 4 == 3)) {
          printf (".");
        } else {
          printf ("@");
        }
        posicion--;

      }

      printf("\n");
    }


    /* Triangulo inferior izquierdo del rombo */
    for (int altura = lado; altura >= lado - altura - lado; altura--) {

      /* Espacios en blanco parte inferior */
      for (int indice = lado - 1; indice >= altura - 1; indice--) {
        printf(" ");
      }
      posicion = 4;
      for (int indice = 1;indice <= altura - 1; indice++) {
        if (posicion % 4 == 0) {
          printf ("@");
        } else if ((posicion %4 == 1)||(posicion % 4 == 3)) {
          printf (".");
        } else {
          printf ("o");
        }
        posicion++;

      }
/* Triangulo inferior derecho del rombo */

      posicion = altura-1;
      for (int indice = 2; indice <= altura - 1; indice++) {
        if (posicion % 4 == 0) {
          printf ("o");
        } else if ((posicion % 4 == 1)||(posicion % 4 == 3)) {
          printf (".");
        } else {
          printf ("@");
        }
        posicion--;

      }
      printf("\n");
    }

  }
}
