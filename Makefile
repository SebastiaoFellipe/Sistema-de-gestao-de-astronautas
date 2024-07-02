all: astronauta.o voo.o sistema.o main.o
	g++ astronauta.o voo.o sistema.o main.o -o saida

astronauta.o: astronauta.cpp astronauta.h
	g++ -c astronauta.cpp

voo.o: voo.cpp voo.h
	g++ -c voo.cpp

sistema.o: sistema.cpp sistema.h
	g++ -c sistema.cpp

main.o: main.cpp
	g++ -c main.cpp

clean:
	rm -rf *.o