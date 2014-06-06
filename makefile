SOURCES+=$(wildcard src/*.c)

INCLUDES+=-I./src

LIBRARY+=-lrt
LIBRARY+=-lpthread

CFLAGS+=-Wall
CFLAGS+=-O3

default:
	mkdir -p build
	gcc $(CFLAGS) $(INCLUDES) $(SOURCES) -o build/coup $(LIBRARY)

clean:
	rm -fr build
