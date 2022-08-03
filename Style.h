#ifndef STYLE_H
#define STYLE_H
#pragma once


/**
\file Style.h
\brief Funções relativas aos estilos
*/


/*!
 * @brief Struct para a representação de um estilos
 * 
 * Armazena informações relativa a um estilo
 */
typedef struct{
    char estilo[60]; ///< string que contem o nome do estilo
    char cor_principal[40]; ///< string que contem a cor princial do estilo (é inútil, by default o aegisub coloca a cor principal)
    char cor_secundaria[40]; ///< string que contem a cor secundária do estilo
}ESTILO;


/*!
 * @brief Struct para a representação da linhas resultantes
 * 
 * Armazena cada linha resultante criada por ciclo
 */
typedef struct linha{
    char line[1000]; ///< string que contem a linha resultante
    struct linha *prox; ///< pointer para uma nova linha
}*LINHA;


/*!
 * @brief Struct para a representação de um worker
 * 
 * Armazena dados relativos a uma linha (estilo, cores, tempos, frase original)
 */
typedef struct worker{
    char estilo[60]; ///< string que contem o estilo aplicado
    char cor_p[40]; ///< string que contem a cor principal
    char cor_s[40]; ///< string que contem a cor secundária
    char tempo_inicial[40]; ///< string que contem o tempo inicial do karaoke
    char tempo_final[40]; ///< string que contem o tempo final do karaoke
    char tempo_atual[40]; ///< string que contem o tempo final de uma mudança de cor
    int posicoes[100]; ///< array que contem as posições onde serão inseridas as tags
    int *N_posicoes; ///< comprimento do array das posições
    int tempos[100]; ///< array que contem o tempos com a duração da mudança de cada cor
    int *N_tempos; ///< tamanho do array dos tempos
    char content[500]; ///< string apenas com a frase de karaoke
}WORKER;


/**
 * @brief Passar a informação de uma linha de estilo para um array
 * 
 * @param string linha de estilo da qual serão retirada informações
 * @param lista array para o qual a informação será passada
 * @param N indice que indica o número de elementos do array de estilos 
 */
void copia_estilo(char *string, ESTILO lista[], int *N);


/**
 * @brief Correção de uma tags de cor
 * 
 * @param string string que contem um cor e será corrigida de forma a criar uma tag
 */
void prefixo_sufixo_principal(char *string);


/**
 * @brief Aplicação da criação de tag de cor a todas os estilos de um array
 * 
 * @param lista array no qual as tags de cor serão criadas
 * @param N tamanho do array
 */
void correcao_cores(ESTILO lista[], int N);


/**
 * @brief Junção de string para a criação de uma linha final, ou seja, linha resultante do script
 * 
 * @param line linha resultante do script
 * @param etilo string com o estilo a ser aplicado na linha
 * @param strat_time string com o tempo inicial de uma linha no aegisub 
 * @param end_time string com o tempo final de uma linha no aegisub
 * @param content string com a frase original e tags inseridas 
 */
void creat_line(char *line, char *etilo, char *strat_time, char *end_time, char *content);


/**
 * @brief Colocar uma linha resultante na lista ligada das linhas resultantes
 * 
 * @param final_list lista ligada que armazena as linhas resultantes do script
 * @param string linha resultante que será colocada na lista ligada 
 */
void push(LINHA *final_list, char *string);


/**
 * @brief Encontrar a posição de um estilo num array de estilos
 * 
 * @param lista array no qual será procurado um determinado estilo
 * @param N tamanho do array de estilos
 * @param string estilo procurado no array
 * @return indice do estilo
 */
int found_estilo(ESTILO lista[], int N, char *string);


/**
 * @brief Inicialização de um worker
 * 
 * @param base pointer para um worker no qual será colocada toda a informação para a criação das linhas resultantes
 * @param string string correspondente a uma linha de karaoke bruta
 * @param lista array com informações relativas aos estilos
 * @param N comprimento da lista de estilos
 */
void init_worker(WORKER *base, char *string, ESTILO lista[], int N);


#endif