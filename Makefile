compile:
	cc -c load_board.c
	cc -c ant.c
	cc -c print_board.c
	cc main.c ant.o load_board.o print_board.o
	rm -rf *.o