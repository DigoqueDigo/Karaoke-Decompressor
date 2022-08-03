#ifndef PRINTER_H
#define PRINTER_H
#pragma once


/**
\file Printer.h
\brief Funções relativas a prints 
*/


/**
 * @brief Representação de um array no terminal
 * 
 * @param array array que será representado no terminal
 * @param N tamanho do array
 */
void print_array(int array[], int N);


/**
 * @brief Representação de um array de estilos do terminal
 * 
 * @param lista array de estilos que será representado
 * @param N tamanho do array 
 */
void print_estilos(ESTILO lista[], int N);


/**
 * @brief Representação de uma lista ligada que contem as linhas resultantes do script
 * 
 * @param lista lista ligada que será representada
 */
void print_final_lines(LINHA lista);


/**
 * @brief Representação de uma lista ligada que contem estilos
 * 
 * @param lista lista ligada que contem os estilo a serem representados no terminal
 */
void print_estilos_advanced(LINK_ESTILOS lista);


/**
 * @brief Representação de um array de tempos
 * 
 * @param lista array que contem os tempos fornecidos pelo user
 * @param N tamanho do array
 */
void print_tempos_advanced(TEMPOS lista[], int N);


/**
 * @brief Representação do conteudo de um worker no terminal
 * 
 * @param base worker que se pretende representar
 */
void print_worker(WORKER base);


#endif