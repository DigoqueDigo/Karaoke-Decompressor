#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "CleanTags.h"


int found_indice(char *string){
    int p;
    for (p = 0; string[p] != '{'; p++){
        if (string[p] == '\n' || string[p] == '\0') return -1; 
    }
//    printf("inicio -> %d\n", p);
    return p;
}


int found_next(char *string, int x){
    int n = x+1;
    for (; string[n] != '}'; n++);
//    printf("fim -> %d\n", n);
    return n;
}


void remove_tag(char *string, int start, int end){
    int dif = end-start+1;
    for (; string[start+dif] != '\0' && string[start+dif] != '\n' ;start++){
        string[start] = string[start+dif];
    }
    string[start] = '\0';
}


void clean_string(char *string){
    int x, y;
    while (found_indice(string) != -1){
        x = found_indice(string);
        y = found_next(string,x);
        remove_tag(string,x,y);
    }
}