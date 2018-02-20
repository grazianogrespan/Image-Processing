########################################################################
# 																	   #
# target : prerequisites											   #
# 	commands														   #
#																	   #
#	– target                                                           #
#																	   #
# • Indica i file che saranno costruiti dalla regola                   #
#																	   #
#	– prerequisites													   #
#																	   #
# • Indica i file da cui il file target dipendono					   #
#																	   #
#	– commands														   #
#																	   #
# • I comandi che costruiscono i file del target a partire dai file    #
#	dei prerequisiti												   #
#																	   #
#	-g    Informazioni di Debug                                        #
#	-Wall Mostra i Warning nel compilatore                             #
# 																	   #
########################################################################

# VARIABILI

CC = g++
CFLAGS = -g -Wall
TARGET = elaboraimmagine


all:elaboraimmagine


elaboraimmagine: main.o ./Filtri/Blur.o ./Filtri/Seppia.o ./Utils/CaricaSalva.o ./Utils/Dim.o ./Utils/Scala.o ./Filtri/Sharp.o ./Filtri/BN.o ./Filtri/Lumin.o ./Filtri/Contrasto.o ./Filtri/Zoom.o ./Filtri/Negativo.o ./Filtri/Trama.o
	g++ -o elaboraimmagine main.o ./Filtri/Blur.o ./Filtri/Seppia.o ./Utils/CaricaSalva.o ./Utils/Dim.o ./Utils/Scala.o ./Filtri/Sharp.o ./Filtri/BN.o ./Filtri/Lumin.o ./Filtri/Contrasto.o ./Filtri/Zoom.o ./Filtri/Negativo.o ./Filtri/Trama.o


main.o:  main.cpp ./Headers/Dim.h ./Headers/Scala.h ./Headers/CaricaSalva.h ./Headers/Seppia.h ./Headers/Blur.h ./Headers/Sharp.h ./Headers/BN.h ./Headers/Lumin.h ./Headers/Contrasto.h ./Headers/Zoom.h ./Headers/Negativo.h ./Headers/Trama.h
	g++ -c main.cpp


Blur.o:  Blur.cpp
	g++ -c Blur.cpp


Sharp.o:  Sharp.cpp
	g++ -c Sharp.cpp


Seppia.o:  Seppia.cpp
	g++ -c Seppia.cpp


CaricaSalva.o:  CaricaSalva.cpp
	g++ -c CaricaSalva.cpp


Dim.o:  Dim.cpp
	g++ -c Dim.cpp


Scala.o:  Scala.cpp
	g++ -c Scala.cpp


BN.o: BN.cpp
	g++ -c BN.cpp


Lumin.o: Lumin.cpp
	g++ -c Lumin.cpp


Contrasto.o: Contrasto.cpp
	g++ -c Contrasto.cpp


Zoom.o: Zoom.cpp
	g++ -c Zoom.cpp


Negativo.o: Negativo.cpp
	g++ -c Negativo.cpp


Trama.o: Trama.cpp
	g++ -c Trama.cpp

# make clean rimuove tutti i file oggetto creati in fase di compilazione

clean:
	rm -rf *.o
	rm -rf ./Filtri/*.o
	rm -rf ./Utils/*.o
