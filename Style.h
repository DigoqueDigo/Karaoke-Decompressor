#ifndef STYLE_H
#define STYLE_H
#pragma once

/**
\file Style.h
\brief Funções relativas aos estilos
*/


typedef struct{
    char estilo[60];
    char cor_principal[40];
    char cor_secundaria[40];
}ESTILO;


typedef struct linha{
    char line[1000];
    struct linha *prox;
}*LINHA;


typedef struct worker{
    char estilo[60];
    char cor_p[40];
    char cor_s[40];
    char tempo_inicial[40];  //
    char tempo_final[40];  //
    char tempo_atual[40];  //
    int posicoes[100]; //
    int *N_posicoes;  //
    int tempos[100]; //
    int *N_tempos;  //
    char content[500]; // frase sem as tags
}WORKER;


void copia_estilo(char *string, ESTILO lista[], int *N);

void prefixo_sufixo_principal(char *string);

void correcao_cores(ESTILO lista[], int N);

void creat_line(char *line, char *etilo, char *strat_time, char *end_time, char *content);

void push(LINHA *final_list, char *string);

int found_estilo(ESTILO lista[], int N, char *string);

void init_worker(WORKER *base, char *string, ESTILO lista[], int N);

#endif