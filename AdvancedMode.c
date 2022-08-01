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

void push_tempo(LINK_TEMPOS *lista, char *string){
    LINK_TEMPOS new = malloc(sizeof(struct link_tempos));
    strcpy(new->tempo,string);
    new->prox = NULL;
    for (; *lista != NULL; lista = &((*lista)->prox));
    *lista = new;
}


// p indica o numero de mudanças de cor que serão efetuadas
// retorna -1 se não conseguiu ler a informação

int recolhe_data(LINK_ESTILOS *lista_estilos, LINK_TEMPOS *lista_tempos, int N){
    char aux[50];
    printf("Começa por indicar os tempos (um por linha), os tempos devem estar na forma x:xx:xx.xx\n\n");
    for (int p = 0; p < N; p++){
        if (scanf("%s", aux) != 1) return -1;
        push_tempo(lista_tempos,aux);
    }
  //  printf("Indica a ordem correta dos estilos (um por linha)\n");
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


// vetor :: array com as posições corretas
// indice :: indice do vetor das posiçoes

void advanced_mode(LINHA *output, WORKER base, LINK_TEMPOS tempos, ESTILO lista[], int vetor[], int *indice){
    int ant = 0;
    char line[1000], aux_content[500], aux_tempo[50];
    strcpy(aux_content,base.content);
    strcpy(aux_tempo,base.tempo_inicial);
    soma_tempo(aux_tempo,base.tempos[0]);
    replace_worker(&base,lista[vetor[*indice]]);
    for (int p = 0; p < *(base.N_posicoes); strcpy(aux_content,base.content), strcpy(base.tempo_inicial,base.tempo_atual)){

        
        if (ant == 0) soma_tempo(aux_tempo,base.tempos[p]);
        
        
        
        if (tempos != NULL && strcmp(aux_tempo,tempos->tempo) > 0 && ant == 0){
            strcpy(base.tempo_atual,tempos->tempo);

            replace_worker(&base,lista[vetor[*indice]]);

            ++*indice;

            insere_tag(aux_content,base.cor_s,base.posicoes[p]);
            creat_line(line,base.estilo,base.tempo_inicial,base.tempo_atual,aux_content);
            push(output,line);
            tempos = tempos->prox;
            ant = 1;

        }

        else if (tempos != NULL && ant == 1){
            if (strcmp(aux_tempo,tempos->tempo) > 0){
                strcpy(base.tempo_atual,tempos->tempo);
                tempos = tempos->prox;
                replace_worker(&base,lista[vetor[*indice]]);
                ++*indice;
                insere_tag(aux_content,base.cor_s,base.posicoes[p]);
                creat_line(line,base.estilo,base.tempo_inicial,base.tempo_atual,aux_content);
                push(output,line);

            }
            else{
                strcpy(base.tempo_atual,aux_tempo);
                insere_tag(aux_content,base.cor_s,base.posicoes[p]);
                creat_line(line,base.estilo,base.tempo_inicial,base.tempo_atual,aux_content);
                push(output,line);
                p++;
                ant = 0;
            }
        }


        else{
            soma_tempo(base.tempo_atual,base.tempos[p]);
            insere_tag(aux_content,base.cor_s,base.posicoes[p]);

            creat_line(line,base.estilo,base.tempo_inicial,base.tempo_atual,aux_content);

            push(output,line);
            soma_tempo(base.tempo_inicial,base.tempos[p]);
            p++;
            ant = 0;
        }

    }

    creat_line(line,base.estilo,base.tempo_atual,base.tempo_final,aux_content);
    push(output,line);
    printf("indice: %d\n", *indice);
}  