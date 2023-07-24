#include <string.h>

#include <ncurses.h>

#include "src/init.h"

enum COLORS
{
    COLOR_PINK = 10
};

int main(int argc, char** argv)
{
	//raw();                 //Берём управление клавиатурой на себя
	//cbreak();				// отменяет действие raw()
    int ch;

	init();

	while ( (ch = getch()) != 27)
	{
		if (KEY_ENTER == ch)
		{
			mvprintw(2, 2, "Pressed");
			//move(getcury(stdscr) + 1, 0);
			refresh();
		}
	}

	endwin();
	return 0;
}
