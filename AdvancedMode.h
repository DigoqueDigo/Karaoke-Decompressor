#ifndef ADVANCEDMODE_H
#define ADVANCEDMODE_H
#pragma once

/**
\file AdvancedMode.h
\brief Funções relativas ao modo avançado
*/


typedef struct tempos{
    char tempo[40];
}TEMPOS;

typedef struct link_estilos{
    char estilo[50];
    struct link_estilos *prox;
}*LINK_ESTILOS;



void push_estilo(LINK_ESTILOS *lista, char *string);

void push_tempo(TEMPOS lista[], char *string, int indice);

int recolhe_data(LINK_ESTILOS *lista_estilos, TEMPOS lista_tempos[], int N);

void posicoes_estilos(LINK_ESTILOS *lista_estilos, ESTILO lista[], int vetor[], int N_lista);

void replace_worker(WORKER *base, ESTILO estilo);

void advanced_mode(LINHA *output, WORKER base, TEMPOS tempos[], ESTILO lista[], int vetor[], int *indice_estilos, int *indice_posicoes, int N);

void print_worker(WORKER base);

#endif