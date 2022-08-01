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
    printf("Começa por indicar os tempos (um por linha), os tempos devem estar na forma x:xx:xx.xx\n\n");
    for (int p = 0; p < N; p++){
        if (scanf("%s", aux) != 1) return -1;
        push_tempo(lista_tempos,aux,p);
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

void print_worker(WORKER base){
    printf("estilo: ->%s<-\n", base.estilo);
    printf("Cp: ->%s<-\n", base.cor_p);
    printf("Cs: ->%s<-\n", base.cor_s);
    printf("T_i: ->%s<-\n", base.tempo_inicial);
    printf("T_f: ->%s<-\n", base.tempo_final);
    printf("T_a: ->%s<-\n", base.tempo_atual);
    printf("N_t ->%s<-\n", base.content);
    for (int p = 0; p < *(base.N_tempos); p++) printf("%d -> ", base.tempos[p]);
    putchar('\n');
    printf("T: %d\n", *(base.N_tempos));
    for (int p = 0; p < *(base.N_posicoes); p++) printf("%d -> ", base.posicoes[p]);
    putchar('\n');
    printf("P: %d\n", *(base.N_posicoes));
}


// output -> lista com o output
// worker
// tempos -> array com os tempos de sepraração
// lista -> lista dos estilos
// array -> lista com a posiçoes corretas para a subtituição
// indice das posicoes
// indice dos tempos
// tamanho do vetor dos tempos

void advanced_mode(LINHA *output, WORKER base, TEMPOS tempos[], ESTILO lista[], int vetor[], int *indice_posicoes, int *indice_tempos, int N){
    //int ant = 0;
    char line[1000], aux_content[500], aux_tempo[50];
    strcpy(aux_content,base.content);
    strcpy(aux_tempo,base.tempo_inicial);
    print_worker(base);
    replace_worker(&base,lista[vetor[*indice_posicoes++]]);
    print_worker(base);
    for (int p = 0; p < *(base.N_posicoes); strcpy(aux_content,base.content), strcpy(base.tempo_inicial,base.tempo_atual), p++){
        
        soma_tempo(aux_tempo,base.tempos[p]);
        printf("aux_tempo:::::::: ->%s<-\n\n\n", aux_tempo);
        replace_worker(&base,lista[vetor[*indice_posicoes]]);
        int a = strcmp(aux_tempo,tempos[*indice_tempos].tempo);

        
        if (*indice_tempos < N && a > 0){
            
            
            strcpy(base.tempo_atual,tempos[*indice_tempos].tempo);
            ++*indice_tempos;
            ++*indice_posicoes;
            
            
            insere_tag(aux_content,base.cor_s,base.posicoes[p]);
            creat_line(line,base.estilo,base.tempo_inicial,base.tempo_atual,aux_content);
            push(output,line);
            strcpy(aux_content,base.content);


            strcpy(base.tempo_inicial,base.tempo_atual);
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