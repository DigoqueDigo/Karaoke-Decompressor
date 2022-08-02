#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "Style.h"
#include "CleanTags.h"
#include "Position.h"
#include "Tempo.h"
#include "SimpleMode.h" 
#include "AdvancedMode.h"


void push_estilo(LINK_ESTILOS *lista, char *string){
    LINK_ESTILOS new = malloc(sizeof(struct link_estilos));
    strcpy(new->estilo,string);
    new->prox = NULL;
    for (; *lista != NULL; lista = &((*lista)->prox));
    *lista = new;
}

void push_tempo(TEMPOS lista[], char *string, int indice){
    strcpy(lista[indice].tempo,string);
}


// p indica o numero de mudanças de cor que serão efetuadas
// retorna -1 se não conseguiu ler a informação

int recolhe_data(LINK_ESTILOS *lista_estilos, TEMPOS lista_tempos[], int N){
    char aux[50];
    printf("\nComeça por indicar os tempos (um por linha), os tempos devem estar na forma x:xx:xx.xx\n\n");
    for (int p = 0; p < N; p++){
        if (scanf("%s", aux) != 1) return -1;
        push_tempo(lista_tempos,aux,p);
    }
    printf("\nIndica a ordem sequencial dos estilos (um por linha)\n");
    for (int p = 0; p <= N; p++){
        if (scanf("%s", aux) != 1) return -1;
        push_estilo(lista_estilos,aux);
    }
    return 0;
}


void posicoes_estilos(LINK_ESTILOS *lista_estilos, ESTILO lista[], int vetor[], int N_lista){
    int N = 0, p = 0;
    for (; *lista_estilos != NULL; lista_estilos = &((*lista_estilos)->prox)){
        for (p = 0; p < N_lista && strcmp((*lista_estilos)->estilo,lista[p].estilo) != 0; p++);
        vetor[N++] = p;
    }
}

void replace_worker(WORKER *base, ESTILO estilo){
    strcpy(base->estilo,estilo.estilo);
    strcpy(base->cor_p,estilo.cor_principal);
    strcpy(base->cor_s,estilo.cor_secundaria);
}


void advanced_mode(LINHA *output, WORKER base, TEMPOS tempos[], ESTILO lista[], int vetor[], int *indice_posicoes, int *indice_tempos, int N){
    char line[1000], aux_content[500], aux_tempo[50];
    strcpy(aux_content,base.content);
    strcpy(aux_tempo,base.tempo_inicial);
    replace_worker(&base,lista[vetor[*indice_posicoes++]]);
    for (int p = 0; p < *(base.N_posicoes); strcpy(aux_content,base.content), strcpy(base.tempo_inicial,base.tempo_atual), p++){ 

        soma_tempo(aux_tempo,base.tempos[p]);
        replace_worker(&base,lista[vetor[*indice_posicoes]]);

        
        if (*indice_tempos < N && strcmp(aux_tempo,tempos[*indice_tempos].tempo) > 0){

            for (; *indice_tempos < N && strcmp(aux_tempo,tempos[*indice_tempos].tempo) > 0; strcpy(aux_content,base.content), strcpy(base.tempo_inicial,base.tempo_atual), ++*indice_tempos, ++*indice_posicoes){
            
                strcpy(base.tempo_atual,tempos[*indice_tempos].tempo);
                replace_worker(&base,lista[vetor[*indice_posicoes]]);


                insere_tag(aux_content,base.cor_s,base.posicoes[p]);
                creat_line(line,base.estilo,base.tempo_inicial,base.tempo_atual,aux_content);
                push(output,line);

            }

            strcpy(base.tempo_atual,aux_tempo);
            replace_worker(&base,lista[vetor[*indice_posicoes]]);
            insere_tag(aux_content,base.cor_s,base.posicoes[p]);
            creat_line(line,base.estilo,base.tempo_inicial,base.tempo_atual,aux_content);
            push(output,line);

        }

        else{

            soma_tempo(base.tempo_atual,base.tempos[p]);
            insere_tag(aux_content,base.cor_s,base.posicoes[p]);

            creat_line(line,base.estilo,base.tempo_inicial,base.tempo_atual,aux_content);
        
            push(output,line);
            strcpy(aux_content,base.content);

        }
        
    }
    creat_line(line,base.estilo,base.tempo_atual,base.tempo_final,aux_content);
    push(output,line);
}