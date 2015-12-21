CC = g++
CXXFLAGS = -std=c++11 -I.
EXECUTABLE = matrices
SRC_DIR = libmatrix
BUILD_DIR = build

_OBJS = matrix.o main.o
OBJS = $(patsubst %, ${BUILD_DIR}/%, ${_OBJS})

_DEPS = matrix.h
DEPS = $(patsubst %, ${SRC_DIR}/%, ${_DEPS})

.PHONY: all

all: run

${EXECUTABLE}: ${OBJS}
	${CC} -o $@ $^ ${CXXFLAGS}

${BUILD_DIR}/%.o: ${SRC_DIR}/%.cpp ${DEPS} ${BUILD_DIR}
	${CC} -c -o $@ $< ${CXXFLAGS}

${BUILD_DIR}/main.o: main.cpp ${DEPS} ${BUILD_DIR}
	${CC} -c -o $@ $< ${CXXFLAGS}

${BUILD_DIR}:
	mkdir ${BUILD_DIR}

run: ${EXECUTABLE}
	./${EXECUTABLE}

.PHONY: clean

clean:
	-rm -r ${BUILD_DIR} ${EXECUTABLE}
