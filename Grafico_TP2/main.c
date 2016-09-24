#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 2

typedef struct{

    char nombre[20];
    int edad;
    char dni[9];
    int estado;

}ePersona;

int menu_(void); //menu de opciones
int validar_rango(int,int,int);//valida rango (numero,maximo,minimo)
void alta_persona (ePersona[]);//dar altas
void inicializar_cero (ePersona[]);//dar valor a .estado
int buscar_libre (ePersona[]);//busca primer lugar libre
void dar_baja (ePersona[]); //dar baja personas
void ordenar_xnombre (ePersona[]);//personas ordenadas por nombre
void listar_personas (ePersona []); //listar personas
void crear_grafico (ePersona[]);


int main()
{
   ePersona Personas[TAM];
   char respuesta='s';

   inicializar_cero(Personas);

   do{
        switch(menu_()){


        case 1: alta_persona(Personas);
                system("CLS");
                break;



        case 2: dar_baja(Personas);
                system("CLS");
                break;


        case 3: ordenar_xnombre(Personas);
                listar_personas(Personas);
                system("CLS");
                break;


        case 4: crear_grafico(Personas);
                break;



        case 5: return 0;


        }//switch
    }while(respuesta=='s');

    return 0;
}


int validar_rango(int numero, int maximo, int minimo){

int valido=1;

    if(numero>=minimo && numero<=maximo){

        valido=0;
    }

 return valido;
}//validar rango




int menu_ (){

int opcion;

printf("Ingrese opcion a realizar:\n1.Agregar Persona\n2.Borrar Persona\n3.Imprimir lista ordenada por nombre\n4.Realizar grafico por edades\n5.Salir\n\n- ");
scanf("%d", &opcion);
system("CLS");

while(validar_rango(opcion,5,1)){

    printf("Error!!\n-Debe ingresar una opcion valida.\n- ");
    scanf("%d", &opcion);
}

return opcion;
}//menu de opciones


void inicializar_cero(ePersona Personas[]){

int i;

    for(i=0 ; i<TAM ; i++){

        Personas[i].estado=0;

    }//for


}//inicializar el estado a 0



int buscar_libre(ePersona Personas[]){

int i;
int index=-1;

    for(i=0 ; i<TAM ; i++){

        if(Personas[i].estado == 0){

            index=i;

        }//if

    }//for


    return index;
}//busca primer lugar libre




void alta_persona(ePersona personas_alta[]){

int lugar;
int AUX_int;
char AUX_cad[50];
int i;


        lugar = buscar_libre(personas_alta);

        if(lugar!=-1){

            printf("Ingrese su nombre: ");
            fflush(stdin);
            scanf("%s", &AUX_cad);

            while(strlen(AUX_cad)>20){  //validar cadena

                printf("\nNombre demaciado largo, reingrese: ");
                fflush(stdin);
                scanf("%s", &AUX_cad);

            }//while

            strcpy(personas_alta[lugar].nombre, AUX_cad);

            printf("\nIngrese su edad: ");
            fflush(stdin);
            scanf("%d", &AUX_int);

            while(AUX_int<0){   //validar edad

                printf("\nERROR!\n edad ingresada no valida, reingrese: ");
                fflush(stdin);
                scanf("%d", &AUX_int);
            }//validar edad

            personas_alta[lugar].edad=AUX_int;

            printf("\nIngrese su DNI: ");
            fflush(stdin);
            scanf("%s", AUX_cad);

            while(strlen(AUX_cad)>8 || strlen(AUX_cad)<8){  //validar dni

                printf("\nERROR\nDNI incorrecto (8 digitos), reingrese: ");
                fflush(stdin);
                scanf("%s", AUX_cad);

            }//while

            /*for(i=0 ; i<TAM ; i++){

                    if(strcmp(AUX_cad ,personas_alta[i].dni)==0 && personas_alta[i].estado){

                    strcpy(personas_alta[lugar].dni, AUX_cad);
                    personas_alta[lugar].estado=1;

                    printf("\n\nCargado con exito.\n");
                    system("pause");
                    break;


                    }else{

                        printf("\nEl dni ya fue ingresado.\n");
                        system("pause");
                        break;

                    }
            }//for*/ //no puedo validar los DNI ingresados

                    strcpy(personas_alta[lugar].dni, AUX_cad);
                    personas_alta[lugar].estado=1;

        }else{
        printf("\n no hay lugar disponible.\n");
        system("pause");
        }

}//altas persona



void dar_baja(ePersona personas_baja[]){

int i;
char AUX_cad[20];
char valid;

        printf("\nIngrese numero de documento a dar de baja: ");
        fflush(stdin);
        scanf("%s", &AUX_cad);

        while(strlen(AUX_cad)>8 || strlen(AUX_cad)<8){  //validar dni

                printf("\nERROR\nDNI incorrecto (8 digitos), reingrese: ");
                fflush(stdin);
                scanf("%s", &AUX_cad);

            }//while

        for(i=0 ; i<TAM ; i++){

            if(strcmp(AUX_cad, personas_baja[i].dni)==0 ){

                printf("\n\nPersona encontrada!!\n-Seguro desea borrar a %s ?(s/n): ", personas_baja[i].nombre);
                fflush(stdin);
                scanf("%c", &valid);

                while(valid!='s' && valid!='n'){

                    printf("\nOpcion incorrecta, ingrese (S/N): ");
                    fflush(stdin);
                    scanf("%c", &valid);

                }

                if(valid=='s'){
                    personas_baja[i].estado=0;
                    printf("\nLa persona fue borrada con exito. \n");
                }else

             break;
            }else{
            printf("\nPersona no encontrada.\n");
            }

        }//for


}//dar baja




void ordenar_xnombre(ePersona ordenar_Personas[]){

ePersona AUX_persona;
int i;
int j;
int criterio;


    printf("\nIngrese criterio de ordenamiento:\n1.A-Z\n2.Z-A\n- ");
    fflush(stdin);
    scanf("%d", &criterio);
    system("cls");

    while (validar_rango(criterio, 2,1)){

        printf("\nIngrese una opcion valida:");
        fflush(stdin);
        scanf("%d", &criterio);
    }//while


        for(i=0 ; i<TAM-1 ; i++){
                for(j=i+1 ; j<TAM ; j++){

                    if(criterio==1){

                            if(strcmp(ordenar_Personas[i].nombre, ordenar_Personas[j].nombre) > 0){


                                AUX_persona=ordenar_Personas[i];
                                ordenar_Personas[i]=ordenar_Personas[j];
                                ordenar_Personas[j]=AUX_persona;
                            }


                    }else{

                        if(strcmp(ordenar_Personas[i].nombre, ordenar_Personas[j].nombre) < 0){


                                AUX_persona=ordenar_Personas[i];
                                ordenar_Personas[i]=ordenar_Personas[j];
                                ordenar_Personas[j]=AUX_persona;

                            } //if

                    }//else

                }//for J

        }//for I





}//ordenar personas


void listar_personas(ePersona mostrar_Personas[]){

int i;

    printf("Nombre\tEdad\tDNI\n----------------------------\n\n\n\n");
        for(i=0 ; i<TAM ; i++){

            if(mostrar_Personas[i].estado==1){
            printf("%s\t%d\t%s\n----------------------------\n", mostrar_Personas[i].nombre, mostrar_Personas[i].edad, mostrar_Personas[i].dni);
            }
        }
    system("pause");
}//listar personas

void crear_grafico(ePersona grafico_personas[]){

   int i, flag=0 ;


    for(i=TAM; i>0; i--){
        if(i<10){
            printf("%02d|",grafico_personas[i].edad);
        }
        else
            printf("%02d|",grafico_personas[i].edad);

        if(grafico_personas[i].edad <= 18){
            printf("*");
        }
        if(grafico_personas[i].edad <= 19 && grafico_personas[i].edad >= 35){
            flag=1;
            printf("\t*");
        }
        if(grafico_personas[i].edad <= 35){
            if(flag==0)
                printf("\t\t*");
            if(flag==1)
                printf("\t*");

        }
        //Bajo una linea luego de cada iteracion
        printf("\n");
    }
    printf("--+-----------------");
    printf("\n  |<18\t19-35\t>35\n");
   // printf("\n   %d\t%d\t%d", hasta18, de19a35, mayorDe35);



    return 0;
}//grafico
