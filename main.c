#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "CleanTags.h"
#include "Tempo.h"
#include "Position.h"
#include "Style.h"
#include "SimpleMode.h"
#include "AdvancedMode.h"


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
        printf("%s\n", lista->line);
    }
}

void print_estilos_advanced(LINK_ESTILOS lista){
    for (; lista != NULL; lista = lista->prox){
        printf("estilo ->%s<-\n", lista->estilo);
    }
}

void print_tempos_advanced(TEMPOS lista[], int N){
    for (int p = 0; p < N; p++){
        printf("tempos ->%s<-\n", lista[p].tempo);
    }
}


int main(){
    int array[10];// posições dos estilos
    TEMPOS lista_tempos[50];
    LINK_ESTILOS *link_estilos = malloc(8);
    LINHA *final_lines = malloc(sizeof(8)), temp;
    WORKER base;
    char string[10000];
    int *N_lista = malloc(sizeof(int));
    int *indice_posicoes = malloc(8);
    int *indice_tempos = malloc(8);
    *N_lista = *indice_posicoes = *indice_tempos = 0;
    ESTILO lista[50];
    recolhe_data(link_estilos,lista_tempos,3);
    while (fgets(string, 10000, stdin) != NULL){

        // Copiar todos os estilos para o array dos estilos

        if (strstr(string,"Style") != NULL){
            copia_estilo(string,lista,N_lista);
            correcao_cores(lista,*N_lista);
        }

        else if (strstr(string,"Dialogue") != NULL){
            //found_times(string,init,last);
            init_worker(&base,string,lista,*N_lista);
            advanced_mode(final_lines,base,lista_tempos,lista,array,indice_posicoes,indice_tempos,3);
        }

        else posicoes_estilos(link_estilos,lista,array,*N_lista);
    }

  //  print_estilos(lista,*N_lista);
  //  print_estilos_advanced(*link_estilos);

  //  print_array(array,4);
  //  print_tempos_advanced(lista_tempos,3);


   // posicoes_estilos(estilos,lista,array,*N_lista);
   // for (int p = 0; p < 4; p++) printf("P: %d\n", array[p]);

   // printf("init: ->%s<-\n", init);
   // printf("last: ->%s<-\n", last);
    
   // print_worker(base);

   // creat_line(line,base.estilo,base.tempo_inicial,base.tempo_final,base.content);

   // push(final_lines,line);

    print_final_lines(*final_lines);


    while(*final_lines != NULL){
        temp = *final_lines;
        final_lines = &((*final_lines)->prox);
        free(temp);
    }

   // print_estilos_advanced(*estilos);
   // print_tempos_advanced(*tempos);






    return 0;
}