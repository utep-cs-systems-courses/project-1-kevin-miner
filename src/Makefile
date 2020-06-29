run: main.o tokenizer.o history.o
	cc -o run main.o tokenizer.o history.o

clean:
	rm -f *.o *.c~ run

tokenizer.o: tokenizer.h tokenizer.c

history.o : history.h history.c

main.o: tokenizer.h main.c history.h
