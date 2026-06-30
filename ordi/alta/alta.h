#ifndef ALTA_H
#define ALTA_H

#include "../struct.h"
#include "../funcion/funcion.h"

Alumno capturarAlumno();

void capturarMaterias(Alumno *alumno);

void altaAlumno(Cola *cola, Alumno alumno);

#endif