#include <ncurses.h>

static const unsigned char MINIMUM_X = 80;
static const unsigned char MINIMUM_Y = 24;

void init()
{
	initscr();

	int currX = getmaxx(stdscr);
	int currY = getmaxy(stdscr);

	printw("%d", currX);

	if (currX > MINIMUM_X || currY > MINIMUM_Y)
	{
		endwin();
		("Terminal size is too small");
	}

	keypad(stdscr, true);
}
