#
# Makefile for CS 70 Spell Checking Assignment
# 

# ----- Make Variables -----

OPTFLAGS  =   -O3
DEFINES   =
CXXFLAGS  =	-g $(OPTFLAGS) -Wall -Wextra -pedantic $(DEFINES) 
CXX	  =	cs70-c++
GTEST_LIB =	-lgtest -lgtest_main

TESTS     =     treeset-tests hashset-tests stdtreeset-tests stdhashset-tests
TARGETS   = 	$(TESTS) myspell

# ----- Make Rules -----

all:	$(TARGETS)

tests:	$(TESTS)
	./treeset-tests
	./hashset-tests
	./stdtreeset-tests
	./stdhashset-tests

clean:
	rm -f $(TARGETS) *.o

myspell: myspell.o stringhash.o
	$(CXX) $(CXXFLAGS) -o myspell myspell.o stringhash.o $(GTEST_LIB)

treeset-tests: treeset-tests.o
	$(CXX) $(CXXFLAGS) -o treeset-tests treeset-tests.o $(GTEST_LIB)

hashset-tests: hashset-tests.o stringhash.o
	$(CXX) $(CXXFLAGS) -o hashset-tests hashset-tests.o stringhash.o $(GTEST_LIB)

stdtreeset-tests: stdtreeset-tests.o
	$(CXX) $(CXXFLAGS) -o stdtreeset-tests stdtreeset-tests.o $(GTEST_LIB)

stdhashset-tests: stdhashset-tests.o stringhash.o
	$(CXX) $(CXXFLAGS) -o stdhashset-tests stdhashset-tests.o stringhash.o $(GTEST_LIB)

# ------ Dependences (.cpp -> .o using default Makefile rule) -----

myspell.o: myspell.cpp abstractset.hpp stringhash.hpp hashset.hpp \
  hashset-private.hpp stdhashset.hpp stdhashset-private.hpp treeset.hpp \
  treeset-private.hpp stdtreeset.hpp stdtreeset-private.hpp
hashset-tests.o: hashset-tests.cpp hashset.hpp abstractset.hpp \
  hashset-private.hpp generic-set-tests.cpp
stdhashset-tests.o: stdhashset-tests.cpp stdhashset.hpp abstractset.hpp \
  stdhashset-private.hpp generic-set-tests.cpp
stdtreeset-tests.o: stdtreeset-tests.cpp stdtreeset.hpp abstractset.hpp \
  stdtreeset-private.hpp generic-set-tests.cpp
treeset-tests.o: treeset-tests.cpp treeset.hpp abstractset.hpp \
  treeset-private.hpp generic-set-tests.cpp
stringhash.o: stringhash.cpp
