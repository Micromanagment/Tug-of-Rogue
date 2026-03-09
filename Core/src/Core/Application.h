#pragma once

#include "Core.h"

namespace Game {
    class APPLICATION_API Application
    {
        public:
            Application();
            virtual ~Application();
            void Run();
    };

    Application* CreateApplication();
}