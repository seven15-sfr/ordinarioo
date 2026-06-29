
#include <stdio.h>

int menuPrincipal(void);
int mostar(void);
int submenu(void);

int menuPrincipal(void){
    int op;
    printf("\n MENU \n");
    printf("1. Crear datos de un nuevo usuario \n");
    printf("2. Bajas de usuarios \n");
    printf("3. Mostar \n");
    printf("4. Sub-Menu Especial \n");
    printf("5. Salir \n");
    scanf("%d", &op);
    return op;
};

int mostar(void){
    int opc;
    printf("Mostar toda la lista \n");
    printf("Mostar alumnos de la carrera \n");
    printf("Mostar alumnos del semestre \n");
    printf("Mostar carrera y semestre \n");
    printf("Buscar a persona por nombre \n");
    printf("Buscar alumno por numero de matricula \n");
    scanf("%d",&opc);
    return opc;
};

int submenu(void){
    int sub;
    printf("\n FC-ESPECIALES \n");
    printf("1. Modificiones \n");
    printf("2. Calificaiones \n");
    scanf("%d",&sub);
    return sub;
};
