#include <ncurses.h>
#include "Event.h"


namespace Game
{
    void Inputs::get_input()
    {
        switch(getch()) {
            case 'w':
                printw("W was pressed");
                break;
            case 's':
                printw("S was pressed");
                break;
            case 'a':
                printw("A was pressed");
                break;
            case 'd':
                printw("D was pressed");
                break;
        }
    }
}
