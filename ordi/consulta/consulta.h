#ifndef CONSULTA_H
#define CONSULTA_H

#include "../struct.h"
#include "../funcion/funcion.h"

void mostrarCola(Cola *cola);

void mostrarPorCarrera(Cola *cola);

void mostrarPorSemestre(Cola *cola);

void mostrarPorCarreraSemestre(Cola *cola);

void buscarPorNombre(Cola *cola);

void buscarPorMatricula(Cola *cola);

void imprimirAlumno(Alumno alumno);

void imprimirMaterias(Alumno alumno);

Nodo* buscarNodoPorMatricula(Cola *cola, int matricula);

#endif