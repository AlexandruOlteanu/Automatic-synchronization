
build:
	g++ main.cpp -o main

run: 
	./main ${problem}

clean:
	rm -rf main