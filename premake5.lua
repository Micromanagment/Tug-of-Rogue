workspace "Rogue"
    configurations {"Debug", "Release"}
    architecture "x64"

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"
IncludeDir = {}
IncludeDir["ncurses"] = "Core/vendor"

--include "another premake5 path"

project "Core" --Name should be of folder containing the so
    location "Core/src"
    kind "SharedLib"
    language "C++"

    targetdir ("bin/" ..outputdir.. "/%{prj.name}")
    objdir ("bin-int/" ..outputdir.. "/%{prj.name}")

    --pchheader "file.h"
    --pchsource "folder/folder/file.cpp"

    files
    {
        "%{prj.name}/**.h",
        "%{prj.name}/**.cpp"
    }

    includedirs
    {
        "%{prj.name}",
        "%{prj.name}/vendor/ncurses/include"
      --"%{IncludeDir.ncurses}"
    }

    links
        {
            "ncurses"
        }

filter "system:linux"
    cppdialect "c++20"

    defines --Macros
    {
        "APP_PLATFORM_LINUX",
        "APP_BUILD_SO"
    }

    postbuildcommands
    {
        "cp %{cfg.buildtarget.abspath} ../bin/" .. outputdir .. "/App"
    }

    filter "configurations:Debug"
        defines "DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "RELEASE"
        optimize "On"

project "App"
    location "App"
    kind "ConsoleApp"

    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "Core/include",
        "Core/src",
        "Core/vendor/ncurses/include"
    }

    links
    {
        "Core"
    }

    filter "system:linux"
        cppdialect "C++20"

        defines
        {
            "APP_PLATFORM_LINUX"
        }

        postbuildcommands
        {
            "echo Running",
            "./bin/" .. outputdir .. "/App/App"
        }
	filter "configurations:Debug"
		defines "APP_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "APP_RELEASE"
		optimize "On"
