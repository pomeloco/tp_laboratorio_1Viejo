#include <stdio.h>
#include <stdlib.h>
#include "lib.h"


int main()
{

   int opcionMenu,A=0,B=0;
   char seguir;

   do{
        system("CLS");
        printf("------------------Calculadora de Numeros Enteros------------------\n");
        printf("elija una opcion:\n\n1.Ingresar X: %d\n2.Ingresar Y: %d\n3.Suma\n4.Resta\n5.Divicion\n6.Multiplicacion\n7.Factorial\n8.Realizar Todas las Operaciones\n9.Salir\n\n", A,B);
        printf("------------------------------------------------------------------\n");
        scanf("%d", &opcionMenu);

        while(validarRango_(opcionMenu,9,1)){
            printf("elija una opcion valida: ");
            scanf("%d", &opcionMenu);
        }

        switch(opcionMenu){

        case 1:     printf("ingrese el primer operando: ");
                    scanf("%d", &A);
                    break;


        case 2:     printf("ingrese el segundo operando: ");
                    scanf("%d", &B);
                    break;



        case 3:     suma_(A,B);
                    break;


        case 4:     resta_(A,B);
                    break;

        case 5:     if(distinto_cero_(A,B)){

                    printf("no se puede realizar la divicion por que un numero tiene el valor 0\n");

                    }else{

                    divicion_(A,B);

                    }
                    break;

        case 6:    multiplicar_(A,B);
                   break;

        case 7:     factorial_(A);
                    break;

        case 8:     suma_(A,B);

                    resta_(A,B);

                    if(distinto_cero_(A,B)){

                    printf("no se puede realizar la divicion por que un numero tiene el valor 0\n");

                    }else{

                    divicion_(A,B);

                    }
                    multiplicar_(A,B);

                    factorial_(A);
                    break;

        case 9:     return 0;
                    break;

        }//siwtch

        printf("desea continuar?: ");
        fflush(stdin);
        scanf("%c", &seguir);
        seguir=tolower(seguir);

    }while(seguir=='s');


    return 0;
}


