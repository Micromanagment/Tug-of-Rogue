#include "Application.h"
#include <ncurses.h>
#include <iostream>
#include "Event.h"
#include "Player.h"
#include <fstream>
#include <string>

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
        std::ofstream logFile("logs/app.log", std::ios::trunc);

        initscr();
        cbreak();
        noecho();
        keypad(stdscr, TRUE);
        refresh();

        int yMax, xMax;
        getmaxyx(stdscr, yMax, xMax);

        WINDOW* playwin = newwin(20,50,(yMax/2)-10, 10);
        box(playwin, 0, 0);
        refresh();
        wrefresh(playwin);
        int ch;
        Player* p = new Player(playwin, 1, 1, '@');
        while((ch = p->getmv()) != 'x')
        {
            logFile << "Pressed: " << static_cast<char>(ch) << std::endl << std::flush;
            p->display();
            wrefresh(playwin);
        }
        delwin(playwin);
        endwin();
    }
}
