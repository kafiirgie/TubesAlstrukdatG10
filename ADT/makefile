#make file - this is a comment section
#makefile for ADT
CC = gcc  #compiler, klo pke clang tulis clang
TARGET = ADTDriver #target file name

#Choose ADT Driver to put below 'all:'
#Config		: $(CC) MesinKarKat/mesin_kar.c MesinKarKat/mesin_kata.c Configuration/Configuration.c Drivers/ConfDriver.c -o $(TARGET)
#MesinKar 	: $(CC) MesinKarKat/mesin_kar.c Drivers/MesinKarDriver.c -o $(TARGET)
#MesinKata 	: $(CC) MesinKarKat/mesin_kar.c MesinKarKat/mesin_kata.c Drivers/MesinKataDriver.c -o $(TARGET)
#ListLinier	: $(CC) Skill/ListLinier.c Drivers/ListLinierDriver.c -o $(TARGET)
#Skill 		: $(CC) Skill/ListLinier.c Skill/Skill.c Drivers/SkillDriver.c -o $(TARGET)
#Player 	: $(CC) MesinKarKat/mesin_kar.c MesinKarKat/mesin_kata.c Configuration/Configuration.c Skill/ListLinier.c Skill/Skill.c Player/Player.c Drivers/PlayerDriver.c -o $(TARGET)
#Round 		: $(CC) MesinKarKat/mesin_kar.c MesinKarKat/mesin_kata.c Configuration/Configuration.c Skill/ListLinier.c Skill/Skill.c Player/Player.c Round/Round.c Drivers/RoundDriver.c -o $(TARGET)

 
all:
	$(CC) MesinKarKat/mesin_kar.c MesinKarKat/mesin_kata.c Configuration/Configuration.c Drivers/ConfDriver.c -o $(TARGET)
clean:
	rm *.o $(TARGET)