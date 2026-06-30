#ifndef FUNCIONES_H
#define FUNCIONES_H

#include "../struct.h"

typedef struct {
    Nodo *frente;
    Nodo *final;
} Cola;

int colaVacia(Cola *cola);
void inicializarCola(Cola *cola);
float calcularPromedioMateria(Materia materia);
int estaAprobado(Materia materia);

#endif