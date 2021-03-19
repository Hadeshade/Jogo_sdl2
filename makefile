#OBJS especifica quais arquivos devem ser compilados
OBJS = main.cpp Game.cpp TextureManager.cpp GameObject.cpp Player.cpp

#CC especifica qual compilador vai ser usado;
CC = g++

#COMPILER_FLAGS especifica as opções de compilação
COMPILER_FLAGS = -w

#LINKER_FLAGS especifica as bibliotecas a serem likadas
LINKER_FLAGS = -lSDL2 -lSDL2_image

#OBJ_NAME especifica o nome do executavél
OBJ_NAME = Jogo_Novo

#Objeto de compilação
all: $(OBJS)
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)