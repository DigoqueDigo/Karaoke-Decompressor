#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "Tempo.h"

// time exemple -> 0:00:00.00

void soma_tempos_lista(int times[], int N){
    int acc = 0;
    for (int p = 0; p < N; p++){
        acc += times[p];
        times[p] = acc;
    }
}


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


// dont need a replace times in string, causa i already have creat line