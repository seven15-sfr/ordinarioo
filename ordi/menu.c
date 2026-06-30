#include "menu.h"
#include <stdio.h>
#include "alta/alta.h"
#include "baja/baja.h"
#include "consulta/consulta.h"
#include "calificacion/calificacion.h"

void modificarDatosAlumno(Cola *cola)
{
    int matricula;
    Nodo *nodo;

    printf("\nIngrese matricula del alumno: ");
    scanf("%d", &matricula);

    nodo = buscarNodoPorMatricula(cola, matricula);

    if(nodo == NULL)
    {
        printf("\nAlumno no encontrado.\n");
        return;
    }

    printf("\n=== NUEVOS DATOS ===\n");

    printf("Nombre: ");
    scanf(" %[^\n]", nodo->alumno.persona.nombre);

    printf("Edad: ");
    scanf("%d", &nodo->alumno.persona.edad);

    printf("Sexo: ");
    scanf(" %c", &nodo->alumno.persona.sexo);

    printf("Carrera: ");
    scanf(" %[^\n]", nodo->alumno.carrera);

    printf("Semestre: ");
    scanf("%d", &nodo->alumno.semestre);

    printf("\nDatos actualizados correctamente.\n");
}

void modificarCalificaciones(Cola *cola)
{
    int matricula, i;
    Nodo *nodo;

    printf("\nIngrese matricula del alumno: ");
    scanf("%d", &matricula);

    nodo = buscarNodoPorMatricula(cola, matricula);

    if(nodo == NULL)
    {
        printf("\nAlumno no encontrado.\n");
        return;
    }

    for(i = 0; i < 5; i++)
    {
        printf("\nMateria: %s\n", nodo->alumno.materias[i].nombre);

        printf("Parcial 1: ");
        scanf("%f", &nodo->alumno.materias[i].parcial1);

        printf("Parcial 2: ");
        scanf("%f", &nodo->alumno.materias[i].parcial2);

        printf("Parcial 3: ");
        scanf("%f", &nodo->alumno.materias[i].parcial3);

        printf("Ordinario: ");
        scanf("%f", &nodo->alumno.materias[i].ordinario);

        float promedioParciales;

        promedioParciales =
            (nodo->alumno.materias[i].parcial1 +
            nodo->alumno.materias[i].parcial2 +
            nodo->alumno.materias[i].parcial3) / 3.0;

        nodo->alumno.materias[i].promedio =
            (promedioParciales * 0.5) +
            (nodo->alumno.materias[i].ordinario * 0.5);

    }

    printf("\nCalificaciones actualizadas.\n");
}

void menuPrincipal(Cola *cola)
{
    int opcion;

    do
    {
        printf("\n=====================================\n");
        printf("      SISTEMA DE CALIFICACIONES\n");
        printf("=====================================\n");
        printf("1. Altas\n");
        printf("2. Bajas\n");
        printf("3. Mostrar\n");
        printf("4. Modificar\n");
        printf("5. Calificaciones\n");
        printf("6. Salir\n");
        printf("=====================================\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch(opcion)
        {
            case 1:
                printf("\nMenu de Altas\n");
                menuAltas(cola);
                break;

            case 2:
                printf("\nMenu de Bajas\n");
                menuBajas(cola);
                break;

            case 3:
                printf("\nMenu de Mostrar\n");
                menuMostrar(cola);
                break;

            case 4:
                printf("\nMenu de Modificar\n");
                menuModificar(cola);
                break;

            case 5:
                printf("\nMenu de Calificaciones\n");
                menuCalificaciones(cola);
                break;

            case 6:
                printf("\n Saliendo ... \n");
                break;

            default:
                printf("\nOpcion invalida.\n");
        }

    } while(opcion != 6);
}

void menuAltas(Cola *cola)
{
    int opcion;
    char respuesta;
    Alumno alumno;

    do
    {
        printf("\n========== ALTAS ==========\n");
        printf("1. Una persona\n");
        printf("2. Varias personas\n");
        printf("3. Regresar\n");
        printf("===========================\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch(opcion)
        {
            case 1:

                alumno = capturarAlumno();

                altaAlumno(cola, alumno);

                printf("\nAlumno registrado correctamente.\n");

                break;

            case 2:

                do
                {
                    alumno = capturarAlumno();

                    altaAlumno(cola, alumno);

                    printf("\n¿Registrar otro alumno? (S/N): ");
                    scanf(" %c", &respuesta);

                } while(respuesta == 'S' || respuesta == 's');

                break;

            case 3:

                printf("\nRegresando...\n");

                break;

            default:

                printf("\nOpcion invalida.\n");

        }

    } while(opcion != 3);
}

void menuBajas(Cola *cola)
{
    int opcion;
    char respuesta;

    do
    {
        printf("\n========== BAJAS ==========\n");
        printf("1. Una persona\n");
        printf("2. Varias personas\n");
        printf("3. Todas\n");
        printf("4. Regresar\n");
        printf("===========================\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch(opcion)
        {
            case 1:

                bajaAlumno(cola);

                break;

            case 2:

                do
                {
                    bajaAlumno(cola);

                    printf("\n¿Eliminar otro alumno? (S/N): ");
                    scanf(" %c", &respuesta);

                } while((respuesta == 'S' || respuesta == 's') && !colaVacia(cola));

                break;

            case 3:

                while(!colaVacia(cola))
                {
                    bajaAlumno(cola);
                }

                printf("\nTodos los alumnos fueron eliminados.\n");

                break;

            case 4:

                printf("\nRegresando...\n");

                break;

            default:

                printf("\nOpcion invalida.\n");
        }

    } while(opcion != 4);
}

void menuMostrar(Cola *cola)
{
    int opcion;

    do
    {
        printf("\n========== MOSTRAR ==========\n");
        printf("1. Todos\n");
        printf("2. Carrera\n");
        printf("3. Semestre\n");
        printf("4. Carrera y Semestre\n");
        printf("5. Nombre\n");
        printf("6. Matricula\n");
        printf("7. Regresar\n");
        printf("=============================\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch(opcion)
        {
            case 1:
                mostrarCola(cola);
                break;

            case 2:
                mostrarPorCarrera(cola);
                break;

            case 3:
                mostrarPorSemestre(cola);
                break;

            case 4:
                mostrarPorCarreraSemestre(cola);
                break;

            case 5:
                buscarPorNombre(cola);
                break;

            case 6:
                buscarPorMatricula(cola);
                break;

            case 7:
                printf("\nRegresando...\n");
                break;

            default:
                printf("\nOpcion invalida.\n");
        }

    } while(opcion != 7);
}

void menuModificar(Cola *cola)
{
    int opcion;

    do
    {
        printf("\n========== MODIFICAR ==========\n");
        printf("1. Datos del alumno\n");
        printf("2. Calificaciones de materias\n");
        printf("3. Regresar\n");
        printf("================================\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch(opcion)
        {
            case 1:
                modificarDatosAlumno(cola);
                break;

            case 2:
                modificarCalificaciones(cola);
                break;

            case 3:
                printf("\nRegresando...\n");
                break;

            default:
                printf("\nOpcion invalida.\n");
        }

    } while(opcion != 3);
}