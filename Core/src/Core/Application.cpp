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
        cbreak();
        noecho();
        keypad(stdscr, TRUE);
        refresh();

        int c;
        while ((c = getch()) != 'q')
        {
            clear();
            printw("Pressed: %d ('%c')\n", c, c);
            printw("q to quit.\n");
            refresh();
        }

        endwin();
    }
}
