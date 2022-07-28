#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "CleanTags.h"



int main(){
    char string[1000];
    if (fgets(string, 1000, stdin) != NULL){
        clean_string(string);
        printf("->%s<-\n", string);
    }
    return 0;
}