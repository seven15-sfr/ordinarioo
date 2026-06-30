#include "consulta.h"
#include <stdio.h>
#include <string.h>

void imprimirMaterias(Alumno alumno)
{
    int i;

    printf("\n========== MATERIAS ==========\n");

    for (i = 0; i < 5; i++)
    {
        printf("\nMateria %d\n", i + 1);
        printf("Nombre      : %s\n", alumno.materias[i].nombre);
        printf("Parcial 1   : %.2f\n", alumno.materias[i].parcial1);
        printf("Parcial 2   : %.2f\n", alumno.materias[i].parcial2);
        printf("Parcial 3   : %.2f\n", alumno.materias[i].parcial3);
        printf("Ordinario   : %.2f\n", alumno.materias[i].ordinario);
        printf("Promedio    : %.2f\n", alumno.materias[i].promedio);
    }
}

void imprimirAlumno(Alumno alumno)
{
    printf("\n=========================================\n");
    printf("Nombre      : %s\n", alumno.persona.nombre);
    printf("Edad        : %d\n", alumno.persona.edad);
    printf("Sexo        : %c\n", alumno.persona.sexo);

    printf("Matricula   : %d\n", alumno.matricula);
    printf("Carrera     : %s\n", alumno.carrera);
    printf("Semestre    : %d\n", alumno.semestre);

    imprimirMaterias(alumno);

    printf("=========================================\n");
}

void mostrarPorCarrera(Cola *cola)
{
    char carrera[50];
    int encontrado = 0;

    printf("\nIngrese la carrera: ");
    scanf(" %[^\n]", carrera);

    Nodo *aux = cola->frente;

    while (aux != NULL)
    {
        if (strcmp(aux->alumno.carrera, carrera) == 0)
        {
            imprimirAlumno(aux->alumno);
            encontrado = 1;
        }

        aux = aux->siguiente;
    }

    if (!encontrado)
    {
        printf("\nNo hay alumnos en esa carrera.\n");
    }
}

void mostrarPorSemestre(Cola *cola)
{
    int semestre;
    int encontrado = 0;

    printf("\nIngrese el semestre: ");
    scanf("%d", &semestre);

    Nodo *aux = cola->frente;

    while (aux != NULL)
    {
        if (aux->alumno.semestre == semestre)
        {
            imprimirAlumno(aux->alumno);
            encontrado = 1;
        }

        aux = aux->siguiente;
    }

    if (!encontrado)
    {
        printf("\nNo hay alumnos en ese semestre.\n");
    }
}

void mostrarPorCarreraSemestre(Cola *cola)
{
    char carrera[50];
    int semestre;
    int encontrado = 0;

    printf("\nIngrese la carrera: ");
    scanf(" %[^\n]", carrera);

    printf("Ingrese el semestre: ");
    scanf("%d", &semestre);

    Nodo *aux = cola->frente;

    while (aux != NULL)
    {
        if (strcmp(aux->alumno.carrera, carrera) == 0 &&
            aux->alumno.semestre == semestre)
        {
            imprimirAlumno(aux->alumno);
            encontrado = 1;
        }

        aux = aux->siguiente;
    }

    if (!encontrado)
    {
        printf("\nNo hay alumnos con esos criterios.\n");
    }
}

void buscarPorNombre(Cola *cola)
{
    char nombre[100];
    int encontrado = 0;

    printf("\nIngrese el nombre: ");
    scanf(" %[^\n]", nombre);

    Nodo *aux = cola->frente;

    while (aux != NULL)
    {
        if (strcmp(aux->alumno.persona.nombre, nombre) == 0)
        {
            imprimirAlumno(aux->alumno);
            encontrado = 1;
        }

        aux = aux->siguiente;
    }

    if (!encontrado)
    {
        printf("\nNo se encontro el alumno.\n");
    }
}

void buscarPorMatricula(Cola *cola)
{
    int matricula;
    int encontrado = 0;

    printf("\nIngrese la matricula: ");
    scanf("%d", &matricula);

    Nodo *aux = cola->frente;

    while (aux != NULL)
    {
        if (aux->alumno.matricula == matricula)
        {
            imprimirAlumno(aux->alumno);
            encontrado = 1;
            break; // matrícula es única
        }

        aux = aux->siguiente;
    }

    if (!encontrado)
    {
        printf("\nAlumno no encontrado.\n");
    }
}

void mostrarCola(Cola *cola)
{
    if (colaVacia(cola))
    {
        printf("\nCola vacia.\n");
        return;
    }

    Nodo *aux = cola->frente;
    int contador = 1;

    while (aux != NULL)
    {
        printf("\n========= ALUMNO %d =========\n", contador);
        imprimirAlumno(aux->alumno);

        aux = aux->siguiente;
        contador++;
    }
}

Nodo* buscarNodoPorMatricula(Cola *cola, int matricula)
{
    Nodo *aux = cola->frente;

    while(aux != NULL)
    {
        if(aux->alumno.matricula == matricula)
        {
            return aux;
        }
        aux = aux->siguiente;
    }

    return NULL;
}