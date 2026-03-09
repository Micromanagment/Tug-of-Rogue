#include "EntryPoint.h"

class App : public Game::Application
{
    public:
    App()
    {

    }
    ~App()
    {

    }
};

Game::Application* Game::CreateApplication()
{
    return new App();
}
//
