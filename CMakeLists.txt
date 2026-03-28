cmake_minimum_required(VERSION 4.0)
project(project1)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include(FetchContent)
FetchContent_Declare(SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 3.0.2
        GIT_SHALLOW ON
        EXCLUDE_FROM_ALL
        SYSTEM)
FetchContent_MakeAvailable(SFML)

add_executable(main src/main.cpp
        src/Game.cpp
        header/Game.h
        src/UI.cpp
        header/UI.h
        src/UIElement.cpp
        header/UIElement.h
        src/UIEInteractable.cpp
        header/UIEInteractable.h
        src/snake.cpp
        header/snake.h
        src/grid.cpp
        header/grid.h
        src/apple.cpp
        header/apple.h)
target_compile_features(main PRIVATE cxx_std_17)
target_link_libraries(main PRIVATE SFML::System SFML::Graphics SFML::Window SFML::Audio SFML::Network)

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT main)


