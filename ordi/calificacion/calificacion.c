#include <stdio.h>
#include <string.h>
#include "calificacion.h"

void menuCalificaciones(Cola *cola)
{
    int op;

    do
    {
        printf("\n========== CALIFICACIONES ==========\n");
        printf("1. Por semestre\n");
        printf("2. Por materia\n");
        printf("3. Por parcial\n");
        printf("4. Por carrera (adeudos)\n");
        printf("5. Regresar\n");
        printf("====================================\n");

        scanf("%d", &op);

        switch(op)
        {
            case 1: reporteSemestre(cola); break;
            case 2: reporteMateria(cola); break;
            case 3: reporteParcial(cola); break;
            case 4: reporteCarrera(cola); break;
        }

    } while(op != 5);
}

void reporteSemestre(Cola *cola)
{
    int sem;
    printf("Semestre: ");
    scanf("%d", &sem);

    Nodo *aux = cola->frente;

    printf("\n--- ALUMNOS DEL SEMESTRE ---\n");

    while(aux != NULL)
    {
        if(aux->alumno.semestre == sem)
        {
            int aprobadas = 0;

            for(int i = 0; i < 5; i++)
            {
                if(estaAprobado(aux->alumno.materias[i]))
                    aprobadas++;
            }

            if(aprobadas == 2)
                printf("APROBADO: %d - %s\n",
                    aux->alumno.matricula,
                    aux->alumno.persona.nombre);
            else
                printf("REPROBADO: %d - %s\n",
                    aux->alumno.matricula,
                    aux->alumno.persona.nombre);
        }

        aux = aux->siguiente;
    }
}

void reporteMateria(Cola *cola)
{
    char mat[50];
    printf("Materia: ");
    scanf(" %[^\n]", mat);

    Nodo *aux = cola->frente;

    while(aux != NULL)
    {
        for(int i = 0; i < 5; i++)
        {
            if(strcmp(aux->alumno.materias[i].nombre, mat) == 0)
            {
                if(estaAprobado(aux->alumno.materias[i]))
                {
                    printf("APROBADO -> %d %s\n",
                        aux->alumno.matricula,
                        aux->alumno.persona.nombre);
                }
                else
                {
                    printf("REPROBADO -> %d %s\n",
                        aux->alumno.matricula,
                        aux->alumno.persona.nombre);
                }
            }
        }

        aux = aux->siguiente;
    }
}

void reporteParcial(Cola *cola)
{
    int p;
    printf("Parcial (1-3): ");
    scanf("%d", &p);

    Nodo *aux = cola->frente;

    while(aux != NULL)
    {
        for(int i = 0; i < 5; i++)
        {
            float nota = 0;

            if(p == 1) nota = aux->alumno.materias[i].parcial1;
            if(p == 2) nota = aux->alumno.materias[i].parcial2;
            if(p == 3) nota = aux->alumno.materias[i].parcial3;

            if(nota >= 6)
            {
                printf("APROBÓ PARCIAL -> %d %s (%s)\n",
                    aux->alumno.matricula,
                    aux->alumno.persona.nombre,
                    aux->alumno.materias[i].nombre);
            }
        }

        aux = aux->siguiente;
    }
}

void reporteCarrera(Cola *cola)
{
    Nodo *aux = cola->frente;

    while(aux != NULL)
    {
        int adeudos = 0;

        for(int i = 0; i < 5; i++)
        {
            if(!estaAprobado(aux->alumno.materias[i]))
                adeudos++;
        }

        if(adeudos == 0)
            printf("SIN ADEUDOS -> %d\n", aux->alumno.matricula);
        else if(adeudos <= 3)
            printf("1-3 ADEUDOS -> %d\n", aux->alumno.matricula);
        else
            printf("+4 ADEUDOS -> %d\n", aux->alumno.matricula);

        aux = aux->siguiente;
    }
}