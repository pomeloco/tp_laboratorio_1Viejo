#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#define TAM 3

// hecho con C99

typedef struct{

    char nombre[20];
    int edad;
    char dni[8];
    int flag;

}ePersona;


void inicializar_flags (ePersona[], int);//inicializa flags en 0
int buscar_Libre (ePersona[], int);//busca primer lugar libre en array
int buscar_Persona (ePersona[], int, char[]);//buscar persona por dni en array

void imprimir_grafico(ePersona[]);
void mostrar_lista(ePersona[]);
void baja_persona (ePersona[]);
void agregar_persona (ePersona[]);//agrega una persona al array


int main()
{

 int opcion;
 char seguir='s';
 ePersona Personas[TAM];



    inicializar_flags(Personas, TAM);

    do{
        system("CLS");
        printf("\t*******menu*****\n1.Agregar Personas\n2.Borrar persona (ver codigo funcion <buscar persona>)\n3.Mostrar Lista\n4.Graficar\n5.Salir\n>");
        fflush(stdin);
        scanf("%d", &opcion);

        while(opcion<1||opcion>5){

            printf("opcion no valida, reingrese\n>");
            fflush(stdin);
            scanf("%d", &opcion);
        }

        switch(opcion){

            case 1: system("CLS");
                    agregar_persona(Personas);//agregar una persona
                    break;

            case 2: system("CLS");
                    baja_persona(Personas);// borrar una persona
                    break;

            case 3: system("CLS");
                    mostrar_lista(Personas);//imprimir lista ordenada por nombre
                    break;

            case 4: system("CLS");
                    imprimir_grafico(Personas);
                    // imprimir grafico de edades
                    break;

            case 5: return 0;
                    break;



        }//switch

    printf("desea continuar? ");
    fflush(stdin);
    }while(tolower(seguir=getchar())=='s');



    return 0;
}//main


void inicializar_flags(ePersona Personas[], int tam){

    for(int i=0;i<tam;i++){

        Personas[i].flag=0;
    }//for

}//funcion inicializar flags


int buscar_Libre(ePersona Personas[], int tam){

int index=-1;

    for(int i=0;i<tam;i++){

            if(Personas[i].flag==0){

                index=i;
                break;

            }//if

    }//for
    return index;
}//funcion buscar libre


void agregar_persona (ePersona Persona[]){

    int index;
    char auxCHAR[30];
    int auxINT;

        index=buscar_Libre(Persona, TAM);

        if(index!=-1){

            printf("ingrese nombre: ");
            fflush(stdin);
            gets(auxCHAR);

            while(strlen(auxCHAR)>20){

                printf("\nNombre Demasiado largo, reingrese: ");
                fflush(stdin);
                gets(auxCHAR);

            }//while

            strcpy(Persona[index].nombre,auxCHAR);

            printf("Ingrese Edad: ");
            scanf("%d", &auxINT);

            while(auxINT<0){

                printf("Error, reingrese edad: ");
                fflush(stdin);
                scanf("%d", &auxINT);
            }//while

            Persona[index].edad=auxINT;

            printf("Ingrese DNI: ");
            fflush(stdin);
            gets(auxCHAR);

            while(strlen(auxCHAR)>8){

                printf("DNI demasiado largo, reingrese: ");
                fflush(stdin);
                gets(auxCHAR);

            }//while

            strcpy(Persona[index].dni,auxCHAR);


            Persona[index].flag=1;

        }else{

            printf("\n no se encontro espacio disponible\n");

        }//if else

}//funcion agregar_persona


int buscar_Persona(ePersona Personas[], int tam, char auxCHAR[]){

int encontrado=-1;
//char auxCHAR[30];
int aux;


    for(int i=0;i<tam;i++){
        aux=strcmp(Personas[i].nombre,auxCHAR);

        if(strcmp(Personas[i].nombre,auxCHAR)==0 && Personas[i].flag==1){

            encontrado=i;
            break;
        }

    }//for


return encontrado;
}//funcion buscar personas





void baja_persona(ePersona Personas[]){

char auxCHAR[30];
int index;
char respuesta;


    printf("\nIngrese DNI a buscar: ");
    fflush(stdin);
    gets(auxCHAR);

    while(strlen(auxCHAR)>8){

            printf("DNI demasiado largo, reingrese: ");
            fflush(stdin);
            gets(auxCHAR);

    }//while

    index=buscar_Persona(Personas, TAM, auxCHAR);


    if(index!=-1){

        printf("\tPersona Encontrada!\n");

        printf("Seguro que dea eliminar a: %s %d %s", Personas[index].nombre, Personas[index].edad, Personas[index].dni);
        fflush(stdin);
        tolower(respuesta=getch());

        while(respuesta!='s' || respuesta!='n'){

            printf("error, debe ingresar s/n");
            fflush(stdin);
            tolower(respuesta=getch());

        }//while

        Personas[index].flag=0;
        printf("La persona fue dada de baja con exito");


    }else{

        printf("Persona no encontrada.\n");

    }



}//funcion dar de baja personas

void mostrar_lista(ePersona Personas[]){

ePersona auxPersona;
int opcionOrd;

    printf("-Elija opcion de ordenamiento\n1.A-Z\n2.Z-A\n>");
    fflush(stdin);
    scanf("%d", &opcionOrd);

    while(opcionOrd<1 || opcionOrd>2){

        printf("opcion no valida, reingrese\n>");
        fflush(stdin);
        scanf("%d", &opcionOrd);
    }


    switch(opcionOrd){

        case 1:
                for(int i=0;i<TAM-1;i++){
                    for(int j=i;j<TAM;j++){

                            if(strcmp(Personas[i].nombre, Personas[j].nombre)>0){

                                auxPersona=Personas[i];
                                Personas[i]=Personas[j];
                                Personas[j]=auxPersona;
                            }


                    }//for J
                }//for I
                break;

        case 2:
                for(int i=0;i<TAM-1;i++){
                    for(int j=i;j<TAM;j++){

                            if(strcmp(Personas[i].nombre, Personas[j].nombre)<0){

                                auxPersona=Personas[i];
                                Personas[i]=Personas[j];
                                Personas[j]=auxPersona;
                            }


                    }//for J
                }//for I
                break;


    }//switch

    printf("Nombre\tEdad\tDNI\n");
    for(int i=0;i<TAM;i++){

        if(Personas[i].flag==1){

            printf("%s\t%d\t%s\n", Personas[i].nombre, Personas[i].edad, Personas[i].dni);
        }
    }

}//funcion mostrar personas



void imprimir_grafico(ePersona Personas[]){

int maximo=-1;

int contadores[3]={0};


        for(int i=0;i<TAM;i++){

            if(Personas[i].edad<18 && Personas[i].flag==1){

                contadores[0]++;
            }else if(Personas[i].edad<35 && Personas[i].edad>18 && Personas[i].flag==1){

                contadores[1]++;
            }else if(Personas[i].edad>35 && Personas[i].flag==1){
                contadores[2]++;

                }

        }//for

    for(int i=0;i<3;i++){

        if(contadores[i]>maximo)
            maximo=contadores[i];

    }



   for (int i = maximo; i > 0; i--){
      for (int j = 0; j < 3; j++)
         if (contadores[j] >= i)
            printf(" *\t");
         else
            printf(" \t");

      putchar('\n');
   }

        printf("<18\t18-35\t>35\n");


}//funciop imprimir grafico
