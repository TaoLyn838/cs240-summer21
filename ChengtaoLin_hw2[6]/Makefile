exe = a.out
flags = -Wall -std=c99

run : $(exe)
	./$(exe) < CompleteShakespeare.txt 

$(exe): HistogramofWordLengths.c
	gcc -o $@ $^ $(flags)