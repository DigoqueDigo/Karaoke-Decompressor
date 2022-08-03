#ifndef SIMPLEMODE_H
#define SIMPLEMODE_H
#pragma once


/**
\file SimpleMode.h
\brief Funções relativas ao modo simples
*/


/**
 * @brief Criação das linhas de output no SimpleMode
 * 
 * @param output_lista lista ligada na qual são armazenadas as linhas de output
 * @param base worker a partir do qual serão trabalhadas as linhas de output
 */
void simple_mode(LINHA *output_list, WORKER base);


#endif