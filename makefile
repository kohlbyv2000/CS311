

gfsarray: gfsarray.hpp
	g++ -std=c++17 -Wall -Wextra gfsarray.hpp -o gfsarray

clean:
	rm -f gfsarray *.o

.PHONY: all clean