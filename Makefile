all: astronauta.o voo.o sistema.o
	g++ astronauta.o voo.o sistema.o -o saida

astronauta.o: astronauta.cpp astronauta.h
	g++ -c astronauta.cpp

voo.o: voo.cpp voo.h
	g++ -c voo.cpp

sistema.o: sistema.cpp
	g++ -c sistema.cpp

clean:
	rm -rf *.o