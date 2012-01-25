#####################################################################
# Makefile for Jefferson Amado 
#
# Compiler: gcc version 4.4.3 (Ubuntu 4.4.3-4ubuntu5) 
# Target: i486-linux-gnu
# Thread model: posix
#####################################################################
nombre_Programa= TrashSpace
# compiler
CPP = g++
# C++ compiler flags 
CPPFLAGS = -lGLU -lglut -lGL  -w
#directorios
OUT=ts.sh
SRC=source/Camara.cpp source/Obstaculo.cpp source/Player.cpp source/imageloader.cpp source/ObstaculoList.cpp source/TrashSpace.cpp

default: make $(OUT)
make:
	$(CPP) $(CPPFLAGS) $(SRC) -o $(OUT)
doc:
	doxygen 
clean:
	rm -frv  $(OUT) doc/
