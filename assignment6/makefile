
PROGS := car supplies geom

all: $(PROGS)


car: Car.cpp Car.hpp
	g++ -g Car.cpp -o car

supplies: Supplies.cpp Supplies.hpp
	g++ -g Supplies.cpp -o supplies

geom: LineSegment.o Point.o
	g++ -g LineSegment.o Point.o -o geom

LineSegment.o: LineSegment.cpp LineSegment.hpp
	g++ -c LineSegment.cpp

Point.o: Point.cpp Point.hpp
	g++ -c Point.cpp


clean:
	rm -f $(PROGS) *.o *~
