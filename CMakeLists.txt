cmake_minimum_required(VERSION 2.6)
project(EERTR)
SET(CMAKE_CXX_FLAGS_DEBUG "-Wall -ggdb -lSDL -lGL -lGLU -lAntTweakBar")
SET(CMAKE_CXX_FLAGS_RELEASE "-Wall -o3 -lSDL -lGL -lGLU -lAntTweakBar")
find_package(PkgConfig)
find_package(wxWidgets COMPONENTS base core REQUIRED)
add_definitions(${wxWidgets_DEFINITIONS})
#pkg_check_modules(GTKMM gtkmm-2.4)
add_subdirectory(src)