#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "CleanTags.h"
#include "Tempo.h"


void print_times(int times[], int N){
    printf("elementos: %d\n", N);
    for (int p = 0; p < N; p++) printf("%d -> ", times[p]);
    putchar('\n');
}



int main(){
    
    /*int times[100], *N = malloc(sizeof(int));
    char string[1000];
    *N = 0;
    if (fgets(string, 1000, stdin) != NULL){
        copy_all_times(string,times,N);
        print_times(times,*N);
    }
    soma_tempos_lista(times,*N);
    print_times(times,*N);*/

    char time[20] = "0:30:59.77";
    printf("->%s<-\n", time);
    soma_tempo(time,130);
    printf("->%s<-\n", time);
    return 0;
}