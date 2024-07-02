#pragma once

#include "Args.h"

#ifndef _WIN32
#include <curses.h>
#include <locale.h>
#include "RandomChance.h"
#include "Repeat.h"
#include "Sigaction.h"
#include "ZeroMemory.h"

#define NCURSES_ERROR_IF(Condition) \
    if (Condition)                  \
    return false

static inline void createTop(char* dest, size_t width)
{
    int offset = sprintf(dest, "\u250F");
    repeat_count(width - 2) offset += sprintf(dest + offset, "\u2501");
    sprintf(dest + offset, "\u2513");
}

static inline void createBottom(char* dest, size_t width)
{
    int offset = sprintf(dest, "\u2517");
    repeat_count(width - 2) offset += sprintf(dest + offset, "\u2501");
    sprintf(dest + offset, "\u251B");
}

static inline bool heavy_border(WINDOW* window)
{
    const char* side = "\u2503";

    int height, width;
    getmaxyx(window, height, width);

    char buf[BUFSIZ];
    createTop(buf, width);
    NCURSES_ERROR_IF(mvwaddstr(window, 0, 0, buf) == ERR);
    repeat(height - 2)
    {
        NCURSES_ERROR_IF(mvwaddstr(window, i + 1, 0, side) == ERR);
        NCURSES_ERROR_IF(mvwaddstr(window, i + 1, width - 1, side) == ERR);
    }
    createBottom(buf, width);
    mvwaddstr(window, height - 1, 0, buf);

    return true;
}

static inline bool printGuruMessage(WINDOW* window)
{
    setlocale(LC_ALL, "");

    NCURSES_ERROR_IF(not initscr());
    NCURSES_ERROR_IF(raw() == ERR);
    NCURSES_ERROR_IF(noecho() == ERR);
    NCURSES_ERROR_IF(curs_set(false) == ERR);
    NCURSES_ERROR_IF(refresh() == ERR);

    const int red_color_index = COLOR_RED;
    const int default_background_color = -1;
    NCURSES_ERROR_IF(start_color() == ERR);
    NCURSES_ERROR_IF(use_default_colors() == ERR);
    NCURSES_ERROR_IF(init_pair(red_color_index, COLOR_RED, default_background_color) == ERR);

    mmask_t* ignore_old_mask = NULL;
    NCURSES_ERROR_IF(keypad(stdscr, true) == ERR);
    NCURSES_ERROR_IF(not(mousemask(BUTTON1_CLICKED, ignore_old_mask) & BUTTON1_CLICKED));

    const char* line1 = "   Software Failure.    Press left mouse button to continue.   ";
    const char* line2 = "              Guru Meditation #0000000C.48454C50               ";
    const size_t height = 4;
    const size_t width = strlen(line1) + 2;
    const int red = COLOR_PAIR(red_color_index);
    NCURSES_ERROR_IF(not(window = newwin(height, width, 0, (COLS - width) / 2)));
    NCURSES_ERROR_IF(wattrset(window, A_BLINK | red) == ERR);
    NCURSES_ERROR_IF(not heavy_border(window) and box(window, 0, 0) == ERR);
    NCURSES_ERROR_IF(wattrset(window, A_BOLD | red) == ERR);
    NCURSES_ERROR_IF(mvwaddstr(window, 1, 1, line1) == ERR);
    NCURSES_ERROR_IF(mvwaddstr(window, 2, 1, line2) == ERR);
    NCURSES_ERROR_IF(wrefresh(window) == ERR);

    return true;
}

static inline bool waitForLmb(void)
{
    int ch;
    MEVENT mevent;
    ZERO_MEMORY(&mevent);

    while (not(mevent.bstate == BUTTON1_CLICKED))
    {
        NCURSES_ERROR_IF((ch = getch()) == ERR);
        NCURSES_ERROR_IF(ch == KEY_MOUSE and getmouse(&mevent) == ERR);
    }

    return true;
}

static inline SigActionSignature(ignoreSignal)
{
    attrset(A_BLINK);
    mvaddstr(0, 0, "\u263a");
    refresh();
}

static inline void printGuru(const Args* args)
{
    if (argsContains(args, "--force_guru") or chance(1337))
    {
        installSigaction(SIGTERM, ignoreSignal);
        WINDOW* window = NULL;
        printGuruMessage(window) and waitForLmb();
        delwin(window);
        endwin();
    }
}
#else
inline void printGuru(const Args* args)
{
    (void)args;
}
#endif
