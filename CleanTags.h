#ifndef CLEANTAGS_H
#define CLEANTAGS_H
#pragma once

/**
\file CleanTags.h
\brief Funções relativas à remoção de tags de Karaoke
*/

/**
 * @brief Calcula o indice do primeiro caractere '{'
 * 
 * @param string string com tags de karaoke
 * @return o indice do caractere
 */
int found_indice(char *string);


/**
 * @brief Calcula o indice do primeiro caractere '}'
 * 
 * @param string string com tags de karaoke
 * @return o inidice do caractere
 */
int found_next(char *string, int x);


/**
 * @brief Remoção de uma tag
 * 
 * @param string string com tags de karaoke
 * @param start indice do caractere '{'
 * @param end indice do caractere '}'
 */
void remove_tag(char *string, int start, int end);


/**
 * @brief Remoção de todas as tags de Karaoke
 * 
 * @param string string com tags de karaoke
 */
void clean_string(char *string);


int string_to_int (char *string);

void copy_times_from_tag(char *string, int start, int end, int times[], int *N);

void copy_all_times(char *string, int times[], int *N);


#endif