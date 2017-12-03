all: distancevektor execute clean

distancevektor: distancevektor.o
	g++ distancevektor.o -o distancevektor

distancevektor.o: distancevektor.cpp
	g++ -c distancevektor.cpp

execute :
	./distancevektor
clean:
	rm -rf *o distancevektor

