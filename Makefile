CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra

.PHONY: test clean

tests: Tennis.cpp tests.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

test: tests
	./tests

clean:
	rm -f tests realtime_game