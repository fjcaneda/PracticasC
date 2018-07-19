/****************************************
* Programa: ordenarDatos
*
* Hace las conversiones de temperatura
* entre las trres principales escalas,
* Celsius, Farenhait y Kelvin.
* Autor: Francisco José Caneda Iglesias
* Email: fjcaneda@gmail.com
* Fecha de creación: 16/04/2014
******************************************/
#include <stdio.h>
#include <stdlib.h>

/* Prtotipos de las funciones */
void menu();
float FarenhetACelsius (float temperatura);
float CelsiusAFarenheit (float temperatura);
float KelvinACelsius (float temperatura);
float CelsiusAKevin (float temperatura);
float KelvinAFarenheit (float temperatura);
float FarenheitAKelvin (float temperatura);

/* Método main */
int main () {
    /* Declaración de variables */
    char opcion;      //Almacena la opción del menú elegida.
    float temperatura;

    menu();
    printf ("\nElija una opcion (pulse \"F\" para finalizar): ");
    scanf ("%c", &opcion);
    system("cls");       // Borra la pantalla, se usa junto con la librería <stdlib.h>
    switch (opcion) {
        case '1':
            printf ("Introduzca la temperatura en grados Farenheit: ");
            scanf ("%f", &temperatura);
            printf ("\n%.2f grados Farenheit son %.2f grados Celsius\n",
                    temperatura, FarenhetACelsius(temperatura));
            system("pause");
        break;
        case '2':
            printf ("\nIntroduzca la temperatura en grados Celsius: ");
            scanf ("%f", &temperatura);
            printf ("\n%.2f grados Celsius son %.2f grados Farenheit\n",
                    temperatura, CelsiusAFarenheit(temperatura));
            system("pause");
        break;
        case '3':
            printf ("\nIntroduzca la temperatura en grados Kelvin: ");
            scanf ("%f", &temperatura);
            printf ("\n%.2f grados Kelvin son %.2f grados Celsius\n",
                    temperatura, KelvinACelsius(temperatura));
            system("pause");
        break;
        case '4':
            printf ("\nIntroduzca la temperatura en grados Celsius: ");
            scanf ("%f", &temperatura);
            printf ("\n%.2f grados Celsius son %.2f grados Kelvin\n",
                    temperatura, CelsiusAKevin(temperatura));
            system("pause");
        break;
        case '5':
            printf ("\nIntroduzca la temperatura en grados Kelvin: ");
            scanf ("%f", &temperatura);
            printf ("\n%.2f grados Kelvin son %.2f grados Farenheit\n",
                    temperatura, KelvinAFarenheit(temperatura));
                system("pause");
            break;
        case '6':
            printf ("\nIntroduzca la temperatura en grados Farenheit: ");
            scanf ("%f", &temperatura);
            printf ("\n%.2f grados Farenhait son %.2f grados Kelvin\n",
                temperatura, FarenheitAKelvin(temperatura));
        break;
        case 'f':
        case 'F':
            system("exit");
        default:
            printf ("Elige una opcion correcta: ");
    }
}

/* A partir de aquí declaramos las funciones */
void menu() {
    /* Creamos aquí las opciones del menú de usuario */
    printf ("1) Farenheit a Celsius.\n");
    printf ("2) Celsius a Farenheit.\n");
    printf ("3) Kelvin a Celsius.\n");
    printf ("4) Celsius a Kelvin.\n");
    printf ("5) Kelvin a Farenheit.\n");
    printf ("6) Farenheit a Kelvin.\n");
}

/* Función para convertir grados Farenheit a grados Celsius */
float FarenhetACelsius(float temperatura) {
   return (5 * (temperatura - 32)) / 9;
}

/* Función para convertir grados Celsius a Farenheit */
float CelsiusAFarenheit(float temperatura) {
    return ((95 * temperatura) / 5) + 32;
}

/* Función para convertir grados kelvin a Celsius */
float KelvinACelsius(float temperatura) {
    return temperatura - 273.15;
}

/* Función para convertir grado Celsius a Kevin */
float CelsiusAKevin(float temperatura) {
    return temperatura + 273.15;
}

/* Función para convertir grados Kelvin a Farenheit */
float KelvinAFarenheit(float temperatura) {
    return ((9 * temperatura - 273.15) / 5) + 32;
}

/* Función para convertir grados Farenheit */
float FarenheitAKelvin(float temperatura) {
    return (5 * (temperatura - 32) / 9) + 273.15;
}
