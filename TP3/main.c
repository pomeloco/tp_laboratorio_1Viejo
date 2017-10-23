#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/******************
Definir una estructura “movie” con los datos de una pelicula:
• Título
• Género
• Duración
• Descripción
• Puntaje
• Link de imagen
---------------------
1. Agregar película
2. Borrar película
3. Modificar película
4. Generar página web
5. Salir
*******************/

typedef struct{

char titulo[30];
char genero[30];
char duracion[5];
char descripcion [50];
int puntaje;
char link[100];

}eMovie;

void add_film(eMovie*, FILE*);


int main()
{
    eMovie* Pelicula;
    FILE *f;
    int opcion=-1;
    char respuesta='s';

    for(int i=0;i<2;i++){

        add_film(Pelicula,f);
    }


    return 0;
}



void add_film(eMovie* Pelicula, FILE *f){

    int contador=1;


    Pelicula = (eMovie*)malloc(sizeof(eMovie));

    if(Pelicula==NULL){
        printf("No se pudo asignar espacio en memoria");
        exit(1);
    }//if null

    f=fopen("pelis.bin","wb");

    if(f==NULL){

        printf("no se pudo abrir el archivo.");
        exit(1);
    }//if archivo

    printf("Ingrese titulo de la pelicula: ");
    fflush(stdin);
    gets(Pelicula->titulo);

    printf("Ingrese genero de la pelicula: ");
    fflush(stdin);
    gets(Pelicula->genero);

    printf("Ingrese duracion de la pelicula: ");
    fflush(stdin);
    gets(Pelicula->duracion);

    printf("Ingrese descripcion de la pelicula: ");
    fflush(stdin);
    gets(Pelicula->descripcion);

    printf("Ingrese puntiacion de la pelicula: ");
    fflush(stdin);
   // scanf("%d", Pelicula->puntaje);

    printf("Ingrese Link de la pelicula: ");
    fflush(stdin);
    gets(Pelicula->link);

    fseek(f,sizeof(Pelicula),contador);
    //fprintf(f,"%s,%s,%s,%s,%d,%s\n", Pelicula->titulo, Pelicula->genero, Pelicula->duracion ,Pelicula->descripcion, Pelicula->puntaje, Pelicula->link);

    fwrite(Pelicula,sizeof(eMovie),contador,f);
    fclose(f);

    contador++;
}//agrega una Pelicula
