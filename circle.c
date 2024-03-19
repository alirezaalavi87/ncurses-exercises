/**
  A ball within a box that moves in a circle
   the standard formula for drawing a circle with the center (a,b) with radius
   r: (x−a)^2 + (y−b)^2 = r^2
 */

#include <math.h>
#include <ncurses.h>
#include <stdio.h>
#include <unistd.h>

#define DELAY 30000

struct coordinates {
  float x, y;
};

// typedef struct coordinates Struct;

// TODO I feel like the direction shouldn't be a part of this function because
// this function has to be pure mathematically. what to do?
/**
 * returns y of point on circle, given , the center coordinates and radius, for
 * given x int center_x, center_y : coordinates for the center int x : the x of
 * the point on the circle int r : the radius of the circle
 * int direction : whether return y for lower half of the circle (direction = 1)
 *or upper half (direction = -1)
 **/
float calc_circle(int center_x, int center_y, int x, int r, int direction) {
  float y;

  // NOTE according to the equation:
  // y = b +- sqrt[r^2 - (x-a)^2]

  // if (x > 0) {
  //   y = center_y + (sqrt(pow(r, 2) - pow((x - center_x), 2)));
  // } else {
  //   y = center_y - (sqrt(pow(r, 2) - pow((x - center_x), 2)));
  // }

  y = center_y + (sqrt(pow(r, 2) - pow((x - center_x), 2))) * direction;

  return y;
}

int main(int argc, char *argv[]) {
  int max_win_x = 0, max_win_y = 0;
  char str_x[10], str_y[10];
  int center_x, center_y; // coordinates of the center of the screen
  int direction = 1;
  float next_x;     // the next value for x
  const int r = 10; // radius of circle
  struct coordinates point;

  initscr(); // Initialize ncurses screen
  noecho();
  curs_set(FALSE);

  getmaxyx(stdscr, max_win_y, max_win_x);
  center_x = max_win_x / 2;
  center_y = max_win_y / 2;
  // printf("center: (%i, %i)\n", center_x, center_y);

  // initial values for xy
  point.x = center_x + r;
  // point.y = calc_circle(center_x, center_y, point.x, r);

  // let it spin
  while (1) {
    // round to avoid floats and uneven look to the circle
    point.y = round(calc_circle(center_x, center_y, point.x, r, direction));
    // draw circle and center
    mvprintw(center_y, center_x, "x");
    mvprintw(point.y, point.x, "o");
    // printf("X: %f,Y: %f\n", point.x,
    //        round(calc_circle(center_x, center_y, point.x, r, direction)));

    // print values of x,y
    // convert the int to a string
    sprintf(str_y, "%f", point.y);
    sprintf(str_x, "%f", point.x);
    // printf("X: %f , Y: %f\n", x, y);
    mvprintw(0, 0, "Y: %s, X: %s", str_y, str_x);
    refresh();
    // comment clear() to see the full circle
    clear();

    // check the next position of x
    next_x = point.x + direction;
    // NOTE center_y - r <= y <= center_y + r && center_x - r <= x <= center_x +
    // r change direction when hit the limits
    if (next_x > center_x + r || next_x < center_x - r) {
      direction = direction * -1;
    } else {
      point.x += direction;
    }

    usleep(DELAY);
  }
  endwin();
}
