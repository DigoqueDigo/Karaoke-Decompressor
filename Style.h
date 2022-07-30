#ifndef STYLE_H
#define STYLE_H
#pragma once

/**
\file CleanTags.h
\brief Funções relativas aos estilos
*/


typedef struct{
    char estilo[40];
    char cor_principal[40];
    char cor_secundaria[40];
}ESTILO;


typedef struct linha{
    char line[2000];
    struct linha *prox;
}*LINHA;


void copia_estilo(char *string, ESTILO lista[], int *N);

void prefixo_sufixo_principal(char *string);

void prefixo_sufixo_secundaria(char *string);

void correcao_cores(ESTILO lista[], int N);

void creat_line(char *line, char *etilo, char *strat_time, char *end_time, char *content);

void push(LINHA *final_list, char *string);


#endif