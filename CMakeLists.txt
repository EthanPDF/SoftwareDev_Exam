cmake_minimum_required(VERSION 3.19)
project(SoftwareDev_Exam LANGUAGES CXX)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core)

qt_standard_project_setup()

qt_add_executable(SoftwareDev_Exam
    main.cpp
    character.h character.cpp
    monster.h monster.cpp
    game.h game.cpp
    battle.h battle.cpp
    status.h status.cpp

)

target_link_libraries(SoftwareDev_Exam
    PRIVATE
        Qt::Core
)

include(GNUInstallDirs)

install(TARGETS SoftwareDev_Exam
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)
