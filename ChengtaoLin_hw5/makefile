

OBJS = hw5.o driver.o
arg = -n 32 -s 2020 

CC = gcc 
FLAGS = -Wall 

clean : all
	rm -f $(OBJS) *.a  *.csv

all : driver 
	./driver $(arg)
	python plot.py


driver : $(OBJS)
	$(CC) $(FLAGS) -o $@ $^ -lm

%.o : %.c
	$(CC) $(FLAGS) -c -o $@ $<
