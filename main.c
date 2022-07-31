#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "CleanTags.h"
#include "Tempo.h"
#include "Position.h"
#include "Style.h"
#include "SimpleMode.h"


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


int main(){
    LINHA *final_lines = malloc(sizeof(8));
    WORKER base;
    char string[10000];
    int *N_lista = malloc(sizeof(int));
    *N_lista = 0;
    ESTILO lista[50];
    while (fgets(string, 10000, stdin) != NULL){

        // Copiar todos os estilos para o array dos estilos

        if (strstr(string,"Style") != NULL){
            copia_estilo(string,lista,N_lista);
            correcao_cores(lista,*N_lista);
        }


        if (strstr(string,"Dialogue") != NULL){
            //found_times(string,init,last);
            init_worker(&base,string,lista,*N_lista);
            simple_mode(final_lines,base);
        }
    }
   // printf("init: ->%s<-\n", init);
   // printf("last: ->%s<-\n", last);
    
   // print_worker(base);

   // creat_line(line,base.estilo,base.tempo_inicial,base.tempo_final,base.content);

   // push(final_lines,line);

    print_final_lines(*final_lines);

    



    return 0;
}