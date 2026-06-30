#include "alta.h"
#include <stdio.h>
#include <stdlib.h>

Alumno capturarAlumno()
{
    Alumno alumno;

    printf("\n===== ALTA DE ALUMNO =====\n");

    printf("Nombre: ");
    scanf(" %[^\n]", alumno.persona.nombre);

    printf("Edad: ");
    scanf("%d", &alumno.persona.edad);

    printf("Sexo (M/F): ");
    scanf(" %c", &alumno.persona.sexo);

    printf("Matricula: ");
    scanf("%d", &alumno.matricula);

    printf("Carrera: ");
    scanf(" %[^\n]", alumno.carrera);

    printf("Semestre: ");
    scanf("%d", &alumno.semestre);

     /* Capturar materias */
    capturarMaterias(&alumno);

    return alumno;
}

void altaAlumno(Cola *cola, Alumno alumno)
{
    Nodo *nuevo = (Nodo *)malloc(sizeof(Nodo));

    if (nuevo == NULL)
    {
        printf("Error de memoria\n");
        return;
    }

    nuevo->alumno = alumno;
    nuevo->siguiente = NULL;

    if (colaVacia(cola))
    {
        cola->frente = nuevo;
        cola->final = nuevo;
    }
    else
    {
        cola->final->siguiente = nuevo;
        cola->final = nuevo;
    }
}

void capturarMaterias(Alumno *alumno)
{
    int i;

    for(i = 0; i < 5; i++)
    {
        printf("\nMateria %d\n", i + 1);

        printf("Nombre: ");
        scanf(" %[^\n]", alumno->materias[i].nombre);

        printf("Parcial 1: ");
        scanf("%f", &alumno->materias[i].parcial1);

        printf("Parcial 2: ");
        scanf("%f", &alumno->materias[i].parcial2);

        printf("Parcial 3: ");
        scanf("%f", &alumno->materias[i].parcial3);

        printf("Ordinario: ");
        scanf("%f", &alumno->materias[i].ordinario);

        alumno->materias[i].promedio =
            (alumno->materias[i].parcial1 +
             alumno->materias[i].parcial2 +
             alumno->materias[i].parcial3 +
             alumno->materias[i].ordinario) / 4.0;
    }
}