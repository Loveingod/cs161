PROGS := dice box hero datePrint

all: $(PROGS)

dice: DiceCup.cpp DiceCup.hpp
	g++ -g DiceCup.cpp -o dice

box: Box.cpp Box.hpp
	g++ -g Box.cpp -o box

hero: Hero.cpp Hero.hpp
	g++ -g Hero.cpp -o hero

datePrint: Date.cpp Date.hpp
	g++ -g Date.cpp -o datePrint


clean:
	rm -f $(PROGS) *.o *~