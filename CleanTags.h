#ifndef CLEANTAGS_H
#define CLEANTAGS_H
#pragma once


/**
\file CleanTags.h
\brief Funções relativas à remoção de tags de Karaoke
*/


/**
 * @brief Encontra o indice do primeiro caractere '{' que encontrar numa string
 * 
 * @param string string que será analisada
 * @return indice do primeiro caractere '{', caso não exista returna -1 como codigo de erro
 */
int found_indice(char *string);


/**
 * @brief Encontra o indice do primeiro caractere '}' a partir de uma determinada posição
 * 
 * @param string string que será analisada
 * @param x indice a partir da qual a analise da string
 * @return indice do primeiro caractere '}'
 */
int found_next(char *string, int x);


/**
 * @brief Remoção de um caractere de uma string
 * 
 * @param string string da qual será removido um caractere
 * @param inicio indice do caractere que será removido
 */
void puxa_atras(char *string, int inicio);


/**
 * @brief Remoção de parte da informação de uma linha de karaoke (tempos,estilos...)
 * 
 * @param string string da qual será removida parte da informação
 */
void remove_dialogue(char *string);


/**
 * @brief Obtenção do conteudo textual de uma linha de karaoke (frase original)
 * 
 * @param string string da qual será removida informação de modo a que esta represente o conteudo original
 */
void clean_string(char *string);


/**
 * @brief Inserção de uma tag numa string tendo em conta uma determinada posição
 * 
 * @param string string na qual será introduzida uma tag
 * @param tag string que será introduzida
 * @param x indice em que será introduzida a tag
 * @return retorna 1 se conseguiu inserir a tag, caso contrário retorna 0 
 */
int insere_tag(char *string, char *tag, int x);


/**
 * @brief Conversão de um string para inteiro
 * 
 * @param stirng string a partir da qual se obterá um inteiro
 * @return inteiro que corresponde à string
 */
int string_to_int (char *string);


#endif