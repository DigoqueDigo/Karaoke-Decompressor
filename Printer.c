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
#include "Printer.h"



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