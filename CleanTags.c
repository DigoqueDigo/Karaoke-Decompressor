#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "CleanTags.h"


// Encontrar a string original

int found_indice(char *string){
    int p;
    for (p = 0; string[p] != '{'; p++){
        if (string[p] == '\n' || string[p] == '\0') return -1; 
    }
    return p;
}

int found_next(char *string, int x){
    int n = x+1;
    for (; string[n] != '}'; n++);
    return n;
}

void puxa_atras(char *string, int inicio){
    for (; string[inicio] != '\0'; inicio++){
        string[inicio] = string[inicio+1];
    }
    string[inicio] = '\0';
}

void remove_dialogue(char *string){
    int i;
    for (int p = 0; p < 9;){
        if (string[0] == ',') p++;
        puxa_atras(string,0);
    }
    for (i = 0; string[i] != '\n'; i++);
    string[i] = '\0';
}


void clean_string(char *string){
    int p;
    if (string[0] == 'D') remove_dialogue(string);
    for (p = 0; string[p] != '\n' && string[p] != '\0';){
        if (string[p] == '{'){
            while (string[p] != '}'){
                puxa_atras(string,p);
            }
            puxa_atras(string,p);
        }
        else p++;
    }
    string[p] = '\0';
}


// Inserir uma tag numa string, retorna 1 se a operação foi bem sucedida

int insere_tag(char *string, char *tag, int x){
    int tamanho = strlen(string);
    if (tamanho < x) return 0;
    char aux[1000];
    int acc = 0;
    for (int p = x; string[p] != '\0'; p++, acc++){
        aux[acc] = string[p];
    }
    aux[acc] = '\0';
    for (int p = 0; tag[p] != '\0'; p++, x++){
        string[x] = tag[p];
    }
    for (int p = 0; aux[p] != '\0'; p++, x++){
        string[x] = aux[p];
    }
    string[x] = '\0';
    return 1;
}


// Copiar os tempos das tags para um array

int string_to_int (char *string){
    int acc = 0, n = strlen(string)-1;
    for (int p = 0; string[p] != '\0'; p++, n--){
        int aux = string[p] - '0';
        acc += aux * pow(10,n); 
    }
    return acc;
}

void copy_times_from_tag(char *string, int start, int end, int times[], int *N){
    char tempo[5], aux[1000];
    int p = 0, acc;
    for (start = start+3; start != end; start++, p++){
        tempo[p] = string[start];
    }
    tempo[p] = '\0';
    acc = string_to_int(tempo);
    times[*N] = acc;
    ++*N;
    strcpy(aux,&(string[end+1]));
    strcpy(string,aux);
}

// Funciona com Dialogue

void copy_all_times(char *string, int times[], int *N){
    while(found_indice(string) != -1){
        int inicio = found_indice(string);
        int fim = found_next(string,inicio);
        copy_times_from_tag(string,inicio,fim,times,N);
    }
}