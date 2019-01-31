CC=g++

CFLAGs = -c -Wall

OUT= -o

CP = cp

SHARED = -shared

SU = sudo

PIC = -fPIC

L= -L. 

STR = -lstring

CONF = ldconfig

all: create 

create: 
	$(CC) stringclass.cpp $(PIC) $(SHARED) $(OUT) libstringclass.so

install:h config 
	$(SU) cp libstringclass.so /usr/lib/

h:
	$(SU) cp stringclass.h /usr/include


config: 
	$(SU) $(CONF)

clean:
	rm *.o *.h *.cpp

