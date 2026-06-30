#ifndef STRUCT_H
#define STRUCT_H

typedef struct
{
    char nombre[100];
    int edad;
    char sexo;
} Persona;

typedef struct
{
    char nombre[50];

    float parcial1;
    float parcial2;
    float parcial3;

    float ordinario;
    float promedio;

} Materia;

typedef struct
{
    Persona persona;

    int matricula;
    char carrera[50];
    int semestre;

    Materia materias[5];

} Alumno;

typedef struct Nodo
{
    Alumno alumno;
    struct Nodo *siguiente;
} Nodo;

#endif