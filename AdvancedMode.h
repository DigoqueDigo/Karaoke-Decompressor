#ifndef ADVANCEDMODE_H
#define ADVANCEDMODE_H
#pragma once

/**
\file AdvancedMode.h
\brief Funções relativas ao modo avançado
*/


typedef struct link_tempos{
    char tempo[40];
    struct link_tempos *prox;
}*LINK_TEMPOS;

typedef struct link_estilos{
    char estilo[50];
    struct link_estilos *prox;
}*LINK_ESTILOS;



void push_estilo(LINK_ESTILOS *lista, char *string);

void push_tempo(LINK_TEMPOS *lista, char *string);

int recolhe_data(LINK_ESTILOS *lista_estilos, LINK_TEMPOS *lista_tempos, int N);

void posicoes_estilos(LINK_ESTILOS *lista_estilos, ESTILO lista[], int vetor[], int N_lista);

void replace_worker(WORKER *base, ESTILO estilo);

void advanced_mode(LINHA *output, WORKER base, LINK_TEMPOS tempos, ESTILO lista[], int vetor[], int *indice);

#endif