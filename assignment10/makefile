PROGS := lib

all: $(PROGS)


lib: Book.o Patron.o Library.o menu.o
	g++ -g Book.o Patron.o Library.o menu.o -o lib

Book.o: Book.cpp Book.hpp
	g++ -c Book.cpp

Patron.o: Patron.cpp Patron.hpp
	g++ -c Patron.cpp

Library.o: Library.cpp Library.hpp
	g++ -c Library.cpp

menu.o: menu.cpp
	g++ -c menu.cpp


clean:
	rm -f $(PROGS) *.o *~
