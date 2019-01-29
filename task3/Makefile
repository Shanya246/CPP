CC=g++

CFLAGs = -c -Wall

OUT= -o

EXENAME = runner

MF = mv

CP = cp

MD = mkdir -p

CPPDIR = SOURCE

HDIR = H

ODIR = BIN

SHARED = -shared

SU = sudo

PIC = -fPIC

L= -L. 

STR = -lstring

CONF = ldconfig

all: run 

run: run1
	$(CC) main.cpp $(L) $(STR) $(OUT) main 

run1:
	./main

clean:
	rm *.o *.h *.cpp

