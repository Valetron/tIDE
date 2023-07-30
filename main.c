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


//#include <ncurses.h>

//int main() {
//    initscr();

//    // disable line buffering and echoing of typed characters
//	raw();
//    //cbreak();
//    //noecho();

//    // print a message and wait for a key press
//    printw("Press Enter to move to a new line (Press 'q' to quit) ");
//    //refresh();
//    int ch;
//	char w = 1;
//    //while ((ch = getch()) != 27)
//	while (w)
//	{
//		cbreak();
//		ch = getch();
//        if (ch == '\n') {
//            // move cursor to a new line
//            move(getcury(stdscr) + 1, 0);
//            refresh();
//        }

//		if (ch == ('s' & 0x1f))
//			mvprintw(getcury(stdscr) + 1, 0, "Ctrl-S");

//		if (ch == ('q' & 0x1f))
//			w = 0;
		
//		raw();
//	}

//    endwin();

//    return 0;
//}




#include <ncurses.h>

int main() {
    // Initialize ncurses
    initscr();
    raw();  // Use raw() mode for low-level input
    noecho();
	keypad(stdscr, true);

    // Loop until the user presses Ctrl-C or Ctrl-Z
    bool running = true;
    while (running)
	{
        // Switch to cbreak() mode temporarily
        cbreak();
        int ch = getch();
        // Switch back to raw() mode
        raw();

        switch (ch)
		{
            case ('s' & 0x1f): // Ctrl-S
                mvprintw(getcury(stdscr) + 1, 0, "Ctrl-S");
                break;
            case ('c' & 0x1f): // Ctrl-C
                running = false;
                break;
            case KEY_RESIZE:
                // Handle window resize event
                break;
            case ERR:
                // Handle input timeout
                break;
			case KEY_BACKSPACE:
			case 127:
				mvdelch(getcury(stdscr), getcurx(stdscr) - 1);
				break;
			case KEY_UP:
				move(getcury(stdscr) - 1, getcurx(stdscr));
				break;
			case KEY_DOWN:
				move(getcury(stdscr) + 1, getcurx(stdscr));
				break;
			case KEY_LEFT:
				move(getcury(stdscr), getcurx(stdscr) - 1);
				break;
			case KEY_RIGHT:
				move(getcury(stdscr), getcurx(stdscr) + 1);
				break;
            default:
                // Handle other input events
				printw("%c", ch);
                break;
        }
    }

    // Clean up ncurses
    endwin();

    return 0;
}