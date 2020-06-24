run: main.o tokenizer.o
	cc -o run main.o tokenizer.o

clean:
	rm -f *.o *.c~ run

tokenizer.o: tokenizer.h tokenizer.c

main.o: tokenizer.h main.c
