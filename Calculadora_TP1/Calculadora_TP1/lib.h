int validarRango_ (int numero, int maximo, int minimo){

int valido=1;

    if(numero>=minimo && numero<=maximo){
        valido=0;
    }

return valido;
}//validar_Rango



void suma_ (int A, int B){



printf("\n\nEl Resultado de la suma es: %d\n\n", A+B);
}//suma


void resta_ (int A, int B){

printf("\n\nEl Resultado de la resta es: %d\n\n", A-B);
}//resta

void divicion_(int A, int B){

printf("\n\nEl Resultado de la divicion es: %.2f\n\n" ,(float)A/(float)B);
}//divicion

void multiplicar_ (int A, int B){

printf("\n\nEl Resultado de la multiplicacion es: %d\n\n", A*B);
}//multiplicacion


void factorial_(int A){

int i, fact=1;

    for(i=1;i<=A;i++){

        fact= fact*i;
    }

    printf("\n\nEl factorial de %d es: %d\n\n",A,fact);
}//factorial


int distinto_cero_(int A, int B){

int valido=0;

        if(A==0 || B==0){
            valido=1;
        }
return valido;
}//validar num distinto a 0

