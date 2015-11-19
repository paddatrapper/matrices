CC = g++
CXXFLAGS = -std=c++11 -I.
EXECUTABLE = matrices
LIB_DIR = libmatrix
SRC_DIR = libmatrix
BUILD_DIR = build

_OBJS = matrix.o main.o
OBJS = $(patsubst %, ${BUILD_DIR}/%, ${_OBJS})

_DEPS = matrix.h
DEPS = $(patsubst %, ${LIB_DIR}/%, ${_DEPS})

${EXECUTABLE}: ${OBJS}
	${CC} -o $@ $^ ${CXXFLAGS}

${BUILD_DIR}/%.o: ${SRC_DIR}/%.cpp ${DEPS}
	${CC} -c -o $@ $< ${CXXFLAGS}

${BUILD_DIR}/main.o: main.cpp ${DEPS}
	${CC} -c -o $@ $< ${CXXFLAGS}

run: ${EXECUTABLE}
	./${EXECUTABLE}

.PHONY: clean

clean:
	-rm ${BUILD_DIR}/* ${EXECUTABLE}
