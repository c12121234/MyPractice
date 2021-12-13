CC = g++
BIN = ./bin
INCLUDE = ./include
CFLAGS += -g -Wall -std=c++11
LIB = ./lib
SRC = ./src
.PHONY:clean

test:
	${CC} ${CFLAGS} -I${INCLUDE} ${SRC}/main.cpp ${SRC}/shape.cpp -o ${BIN}/$@

test2:libshape
	${CC} ${CFLAGS} -I${INCLUDE} ${SRC}/main.cpp -o ${BIN}/$@ -L${LIB} -lshape

test3:libshape
	gcc ${CFLAGS} -I${INCLUDE} ${SRC}/main.c -o ${BIN}/$@ -L${LIB} -lshape -lstdc++

libshape:
	${CC} ${CFLAGS} -fPIC -shared -I${INCLUDE} ${SRC}/shape.cpp -o ${LIB}/$@.so

clean:
	rm -rf ${BIN}/*;rm -rf ${LIB}/*