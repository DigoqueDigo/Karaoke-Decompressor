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


void print_worker(WORKER base){
    printf("estilo: ->%s<-\n", base.estilo);
    printf("Cp: ->%s<-\n", base.cor_p);
    printf("Cs: ->%s<-\n", base.cor_s);
    printf("T_i: ->%s<-\n", base.tempo_inicial);
    printf("T_f: ->%s<-\n", base.tempo_final);
    printf("T_a: ->%s<-\n", base.tempo_atual);
    printf("N_t ->%s<-\n", base.content);
    for (int p = 0; p < *(base.N_tempos); p++) printf("%d -> ", base.tempos[p]);
    putchar('\n');
    printf("T: %d\n", *(base.N_tempos));
    for (int p = 0; p < *(base.N_posicoes); p++) printf("%d -> ", base.posicoes[p]);
    putchar('\n');
    printf("P: %d\n", *(base.N_posicoes));
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

void print_tempos_advanced(LINK_TEMPOS lista){
    for (; lista != NULL; lista = lista->prox){
        printf("tempos ->%s<-\n", lista->tempo);
    }
}


int main(){
    int array[10];// posições dos estilos
    LINK_TEMPOS *link_tempos = malloc(8);
    LINK_ESTILOS *link_estilos = malloc(8);
    LINHA *final_lines = malloc(sizeof(8)), temp;
    WORKER base;
    char string[10000];
    int *N_lista = malloc(sizeof(int));
    int *indice = malloc(8);
    *N_lista = *indice = 0;
    ESTILO lista[50];
    recolhe_data(link_estilos,link_tempos,3);
    while (fgets(string, 10000, stdin) != NULL){

        // Copiar todos os estilos para o array dos estilos

        if (strstr(string,"Style") != NULL){
            copia_estilo(string,lista,N_lista);
            correcao_cores(lista,*N_lista);
        }

        else if (strstr(string,"Dialogue") != NULL){
            //found_times(string,init,last);
            init_worker(&base,string,lista,*N_lista);
            advanced_mode(final_lines,base,*link_tempos,lista,array,indice);
        }

        else posicoes_estilos(link_estilos,lista,array,*N_lista);
    }

   // print_estilos(lista,*N_lista);
   // print_estilos_advanced(*link_estilos);
   // posicoes_estilos(link_estilos,lista,array,7);

    print_array(array,4);
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