#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "CleanTags.h"


void print_times(int times[], int N){
    printf("elementos: %d\n", N);
    for (int p = 0; p < N; p++) printf("%d -> ", times[p]);
    putchar('\n');
}



int main(){
    int times[100], *N = malloc(sizeof(int));
    char string[1000];
    *N = 0;
    if (fgets(string, 1000, stdin) != NULL){
        copy_all_times(string,times,N);
        print_times(times,*N);
    }

    return 0;
}