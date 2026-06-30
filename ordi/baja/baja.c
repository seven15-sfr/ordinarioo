#include "baja.h"
#include <stdio.h>
#include <stdlib.h>

void bajaAlumno(Cola *cola)
{
    if (colaVacia(cola))
    {
        printf("Cola vacia\n");
        return;
    }

    Nodo *aux = cola->frente;

    printf("Eliminando: %s\n", aux->alumno.persona.nombre);

    cola->frente = cola->frente->siguiente;

    if (cola->frente == NULL)
    {
        cola->final = NULL;
    }

    free(aux);
}

