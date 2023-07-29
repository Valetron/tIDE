//#include <string.h>

//#include <ncurses.h>

//#include "src/init.h"

//enum COLORS
//{
//    COLOR_PINK = 10
//};

//int main(int argc, char** argv)
//{
//	//raw();                 //Берём управление клавиатурой на себя
//	//cbreak();				// отменяет действие raw()
//    int ch;

//	//init();

//	initscr();
//	cbreak();
//	noecho();

//	int currX = getmaxx(stdscr);
//	int currY = getmaxy(stdscr);

//	if (currX < MINIMUM_X || currY < MINIMUM_Y)
//	{
//		puts("Terminal size is too small");
//		//exit_curses(1);
//		goto EXIT;
//	}

//	while ( (ch = getch()) != KEY_F(1))
//	{
//		switch (ch)
//		{
//		case KEY_ENTER:
//			//mvprintw(2, 2, "Pressed");
//			printw("Works");
//			refresh();
//			break;
		
//		default:
//			break;
//		}
//		//if (ARR)
//		if (KEY_ENTER == ch)
//		{
//			mvprintw(2, 2, "Pressed");
//			//move(getcury(stdscr) + 1, 0);
//			refresh();
//		}
//	}

//EXIT:
//	endwin();
//	return 0;
//}


#include <ncurses.h>

int main() {
    initscr();

    // disable line buffering and echoing of typed characters
    //cbreak();
	//raw();
    //noecho();

    // print a message and wait for a key press
    printw("Press Enter to move to a new line (Press 'q' to quit) ");
    refresh();

    int ch;
    while ((ch = getch()) != 27) {
        if (ch == '\n') {
            // move cursor to a new line
            move(getcury(stdscr) + 1, 0);
            refresh();
        }
    }

    endwin();

    return 0;
}