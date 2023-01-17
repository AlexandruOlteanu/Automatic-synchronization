
build:
	g++ main.cpp -o main

run: 
	./main ${problem}

clean:
	rm -rf main

# CC = g++
# CFLAGS = -Wall -g

# all: build

# build: sync convert

# sync: sync.o
# 	$(CC) $(CFLAGS) -o $@ $^

# convert: convert.o
# 	$(CC) $(CFLAGS) -o $@ $^

# .PHONY: clean

# run: build
# 	./sync $(problem)

# labyrinth: build
# 	./convert

# clean:
# 	rm -f *.o *~ sync convert
