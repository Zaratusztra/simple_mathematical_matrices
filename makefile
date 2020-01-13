CFLAGS = -std=c++11

test: matrices_test.cpp matrices.h
	g++ -o $@.exe $(CFLAGS) $?