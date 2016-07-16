CC=gcc
CFLAGS=-I.
DEPS = header.h
OBJ = pr.o prc.o  secondForm.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

hw2: $(OBJ)
	gcc -o $@ $^ $(CFLAGS)





