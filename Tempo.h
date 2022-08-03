#ifndef TEMPO_H
#define TEMPO_H
#pragma once


/**
\file Tempo.h
\brief Funções relativas ao tempo das linhas
*/


/**
 * @brief Soma de tempos
 * 
 * @param string string que contem um tempo na forma x:xx:xx.xx
 * @param x tempo que se pretende adicionar à string
 */
void soma_tempo(char *string, int x);


/**
 * @brief Procura o tempo de inicial e final de uma linha de karaoke
 * 
 * @param string string que corresponde a uma linha de karaoke
 * @param strat_time string na qual será guardado o tempo inicial
 * @param end_time string na qual será guardado o tempo final
 */
void found_times(char *string, char *star_time, char *end_time);


/**
 * @brief Armazena o tempo de uma tag de karaoke numa lista
 * 
 * @param string string que corresponde a uma linha de karaoke
 * @param strat indice do inicio da tag
 * @param end indice do final da tag
 * @param times lista no qual será guardado o tempo da tag
 * @param N indice que indica o número de elementos da lista times
 */
void copy_times_from_tag(char *string, int start, int end, int times[], int *N);


/**
 * @brief Armazena todos os tempos das tags de karaoke numa lista
 * 
 * @param string string que corresponde a uma linha de karaoke
 * @param times lista na qual são guadados os tempos de karaoke
 * @param N inteiro que indica o número de elementos da lista times
 */
void copy_all_times(char *string, int times[], int *N);


#endif