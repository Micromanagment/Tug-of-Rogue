#pragma once

//#ifdef ART_PLATFORM_WINDOWS

extern Game::Application* Game::CreateApplication();

int main(int argc, char** argv)
{
    auto app = Game::CreateApplication();
    app->Run();
    delete app;
}


//#endif
