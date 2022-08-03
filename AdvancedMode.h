#ifndef ADVANCEDMODE_H
#define ADVANCEDMODE_H
#pragma once


/** \mainpage Documentação
 * 
 * Bem-vindo à página da documentação deste mini projeto, caso queiras compreender
 * melhor como tudo isto funciona está no sítio certo.\n\n
 * </em>Quem diria que este script teria origem numa pequena conversa no Discord.</em>
 */


/**
\file AdvancedMode.h
\brief Funções relativas ao modo avançado
*/


/*!
 * @brief Struct para a representação de um time break
 * 
 * Armazena os tempos de mudança fornecidos pelo user
 */
typedef struct tempos{
    char tempo[40]; ///< tempo fornecido pelo user
}TEMPOS;


/*!
 * @brief Struct para a representação de estilos
 * 
 * Armazena os estilos fornecidos pelo user no AdvancedMode
 */
typedef struct link_estilos{
    char estilo[50]; ///< estilo fornecido pelo user
    struct link_estilos *prox; ///< apontador para o próximo estilo, caso não exista fica igual a NULL
}*LINK_ESTILOS;


/**
 * @brief Guarda os estilos fornecidos pelo user no AdvancedMode
 * 
 * @param lista lista ligada na qual serão guardados os estilos 
 * @param string estilo que será guardado na lista ligada
 */
void push_estilo(LINK_ESTILOS *lista, char *string);


/**
 * @brief Guarda os tempos de mudança fornecidos pelo user no AdvancedMode
 * 
 * @param lista lista de TEMPOS na qual serão guadados os tempos de mudança
 * @param string tempo de mudança a ser guardado
 * @param indice indicador da celula onde será guardado o tempo de mudança
 */
void push_tempo(TEMPOS lista[], char *string, int indice);


/**
 * @brief Recolhe o estilos e tempos de mudança e guarda-os
 * 
 * @param lista_estilos lista ligada na qual serão armazenados os estilos
 * @param lista_tempos lista na qual serão armazenados os tempos de mudança
 * @param N número de tempos de mudança em causa
 * @return retorna -1 como codigo de erro, caso tenha conseguido obter a informação desejada retorn 0
 */
int recolhe_data(LINK_ESTILOS *lista_estilos, TEMPOS lista_tempos[], int N);


/**
 * @brief Coloca num array as posições corretas dos estilos de forma a que fiquem ordenados segundo a ordem do user
 * 
 * @param lista_estilos lista ligada com os estilos fornecidos pelo user (estilos ordenados)
 * @param lista lista que contem todas as informação relativas a um estilo (estilos desordenados)
 * @param vetor array no qual serão guardadas as posiçoes corretas dos estilos
 * @param N_lista número de elementos da lista dos estilos desordenados 
 */
void posicoes_estilos(LINK_ESTILOS *lista_estilos, ESTILO lista[], int vetor[], int N_lista);


/**
 * @brief Substitui parte de informação de um worker
 * 
 * @param base worker cuja informação será alterada
 * @param estilo informação que se pretende colocar no worker
 */
void replace_worker(WORKER *base, ESTILO estilo);


/**
 * @brief Primeira função auxiliar da handle
 * 
 * @param output lista ligada na qual são guadadas as linhas de output
 * @param base worker a partir do qual as linhas de output serão trabalhadas
 * @param tempos lista que contem os tempos de mudança
 * @param lista lista que contem todas as informações dos estilos
 * @param vetor array que contem as posições ordenadas dos estilos
 * @param indice_estilos indice utilizado na escolha dos tempos de mudança
 * @param indice_posicoes indice utilizado na escolha dos estilos
 * @param N número total de tempos de mudança
 */
void advanced_mode(LINHA *output, WORKER base, TEMPOS tempos[], ESTILO lista[], int vetor[], int *indice_estilos, int *indice_posicoes, int N);


#endif