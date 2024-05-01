find_package(Curses)

if (CURSES_FOUND)
    message(STATUS "Ncurses found ar ${CURSES_LIBRARIES}")
endif ()
