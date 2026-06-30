# Nombre del ejecutable
TARGET = programa

# Compilador
CC = gcc

# Flags de compilación
CFLAGS = -Wall -Wextra -I.

# Archivos fuente
SRC = \
main.c \
menu.c \
alta/alta.c \
baja/baja.c \
consulta/consulta.c \
funcion/funcion.c \
calificacion/calificacion.c \


# Regla principal
all:
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

# Limpiar compilados
clean:
	rm -f $(TARGET)