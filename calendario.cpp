#include <stdio.h>
#include <string.h>

/*========================================*/
/* Declaración tipos y variables globales */
/*========================================*/
typedef char T_Strmes[12];
typedef T_Strmes T_TextoMeses[13];
T_TextoMeses nomMes={"?","ENERO","FEBRERO","MARZO","ABRIL",
                    "MAYO","JUNIO","JULIO","AGOSTO",
                    "SEPTIEMBRE","OCTUBRE","NOVIEMBRE","DICIEMBRE"};

typedef int T_NumDiasMes[13];
T_NumDiasMes diasDelMes={0,31,28,31,30,31,30,31,31,30,31,30,31};

typedef enum T_Diasem {
    Lunes,Martes,Miercoles,Jueves,
    Viernes,Sabado,Domingo
  };

/*========================================*/
/*  Parte ejecutiva funciones y procedim. */
/*========================================*/
bool EsBisiesto(int ano){
/** Devuelve si un año es bisiesto **/

  bool esbi;
  int mul4,mul400,mul100;

  esbi=false;
  mul4=ano%4;
  mul400=ano%400;
  mul100=ano%100;

  if (mul4==0){       /*<- Es bisiesto si es multiplo de 4 ... */
    esbi=true;
  }
  if (mul100==0) {    /*<- pero no multiplo de 100 ... */
    esbi=false;
  }
  if (mul400==0) {    /*<- salvo que sea multiplo de 400. */
    esbi=true;
  }
  return esbi;
}

int DiasdesdeDado(int mes,int ano){
/** Devuelve el numero de días desde Ene 1601 hasta día 1 del mes dado **/

  int difanos,numanos,numdias,diasbi;

  numanos=ano-1601;
  numdias=numanos*365;

  /* Dias a añadir por los años bisiestos */{
  difanos=ano-1600;
  numanos=difanos;                  /*<- 1600 fue año bisiesto */
  diasbi=0;
  if (numanos>=400){                  /*<- 97 años bisiestos cada 400 años */
    diasbi=(numanos/400)*97;
    numanos=numanos%400;
  }
  if (numanos>=100){                  /*<- 24 años bisiestos cada 100 años */
    diasbi=diasbi+(numanos/100)*24;
    numanos=numanos%100;
  }
  if (numanos>=4){                    /*<- bisiestos en el ultimo siglo */
    diasbi=diasbi+numanos/4;
  }
  if (EsBisiesto(ano) && mes<3){      /*<- Si el año dado es bisiesto */
    diasbi=diasbi-1;                  /*   y el mes menor que marzo */
  }                                   /*  quitar el dia bisiesto del año */
  numdias=numdias+diasbi;
  }

  /* Dias por los meses desde Enero */{
  for (int i=1;i<mes;i++){
    numdias=numdias+diasDelMes[i];
  }
  }

  return numdias;
}

T_Diasem DiaSemana (int mes,int ano){
/** Devuelve el dia de la semana (Lunes,Martes...Domingo), en
función de los dias pasados desde 1/1/1601 Lunes **/

  T_Diasem diase;
  int numdias;

  numdias=DiasdesdeDado(mes,ano);
  numdias=numdias%7;

  switch (numdias){
    case 0:
      diase=Lunes;
      break;
    case 1:
      diase=Martes;
      break;
    case 2:
      diase=Miercoles;
      break;
    case 3:
      diase=Jueves;
      break;
    case 4:
      diase=Viernes;
      break;
    case 5:
      diase=Sabado;
      break;
    default:
      diase=Domingo;
  }
  return diase;
}

int DiasenMes(int mes,int ano){
/** Devuelve el numero de dias en un mes dado, es
necesario el año para el mes de febrero 28 o 29 dias **/

  int outdias;
  bool bisiesto;

/* En general como la plantilla dada */
  outdias=diasDelMes[mes];

/* Si es Feb. ver si es bisiesto 28/29 dias */
  if (mes==2){
    bisiesto=EsBisiesto(ano);
    if (bisiesto){
      outdias=29;
    }
  }
  return outdias;
}

void ImprimirCalend(int mes,int ano) {
/** Imprime la hoja del calendario de un mes **/

  T_Diasem diaSema;
  T_Strmes textMes;
  int diasMes,restoDias,ultiDias,semanas,contador,espacios;

  /* Inicialización de variables */
  diasMes=DiasenMes(mes,ano);    /*<- Dias que tiene el mes */
  diaSema=DiaSemana(mes,ano);    /*<- Dia de la semana para dia 1 */
  contador=0;
  strcpy(textMes,nomMes[mes]);

  /* Imprimir Cabecera */{
  espacios=23-strlen(textMes);

  printf("\n%s",textMes);
  for(int i=1;i<=espacios;i++){
    printf(" ");
  }
  printf("%4d\n",ano);
  printf("===========================\n");
  printf("LU  MA  MI  JU  VI | SA  DO\n");
  printf("===========================\n");
  }

  /* Imprimir primera linea */{
  if (diaSema!=Lunes){
    espacios=int(diaSema);
    contador=7-espacios;

    for(int i=1;i<=espacios;i++){
      if (i==5){
        printf(" . | ");
      } else {
        printf(" .  ");
      }
    }
    for(int i=1;i<=contador;i++){
      if((espacios+i)==5) {
        printf("%2d | ",i);
      } else {
        printf("%2d  ",i);
      }
    }
    printf("\n");
  }
  }

  /* Imprimir Lineas completas */{
  restoDias=diasMes-contador;
  semanas=restoDias/7;

  for(int i=1;i<=semanas;i++){
    printf("%2d  %2d  %2d  %2d  %2d | %2d  %2d\n",contador+1,contador+2,contador+3,contador+4,contador+5,contador+6,contador+7);
    contador=contador+7;
  }
  }

  /* Imprimir última línea */{
  ultiDias=restoDias%7;
  if (ultiDias!=0){
    for (int i=1;i<=ultiDias;i++){
      if (i==5) {
        printf("%2d | ",contador+i);
      } else {
        printf("%2d  ",contador+i);
      }
    }
    for (int i=1;i<=(7-ultiDias);i++){
      if ((ultiDias+i)==5) {
        printf(" . | ");
      } else {
        printf(" .  ");
      }
    }
    printf("\n");
  }
  printf("\n");
  }

}

int main() {
  int mes,ano;

  printf("¿Mes (1..12)?:");
  scanf("%d",&mes);
  printf("¿Año (1601..3000)?:");
  scanf("%d",&ano);
  if (mes>0 && mes<13){
    if (ano>1600 && ano<3001){
      ImprimirCalend(mes,ano);
    }
  }
}

