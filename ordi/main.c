#include "funcion/funcion.h"
#include "menu.h"

int main()
{
    Cola cola;

    inicializarCola(&cola);

    menuPrincipal(&cola);

    return 0;
}