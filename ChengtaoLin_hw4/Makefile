exe = a.out
flags = -Wall -std=c99

run : $(exe)
	./$(exe) test.txt

$(exe): client.c
	gcc -o $@ $^ $(flags)

clear: rm a.out