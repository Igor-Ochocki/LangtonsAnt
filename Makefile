compile:
	cc -c load_board.c
	cc -c ant.c
	cc -c print_board.c
	cc -c board_generator.c
	cc main.c ant.o load_board.o print_board.o board_generator.o
	rm -rf *.o
