cmake_minimum_required(VERSION 3.19)
project(SoftwareDev_Exam LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

add_executable(SoftwareDev_Exam
    main.cpp
    character.cpp
    monster.cpp
    game.cpp
    battle.cpp
    status.cpp
    statuseffect.cpp
    item.cpp
    cave.cpp
)
