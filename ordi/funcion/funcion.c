#include "funcion.h"
#include <stdio.h>
#include <stdlib.h>

int colaVacia(Cola *cola)
{
    return cola->frente == NULL;
}

void inicializarCola(Cola *cola)
{
    cola->frente = NULL;
    cola->final = NULL;
}

float calcularPromedioMateria(Materia materia)
{
    float promedioParciales;

    promedioParciales =
        (materia.parcial1 +
         materia.parcial2 +
         materia.parcial3) / 3.0;

    return (promedioParciales * 0.5) + (materia.ordinario * 0.5);
}

int estaAprobado(Materia materia)
{
    return calcularPromedioMateria(materia) >= 6.0;
}