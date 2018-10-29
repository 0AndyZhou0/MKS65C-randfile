all : random.c
	gcc -o random random.c

run : ./random
	./random
