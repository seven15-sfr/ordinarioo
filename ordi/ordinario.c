#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "altas.h"
#include "struct.h"

int main(void){
    int op;
    struct Persona *ptr=NULL;


   do{
    op=menuPrincipal();
    switch (op){
        case 1://Datos de nuevo usuario
            altas(&ptr);//conexión
            break;
        case 2:

            break;

        default:
            printf("nada aun \n");
            break;
        
    }
    }while (op!=2);
      
    return 0;
}