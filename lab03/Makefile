# CSCI3081 Lab03 makefile

CC = g++
DEBUG = -g
CFLAGS = -Wall -std=c++11 -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)

all: lab03.o

lab03.o : main.o MallardDuck.o RubberDuck.o DecoyDuck.o MuteQuack.o Duck.o Quack.o Squeak.o QuackBehavior.o
	$(CC) $(LFLAGS) *.o -o lab03.out

main.o : main.cpp MallardDuck.h RubberDuck.h DecoyDuck.h MuteQuack.h 
	$(CC) $(CFLAGS) main.cpp

MallardDuck.o : MallardDuck.h MallardDuck.cpp Duck.h Quack.h
	$(CC) $(CFLAGS) MallardDuck.cpp

RubberDuck.o : RubberDuck.h RubberDuck.cpp Duck.h Quack.h Squeak.h
	$(CC) $(CFLAGS) RubberDuck.cpp

DecoyDuck.o : DecoyDuck.h DecoyDuck.cpp Duck.h MuteQuack.h
	$(CC) $(CFLAGS) DecoyDuck.cpp

MuteQuack.o : MuteQuack.h MuteQuack.cpp QuackBehavior.h
	$(CC) $(CFLAGS) MuteQuack.cpp

Duck.o : Duck.h Duck.cpp QuackBehavior.h Quack.h
	$(CC) $(CFLAGS) Duck.cpp

Quack.o : Quack.h Quack.cpp QuackBehavior.h
	$(CC) $(CFLAGS) Quack.cpp

Squeak.o : Squeak.h Squeak.cpp QuackBehavior.h
	$(CC) $(CFLAGS) Squeak.cpp

QuackBehavior.o : QuackBehavior.h QuackBehavior.cpp
		$(CC) $(CFLAGS) QuackBehavior.cpp

clean:
	rm *.o *.out 
