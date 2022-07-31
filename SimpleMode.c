#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "CleanTags.h"
#include "Tempo.h"
#include "Position.h"
#include "Style.h"
#include "SimpleMode.h"



void simple_mode(LINHA *output_list, WORKER base){
    int tamanho = strlen(base.content);
    char aux_content[500], line[1000];
    strcpy(aux_content,base.content);
    for (int p = 0; p < *(base.N_posicoes) && base.posicoes[p] != tamanho; p++){

        soma_tempo(base.tempo_atual,base.tempos[p]);
        insere_tag(aux_content,base.cor_s,base.posicoes[p]);
        insere_tag(aux_content,base.cor_p,0);


        creat_line(line,base.estilo,base.tempo_inicial,base.tempo_atual,aux_content);
        
        push(output_list,line);
        strcpy(aux_content,base.content);
        soma_tempo(base.tempo_inicial,base.tempos[p]);
    }
    
    creat_line(line,base.estilo,base.tempo_atual,base.tempo_final,aux_content);
    push(output_list,line);
}