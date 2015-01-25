PROGS := randNums ticketIncome tempConvert loanPayments

all: $(PROGS)

randnums: randNums.cpp
	g++ -g randNums.cpp -o randNums

ticketIncome: ticketIncome.cpp
	g++ -g ticketIncome.cpp -o ticketIncome
	
tempConvert: tempConvert.cpp
	g++ -g tempConvert.cpp -o tempConvert

loanPayments: loanPayments.cpp
	g++ -g loanPayments.cpp -o loanPayments

clean:
	rm -f $(PROGS) *.o *~