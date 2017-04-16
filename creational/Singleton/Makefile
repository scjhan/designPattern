CXXFLAGS = -g -std=c++11 -O0 -Wall
LDFLAGS = -lpthread

all: main #$@

clean:
	rm -rf main core

main: Singleton.h SingletonWithThreadSafe.h main.cc  #$^
	g++ $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

.PHONY:
	all clean
