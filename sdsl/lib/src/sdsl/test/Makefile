CC=g++
CC_FLAGS=-Wall -g -O3 -I/home/andras/rrr-size-vs-density/sdsl/lib/build/include -L/home/andras/rrr-size-vs-density/sdsl/lib/build/lib -DNDEBUG -funroll-loops 
CCLIB=-lsdsl -ldivsufsort -ldivsufsort64 -lgtest 
SOURCES=$(wildcard *Test.cpp)
EXECS=$(SOURCES:.cpp=)
EXEC_LIST=$(patsubst %,./%;,$(EXECS))                # list of executables
EXEC_LIST_VAL=$(patsubst %,valgrind ./%;,$(EXECS))   # list of executables preceded by valgrind command

all: $(EXECS)
	        
%:%.cpp
	$(CC) $(CC_FLAGS) -o $@ $< $(CCLIB) 

clean:
	rm -f $(EXECS)

# TODO special test case for BitMagicTestSSE

test:
	./test_cases/small/get_corpus.sh
	$(EXEC_LIST)


vtest:
	./test_cases/small/get_corpus.sh
	$(EXEC_LIST_VAL)
