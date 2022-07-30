#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "Position.h"
#include "CleanTags.h"

// É para usar sem Dialogue

void copy_position(char *string, int array[], int *N){
    int ant, acc; // fornece indicações sobre as chavetas 1 -> abertas 0 -> fechadas
    *N = acc = ant = 0;
    //remove_dialogue(string);
    for (int p = 0; string[p] != '\0'; p++){
        if (string[p] == '{'){
            ant = 1;
            array[*N] = acc;
            ++*N;
        } 
        else if (string[p] == '}') ant = 0;
        else if (ant == 0) acc++;
    }
    array[*N] = acc;
    ++*N;
}