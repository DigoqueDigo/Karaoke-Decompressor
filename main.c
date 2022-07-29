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
    char string[1000];
    if (fgets(string, 1000, stdin) != NULL){
        clean_string(string);
    }
    printf("->%s<-\n", string);
    


    return 0;
}