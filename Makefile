CC = gcc
CFLAGS = -Wall -Werror
CFLAGS_TEST = -I T -Wall -Werror
EXECUTABLE = ./bin/Keyboard2
EXECUTABLE_TEST = ./bin/test
OBJECTS = ./built/R_a_W.o ./built/profile.o ./built/menu.o ./built/rating.o ./built/scene.o ./built/training.o ./built/main.o ./built/mode.o ./built/choice.o 
OBJECTS_TEST = ./built/R_a_W.o ./built/profile.o ./built/menu.o ./built/rating.o ./built/scene.o ./built/training.o ./built/test/main.o ./built/mode.o ./built/choice.o ./built/test/tests.o 

all: support_files bin/Keyboard2 bin/test
.PHONY: support_files run run_test clean

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

./built/menu.o: ./src/menu.c
	$(CC) $(CFLAGS) -o $@ -c $^

./built/R_a_W.o: ./src/R_a_W.c
	$(CC) $(CFLAGS) -o $@ -c $^

./built/profile.o: ./src/profile.c
	$(CC) $(CFLAGS) -o $@ -c $^

./built/rating.o: ./src/rating.c
	$(CC) $(CFLAGS) -o $@ -c $^

./built/scene.o: ./src/scene.c
	$(CC) $(CFLAGS) -o $@ -c $^

./built/training.o: ./src/training.c
	$(CC) $(CFLAGS) -o $@ -c $^

./built/main.o: ./src/main.c
	$(CC) $(CFLAGS) -o $@ -c $^

./built/mode.o: ./src/mode.c
	$(CC) $(CFLAGS)  -o $@ -c $^

./built/choice.o: ./src/choice.c
	$(CC) $(CFLAGS)  -o $@ -c $^

$(EXECUTABLE_TEST): $(OBJECTS_TEST)
	$(CC) $(CFLAGS_TEST) -o $@ $^

./built/test/main.o: ./test/main.c
	$(CC) $(CFLAGS_TEST) -o $@ -c $^

./built/test/tests.o: ./test/tests.c
	$(CC) $(CFLAGS_TEST) -o $@ -c $^

support_files: 
	touch ./data/PROF.txt
	touch ./data/RAT.txt

run: 
	./bin/Keyboard2

run_test: 
	./bin/test

clean: 
	rm ./built/*.o
	rm ./built/test/*.o
	rm ./bin/*
	rm ./data/RAT.txt 
	rm ./data/PROF.txt
