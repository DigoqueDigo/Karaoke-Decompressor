#ifndef CLEANTAGS_H
#define CLEANTAGS_H
#pragma once

/**
\file CleanTags.h
\brief Funções relativas à remoção de tags de Karaoke
*/

int found_indice(char *string);

int found_next(char *string, int x);

void puxa_atras(char *string, int inicio);

void clean_string(char *string);

int string_to_int (char *string);

void copy_times_from_tag(char *string, int start, int end, int times[], int *N);

void copy_all_times(char *string, int times[], int *N);


#endif