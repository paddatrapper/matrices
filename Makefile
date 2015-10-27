CC = g++
CXXFLAGS = -std=c++11 -I.
DEPS = libmatrix/matrix.h
EXECUTABLE = matrices
BUILD_DIR = build

_OBJS = matrix.o main.o
OBJS = $(patsubst %, ${BUILD_DIR}/%, ${_OBJS})

${BUILD_DIR}/%.o: %.cpp ${DEPS}
	${CC} -c -o $@ $< ${CXXFLAGS}

${EXECUTABLE}: ${OBJS}
	${CC} -o $@ $^ ${CXXFLAGS}

${BUILD_DIR}/matrix.o: libmatrix/matrix.cpp ${DEPS}
	${CC} -c -o $@ $< ${CXXFLAGS}


.PHONY: clean

clean:
	-rm ${BUILD_DIR}/* ${EXECUTABLE}
