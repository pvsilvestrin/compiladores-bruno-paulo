#set SUFFIX= for unix and SUFFIX=.exe for dos
SUFFIX=.exe

CFLAGS=-O

all: a2i$(SUFFIX)

a2i.c: a2i.y
	bison --output=a2i.c a2i.y

a2i$(SUFFIX): a2i.c
	$(CC) $(CFLAGS) -o a2i$(SUFFIX) a2i.c
	strip a2i$(SUFFIX)


clean:
	rm -f a2i.o *.bak a2i$(SUFFIX)
