#ifndef UTILITARIOS_H
#define UTILITARIOS_H

#include "global.h"

void displayBits(unsigned value);

void displayBitsll(unsigned long long value);

void displayBitsCliquell(unsigned long long *clique);

void inicializarRll(int linha);

int isZero(unsigned long long *R, int i,int *j);

int isZero(unsigned long long *vertice, int *j);

void imprimirLinhall(unsigned long long *R, int i);

void imprimirGrafoll();

void imprimirGrafoll(unsigned long long *G);

int qtdUns(unsigned long long *R, int i);

void verticesDaClique(unsigned long long *vertices);

void inicializarVetorCll();


#endif //UTILITARIOS_H
