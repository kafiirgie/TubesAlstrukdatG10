#make file - this is a comment section
 
CC=gcc  #compiler, klo pke clang tulis clang
TARGET=mainProgram #target file name
#gcc src/main.c View/Game/Game.c View/Initialization/Initialization.c View/Menu/Menu.c src/ADT/listlinier/listlinier.c src/ADT/listlinier/skill.c src/ADT/MesinKarKat/mesin_kata.c src/ADT/MesinKarKat/mesin_kar.c src/ADT/OpenConf/OpenConf.c src/ADT/Player/Player.c -o mein
 
all: 
    $(CC) src/main.c View/Game/Game.c View/Initialization/Initialization.c View/Menu/Menu.c src/ADT/listlinier/listlinier.c src/ADT/listlinier/skill.c src/ADT/MesinKarKat/mesin_kata.c src/ADT/MesinKarKat/mesin_kar.c src/ADT/OpenConf/OpenConf.c src/ADT/Player/Player.c -o $(TARGET)
clean:
    rm *.o $(TARGET)