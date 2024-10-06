OBJS= uimain.o

CFLAGS= -g -O3

all: tokenizer

tokenizer: $(OBJS)
	cc -o tokenizer $(CFLAGS) $(OBJS)

$(OBJS): history.h tokenizer.h

clean:
	rm -f *.o tokenizer

run:tokenizer
	./tokenizer
