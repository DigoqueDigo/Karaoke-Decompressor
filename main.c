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
#include "Printer.h"



int main(){
    char string[10000];
    int array[10], modo;
    int *N_lista = malloc(sizeof(int));
    int *indice_posicoes = malloc(8);
    int *indice_tempos = malloc(8);
    TEMPOS lista_tempos[50];
    LINK_ESTILOS *link_estilos = malloc(8);
    LINHA *final_lines = malloc(sizeof(8));
    WORKER base;
    *N_lista = *indice_posicoes = *indice_tempos = 0;
    ESTILO lista[50];
    
    printf("Escolhe um dos seguintes modos:\n\nModo Simples -> 1\nModo Avançado -> 2\n\nOpção: ");

    if (scanf("%d", &modo) != 1) return -1;

    if (modo == 1){

        printf("\nInsere as linhas dos estilos e as de karaoke respetivamente\n\n");

        while (fgets(string, 10000, stdin) != NULL){

            if (strstr(string,"Style") != NULL){
                copia_estilo(string,lista,N_lista);
                correcao_cores(lista,*N_lista);
            }

            else if (strstr(string,"Dialogue") != NULL){
                init_worker(&base,string,lista,*N_lista);
                simple_mode(final_lines,base);
            }
        }
    }

    else if (modo == 2){

        recolhe_data(link_estilos,lista_tempos,modo);

        while (fgets(string, 10000, stdin) != NULL){

            if (strstr(string,"Style") != NULL){
                copia_estilo(string,lista,N_lista);
                correcao_cores(lista,*N_lista);
            }

            else if (strstr(string,"Dialogue") != NULL){
                init_worker(&base,string,lista,*N_lista);
                advanced_mode(final_lines,base,lista_tempos,lista,array,indice_posicoes,indice_tempos,modo);
            }

            else posicoes_estilos(link_estilos,lista,array,*N_lista);
        }
    }

    printf("NOVAS LINHAS DE KARAOKE:\n\n");

    print_final_lines(*final_lines);


    for (LINHA temp; *final_lines != NULL;){
        temp = *final_lines;
        final_lines = &((*final_lines)->prox);
        free(temp);
    }

    for (LINK_ESTILOS temp; *link_estilos != NULL;){
        temp = *link_estilos;
        link_estilos = &((*link_estilos)->prox);
        free(temp);
    }

    return 0;
}