#make file - this is a comment section
 #makefile for ADT
CC=gcc  #compiler, klo pke clang tulis clang
TARGET=game #target file name
#gcc src/main.c View/Game/Game.c View/Initialization/Initialization.c View/Menu/Menu.c src/ADT/listlinier/listlinier.c src/ADT/listlinier/skill.c src/ADT/MesinKarKat/mesin_kata.c src/ADT/MesinKarKat/mesin_kar.c src/ADT/OpenConf/OpenConf.c src/ADT/Player/Player.c -o mein
 
all: 
	$(CC) main.c View/Menu/Menu.c View/Exit/Exit.c View/Game/Game.c ADT/Skill/ListLinier.c ADT/Skill/Skill.c ADT/Round/Round.c ADT/Player/Player.c ADT/Configuration/Configuration.c ADT/MesinKarKat/mesin_kar.c ADT/MesinKarKat/mesin_kata.c -o $(TARGET)
clean:
	rm *.o $(TARGET)