#include "Application.h"
#include <ncurses.h>
#include <iostream>
#include "Event.h"

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

        while(true)
        {
            Inputs::get_input();
            refresh();
        }
        endwin();
    }
}
