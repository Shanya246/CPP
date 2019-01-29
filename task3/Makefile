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

all: create 

create: 
	$(CC) string11.cpp $(PIC) $(SHARED) $(OUT) libstring.so

install:h config 
	$(SU) cp libstring.so /usr/lib/

h:
	$(SU) cp string11.h /usr/include


config: 
	$(SU) $(CONF)

clean:
	rm *.o *.h *.cpp

