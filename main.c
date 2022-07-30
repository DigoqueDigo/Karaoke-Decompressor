#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "CleanTags.h"
#include "Tempo.h"
#include "Position.h"
#include "Style.h"


// Imprime um array

void print_array(int array[], int N){
    printf("elementos: %d\n", N);
    for (int p = 0; p < N; p++){
        if (p == N-1) printf("%d\n", array[p]);
        else printf("%d -> ", array[p]);
    }
}

// Imprime o array dos estilos

void print_estilos(ESTILO lista[], int N){
    for (int p = 0; p < N; p++){
        printf("Estilo ->%s<-\n", lista[p].estilo);
        printf("Cor principal ->%s<-\n", lista[p].cor_principal);
        printf("Cor secundária ->%s<-\n\n\n", lista[p].cor_secundaria);
    }
}

// Imprime as linhas de output (lista ligada) 

void print_final_lines(LINHA lista){
    for (; lista != NULL; lista = lista->prox){
        printf("->%s<-\n", lista->line);
    }
}


int main(){
    LINHA *final_lines = malloc(sizeof(8));
    /*char string[10000] = "&H00FFFFFF";
    int *N = malloc(sizeof(int));
    *N = 0;
    ESTILO lista[50];
    while (fgets(string, 10000, stdin) != NULL){

        // Copiar todos os estilos para o array dos estilos

        if (strstr(string,"Style") != NULL){
            copia_estilo(string,lista,N);
            correcao_cores(lista,*N);
        }


    } 
    
    print_estilos(lista,*N);
    */




    return 0;
}