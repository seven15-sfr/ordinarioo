#include <stdio.h>
#include <stdlib.h>
#include "altas.h"

int Altas(struct Persona **ptr)
{

    struct Persona *P = NULL;
    struct Alumno *A = NULL;
    int b = 1;//Bandera

    P = nuevaPersona();

    if(P == NULL){

        b = 0;

    }else{
        A = nuevoAlumno();
        if(A == NULL){
            b = 0;
            free(P);
        } else {
        //Hace que se cree el dato y lo enlaza
        P->ptrAlum = A;
        P->ptrSig = *ptr;
        *ptr = P;
        }
    }
    return b;
}

struct Persona* nuevaPersona(void)
{
    struct Persona *P = (struct Persona*)malloc(sizeof(struct Persona));
    if (P == NULL) return NULL;

    P->nombre = (char*)malloc(50 * sizeof(char));
    if (P->nombre == NULL) { free(P); return NULL; }

    printf("Nombre: ");
    scanf("%s",P->nombre);
    printf("Edad: ");
    scanf("%d",&P->edad);
    printf("Genero M o F: ");
    scanf("%c",&P->genero);
    printf("Fecha de nacimiento : ");
    scanf("%s",P->fn);

    P->ptrAlum = NULL;
    P->ptrSig  = NULL;

    return P;
}

struct Alumno* nuevoAlumno(void)
{
    struct Alumno *A = (struct Alumno*)malloc(sizeof(struct Alumno));
    if (A == NULL) return NULL;

    printf("Matricula: ");
    scanf("%s", A->matricula);
    printf("Carrera: ");
    scanf("%s", A->carrera);
    printf("Semestre: ");
    scanf("%d", &A->semestre);
    printf("Correo: ");
    scanf("%s", A->correo);

    return A;
}
