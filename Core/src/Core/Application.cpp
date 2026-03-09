#include "Application.h"
#include <ncurses.h>

namespace Game
{
    Application::Application()
    {
    }

    Application::~Application()
    {
    }
    void Application::Run()
    {
        initscr();
        cbreak();            // immediate key processing
        noecho();            // do not echo typed chars
        keypad(stdscr, TRUE);// enable arrow keys

        printw("Application started. Press 'q' to quit.\n");
        refresh();

        int c;
        while ((c = getch()) != 'q')  // press 'q' to exit
        {
            clear();
            printw("You pressed: %d ('%c')\n", c, c);
            printw("Press 'q' to quit.\n");
            refresh();
        }

        endwin();
    }
}
