#ifndef PRINTER_H
#define PRINTER_H
#pragma once


/**
\file Printer.h
\brief Funções relativas a prints 
*/

void print_array(int array[], int N);

void print_estilos(ESTILO lista[], int N);

void print_final_lines(LINHA lista);

void print_estilos_advanced(LINK_ESTILOS lista);

void print_tempos_advanced(TEMPOS lista[], int N);

void print_worker(WORKER base);


#endif