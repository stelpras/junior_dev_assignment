CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra
LDFLAGS = -pthread

.PHONY: all test run clean

all: tests realtime_game

tests: Tennis.cpp tests.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

realtime_game: Tennis.cpp main.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@ $(LDFLAGS)

test: tests
	./tests

run: realtime_game
	./realtime_game

clean:
	rm -f tests realtime_game