#ifndef POSITION_H
#define POSITION_H
#pragma once


/**
\file Position.h
\brief Funções relativas à posição das tags
*/


/**
 * @brief Armazenamento das posições das tags num array
 * 
 * @param string string que contem as tags de karaoke
 * @param estilo array no qual serão armazenadas as posições das tags
 * @param N no fim da função este pointer estará a apontar a um int que representa o temanho do array
 */
void copy_position(char *string, int array[], int *N);


#endif