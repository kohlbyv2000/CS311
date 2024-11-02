

gfsarray: gfsarray.hpp
	g++ -std=c++17 -Wall -Wextra gfsarray.hpp gfsarray_test.cpp -o gfsarray

clean:
	rm -f gfsarray *.o

.PHONY: all clean