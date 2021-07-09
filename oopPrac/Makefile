ROOTDIR = $(shell pwd)
CC = gcc
CFLAGS += -g -Wall -lm
.PHONY:clean

# Main:square.o main.o
# 	${CC} ${CFLAGS} -I ./include/ -o ./bin/$@

# square.o:./src/square.c ./include/square.h
# 	${CC} ${CFLAGS} -I ./include/ ./src/square.c -c -o ./bin/$@

# main.o:./src/main.c
# 	${CC} ./src/main.c -c -I ./include/ -o ./bin/$@

# Main:
# 	${CC} ./src/ishape.c ./src/triangle.c ./src/square.c ./src/main.c -I ./include/ ${CFLAGS} -o ./bin/$@

Main:
	${CC} ./src/*.c -I ./include/ ${CFLAGS} -o ./bin/$@

clean:
	cd bin;rm -rf *