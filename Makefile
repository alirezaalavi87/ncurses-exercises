straight: straight.c
	gcc straight.c -lncurses -o straight.out

circle: circle.c
	gcc circle.c -lncurses -lm -o circle.out

.PHONY: clean

clean:
	rm -f straight.out circle.out
