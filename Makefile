OBJS = main.c

CC = g++

CFLAGS = -w

LFLAGS = -lSDL2

# Exectuable name
OBJ_NAME = sdl

all : $(OBJS)
		$(CC) $(OBJS) $(CFLAGS) $(LFLAGS) -o $(OBJ_NAME)

clean : $(OBJS)
		rm -f $(OBJ_NAME)