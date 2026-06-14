cmake_minimum_required(VERSION 3.19)
project(SoftwareDev_Exam LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

add_executable(SoftwareDev_Exam
    main.cpp

    character.cpp
    character.h

    monster.cpp
    monster.h

    game.cpp
    game.h

    battle.cpp
    battle.h

    status.cpp
    status.h

    statuseffect.cpp
    statuseffect.h

    item.cpp
    item.h

    cave.cpp
    cave.h
)

find_library(SQLITE3_LIBRARY sqlite3)

target_link_libraries(SoftwareDev_Exam PRIVATE ${SQLITE3_LIBRARY})
