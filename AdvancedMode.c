#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "Style.h"
#include "CleanTags.h"
#include "Position.h"
#include "Tempo.h"
#include "SimpleMode.h" 
#include "AdvancedMode.h"


void push_estilo(LINK_ESTILOS *lista, char *string){
    LINK_ESTILOS new = malloc(sizeof(struct link_estilos));
    strcpy(new->estilo,string);
    new->prox = NULL;
    for (; *lista != NULL; lista = &((*lista)->prox));
    *lista = new;
}

void push_tempo(LINK_TEMPOS *lista, char *string){
    LINK_TEMPOS new = malloc(sizeof(struct link_tempos));
    strcpy(new->tempo,string);
    new->prox = NULL;
    for (; *lista != NULL; lista = &((*lista)->prox));
    *lista = new;
}


// p indica o numero de mudanças de cor que serão efetuadas
// retorna -1 se não conseguiu ler a informação

int recolhe_data(LINK_ESTILOS *lista_estilos, LINK_TEMPOS *lista_tempos, int N){
    char aux[50];
    printf("Começa por indicar os tempos (um por linha), os tempos devem estar na forma x:xx:xx.xx\n\n");
    for (int p = 0; p < N; p++){
        if (scanf("%s", aux) != 1) return -1;
        push_tempo(lista_tempos,aux);
    }
    printf("Indica a ordem correta dos estilos (um por linha)\n");
    for (int p = 0; p <= N; p++){
        if (scanf("%s", aux) != 1) return -1;
        push_estilo(lista_estilos,aux);
    }
    return 0;
}


void posicoes_estilos(LINK_ESTILOS *lista_estilos, ESTILO lista[], int vetor[], int N_lista){
    int N = 0, p = 0;
    for (; *lista_estilos != NULL; lista_estilos = &((*lista_estilos)->prox)){
        for (p = 0; p < N_lista && strcmp((*lista_estilos)->estilo,lista[p].estilo) != 0; p++);
        vetor[N++] = p;
    }
}