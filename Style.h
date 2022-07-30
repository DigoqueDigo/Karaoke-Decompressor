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


void copia_estilo(char *string, ESTILO lista[], int *N);

void prefixo_sufixo_principal(char *string);

void prefixo_sufixo_secundaria(char *string);

void correcao_cores(ESTILO lista[], int N);


#endif