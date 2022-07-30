#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Style.h"



void copia_estilo(char *string, ESTILO lista[], int *N){
    if (string[0] != 'S') return;
    int acc = 0, p = 7;
    for (; string[p] != ','; p++, acc++){
        lista[*N].estilo[acc] = string[p];
    }
    lista[*N].estilo[acc] = '\0';
    for (int i = 0; i < 3; p++){
        if (string[p] == ',') i++;
    }
    for (acc = 0; string[p] != ','; p++, acc++){
        lista[*N].cor_principal[acc] = string[p];
    }
    p++;
    lista[*N].cor_principal[acc] = '\0';
    for (acc = 0; string[p] != ','; p++, acc++){
        lista[*N].cor_secundaria[acc] = string[p];
    }
    ++*N;
}


void prefixo_sufixo_principal(char *string){
    char aux[40];
    int tamanho;
    strcpy(aux,string);
    string[0] = '{'; string[1] = '\\'; string[2] = 'c'; string[3] = '\0';
    strcat(string,aux);
    tamanho = strlen(string);
    string[tamanho++] = '}'; string[tamanho] = '\0';
}

void prefixo_sufixo_secundaria(char *string){
    char aux[40];
    int tamanho;
    strcpy(aux,string);
    string[0] = '{'; string[1] = '\\'; string[2] = '2'; string[3] = 'c'; string[4] = '\0';
    strcat(string,aux);
    tamanho = strlen(string);
    string[tamanho++] = '}'; string[tamanho] = '\0';
}


void correcao_cores(ESTILO lista[], int N){
    for (int p = 0; p < N; p++){
        if (lista[p].cor_principal[0] != '{'){
            prefixo_sufixo_principal(lista[p].cor_principal);
            prefixo_sufixo_secundaria(lista[p].cor_secundaria);
        }
    }
}


void creat_line(char *line, char *etilo, char *strat_time, char *end_time, char *content){
    line[0] = '\0';
    strcat(line,"Dialogue: 0,");
    strcat(line,strat_time);
    strcat(line,",");
    strcat(line,end_time);
    strcat(line,",");
    strcat(line,etilo);
    strcat(line,",,0,0,0,,");
    strcat(line,content);
}


void push(LINHA *final_list, char *string){
    LINHA new = malloc(sizeof(struct linha));
    strcpy(new->line,string);
    new->prox = NULL;
    for (; *final_list != NULL; final_list = &((*final_list)->prox));
    *final_list = new;
}