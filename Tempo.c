#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "CleanTags.h"
#include "Tempo.h"


void soma_tempo(char *string, int x){
    for (int p = 0; p < x; p++){
        int n = strlen(string)-1;
        for (int k = n; k >= 0; k--){
            if (string[k] == '5' && (k == n-4 || k == n-7)) string[k] = '0';
            else if (string[k] != '9' && string[k] != ':' && string[k] != '.'){
                string[k]++;
                k = -1;
            }
            else if (string[k] != ':' && string[k] != '.') string[k] = '0';
        }
    }
}


void found_times(char *string, char *star_time, char *end_time){
    if (string[0] != 'D') return;
    int p, i;
    for (p = 0; string[p] != ','; p++);
    p++;
    for (i = 0; string[p] != ','; p++, i++){
        star_time[i] = string[p];
    }
    star_time[i] = '\0';
    p++;
    for (i = 0; string[p] != ','; p++, i++){
        end_time[i] = string[p];
    }
    end_time[i] = '\0';
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


void copy_all_times(char *string, int times[], int *N){
    while(found_indice(string) != -1){
        int inicio = found_indice(string);
        int fim = found_next(string,inicio);
        copy_times_from_tag(string,inicio,fim,times,N);
    }
}