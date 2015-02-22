
PROGS := caesar shopCart ticTacToe

all: $(PROGS)


caesar: caesar.cpp
	g++ -g caesar.cpp -o caesar

shopCart: Item.o ShopCart.o
	g++ -g Item.o ShopCart.o -o shopCart

ShopCart.o: ShopCart.cpp ShopCart.hpp
	g++ -c ShopCart.cpp

Item.o: Item.cpp Item.hpp
	g++ -c Item.cpp

ticTacToe: TicTacToe.o Board.o
	g++ -g TicTacToe.o Board.o -o ticTacToe

TicTacToe.o: TicTacToe.cpp TicTacToe.hpp
	g++ -c TicTacToe.cpp

Board.o: Board.cpp Board.hpp
	g++ -c Board.cpp


clean:
	rm -f $(PROGS) *.o *~
