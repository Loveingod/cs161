
PROGS := smallSort2 sphere findMode

all: $(PROGS)


smallSort2: smallSort2.cpp
	g++ -g smallSort2.cpp -o smallSort2

sphere: Sphere.o sphereMain.o
	g++ -g Sphere.o sphereMain.o -o sphere

sphereMain.o: sphereMain.cpp
	g++ -c sphereMain.cpp

Sphere.o: Sphere.cpp Sphere.hpp
	g++ -c Sphere.cpp

findMode: findMode.cpp
	g++ -g findMode.cpp -o findMode


clean:
	rm -f $(PROGS) *.o *~
