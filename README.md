## What a snake game needs

- define a border for the game
- draw a snake 
- snake moves one tile on each tick
- get user input
- snake changes direction
- if snake collides with itself or the borders game over
- generate apple at random places within the borders
- if snake collides with apple(eats it), another apple will be spawned and snake's length will be +1

These are a set of practices I did for getting more comfortable with the C language
and ncurses.

it includes:
- `straight.c` : a ball within a box that moves on the x axis and bounces off the walls
    to compile and run: `make straight && ./straight.out`
- `circle.c` : a ball within the screen that moves in a circle
    to compile and run: `make circle && ./circle.out`
