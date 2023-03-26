OBJS = main.c

CC = g++

COMPILER_FLAGS = -w

LINKER_FLAGS = -lSDL2

# Exectuable name
OBJ_NAME = SDLout

all : $(OBJS)
		$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)
