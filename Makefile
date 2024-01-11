compile: prerequisities
	cc main.c ant.o load_board.o print_board.o board_generator.o helpers.o -lm
	rm -rf *.o
	rm -rf output/*

prerequisities: 
	cc -c load_board.c
	cc -c ant.c
	cc -c print_board.c
	cc -c board_generator.c
	cc -c helpers.c

debug: prerequisities
	cc -ggdb main.c ant.o load_board.o print_board.o board_generator.o helpers.o -lm
	rm -rf *.o
	rm -rf output/*
