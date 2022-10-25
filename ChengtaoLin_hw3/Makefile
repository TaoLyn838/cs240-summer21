exe = a.out
flags = -Wall -std=c99

run : $(exe)
	./$(exe) str.txt num.txt

$(exe): driver.c
	gcc -o $@ $^ $(flags)