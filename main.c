#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "CleanTags.h"
#include "Tempo.h"
#include "Position.h"
#include "Style.h"


void print_array(int array[], int N){
    printf("elementos: %d\n", N);
    for (int p = 0; p < N; p++){
        if (p == N-1) printf("%d\n", array[p]);
        else printf("%d -> ", array[p]);
    }
}

void print_estilos(ESTILO lista[], int N){
    for (int p = 0; p < N; p++){
        printf("Estilo ->%s<-\n", lista[p].estilo);
        printf("Cor principal ->%s<-\n", lista[p].cor_principal);
        printf("Cor secundária ->%s<-\n\n\n", lista[p].cor_secundaria);
    }
}


int main(){
    char string[1000] = "&H00FFFFFF";
    int *N = malloc(sizeof(int));
    *N = 0;
    ESTILO lista[30];
    while (fgets(string, 1000, stdin) != NULL){
        copia_estilo(string,lista,N);
    }
    print_estilos(lista,*N);

    correcao_cores(lista,*N);
    
    print_estilos(lista,*N);
    


    return 0;
}