// A ball within a box that moves in a straight line and bounces off the walls
// sources:
// https://www.viget.com/articles/game-programming-in-c-with-the-ncurses-library/
// https://dev.to/tbhaxor/windows-in-ncurses-part-3-2e4

#include <ncurses.h>
#include <unistd.h>

#define DELAY 30000

int main(int argc, char *argv[]) {
  int x = 0, y = 0;
  int max_x = 0, max_y = 0;
  int next_x = 0;
  int direction = 1;

  initscr();
  noecho();
  curs_set(FALSE);

  // Global var `stdscr` is created by the call to `initscr()`
  // Put getmaxyx inside loop to repond to window resize
  getmaxyx(stdscr, max_y, max_x);
  clear(); // fully clear screen

  int max_x_ballbox = max_x - 10;
  int max_y_ballbox = max_y - 10;

  // creating window
  WINDOW *ballbox = newwin(max_y_ballbox, max_x_ballbox, 5, 5);
  refresh();

  while (1) {
    // making the box border with default border styles
    box(ballbox, 0, 0);

    mvwprintw(ballbox, y, x, "o");
    wrefresh(ballbox);

    usleep(DELAY); // shorter delay between movement

    next_x = x + direction;

    // change direction when hit the wall
    if (next_x >= max_x_ballbox || next_x < 0) {
      direction = direction * -1;
    } else {
      x += direction;
    }
  }

  endwin(); // Restore normal window
}
