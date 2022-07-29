#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "CleanTags.h"
#include "Tempo.h"
#include "Position.h"


void print_array(int array[], int N){
    printf("elementos: %d\n", N);
    for (int p = 0; p < N; p++){
        if (p == N-1) printf("%d\n", array[p]);
        else printf("%d -> ", array[p]);
    }
}



int main(){
    char string[1000];
    int array[100], *N = malloc(sizeof(int));
    *N = 0;
    if (fgets(string, 1000, stdin) != NULL){
        remove_dialogue(string);
        printf("->%s<-\n\n\n", string);
        copy_position(string,array,N);
        print_array(array,*N);
    }
    


    return 0;
}