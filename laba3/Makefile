CC := gcc

CFLAGS := -std=c99 -Wall -Werror -pedantic -ggdb

OBJS := mycstring.o func.o

main_prog.exe : $(OBJS) main_prog.o
	$(CC) -o main_prog.exe $(OBJS) main_prog.o

test.exe : $(OBJS) test.o
	$(CC) $^ -o $@

%.o : %.c *.h 
	$(CC) $(CFLAGS) -c $<

clean : 
	del *.o  