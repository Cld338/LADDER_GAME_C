#include "ladder.h"
#include "util.h"
#include "word.h"
#include "ladderPlayer.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <windows.h>
#include <conio.h>


void mark_player(int row, int col) {
    int x = 0;
    int y = 0;
    x = (col / 2) * (1 + HORIZONTAL_LENGTH) + col % 2;
    y = (row / 2) * (1 + VERTICAL_LENGTH) + row % 2;
    gotoxy(x, y);
    setColor(2);
    printf("●");
    setColor(15);
}


int run(int (*map)[ARR_SIZE][ARR_SIZE], struct WORDLIST* wordlist, int level) {
    double elapsed;
    double remaining;
    int ch;
    int x = 0, y = ARR_SIZE - 1;
    int dx, dy;
    print_ladder(map);
    gotoxy(0, 0);
    mark_player(y, x);
    clock_t start = clock();
    int i = 0;
    double time_limit;
    switch (level) {
    case 0: time_limit = CHO_TIME_LIMIT; break;
    case 1: time_limit = JONG_TIME_LIMIT; break;
    case 2: time_limit = GO_TIME_LIMIT; break;
    }
    while (1) {
        elapsed = (double)(clock() - start) / CLOCKS_PER_SEC;
        remaining = time_limit - elapsed;
        gotoxy(35, 0);
        printf("남은 시간: %.2f초   ", remaining);
        if (remaining <= 0.0) {
            system("cls");
            int i = 20, j = 10;

            gotoxy(i, j);
            printf("시간 초과");

            gotoxy(0, 0);
            return 0;
        }
        if (_kbhit()) ch = _getch();
        else continue;
        
        
        dx = 0;
        dy = 0;
        if (ch == 224) {
            ch = _getch();
            switch (ch) {
            case 72: dy = -1; break; // ↑
            case 80: dy = 1;  break; // ↓
            case 75: dx = -1; break; // ←
            case 77: dx = 1;  break; // →
            }
        }
        if (ch == 27) {
            system("cls");
            setColor(14);
            printf("메뉴로 돌아가시겠습니까? (y/n): ");
            while (1) {
                while ((ch = getchar()) == '\n');
                if (ch == 'y') {
                    setColor(15);
                    return 2;
                }
                else if (ch == 'n') {
                    start = clock() - elapsed * CLOCKS_PER_SEC;
                    system("cls");
                    setColor(15);
                    gotoxy(0, 0);
                    print_ladder(map);
                    mark_player(y, x);
                    break;
                }
                else {
                    printf("다시 입력하세요: ");
                }
            }
        }
            
        if (dx == 0 && dy == 0) continue;
        int nx = x + dx;
        int ny = y + dy;

        if (nx < 0 || nx >= ARR_SIZE || ny < 0 || ny >= ARR_SIZE)
            continue;
        int next = (*map)[ny][nx];
        if ((next == 1) || (next == 2)) {
            show_cursor();
            int target_score;
            if (next == 1) target_score = 1;
            else if (next == 2) target_score = 3;
            system("cls");
            if (practice(wordlist, level, target_score, start, time_limit) == 1) {
                (*map)[ny][nx] = 1;
                print_ladder(map);
                hide_cursor();
                x = nx + dx;
                y = ny + dy;
                mark_player(y, x);
            }
            else {
                continue;
            }
            if (y == 0 && x == ARR_SIZE - 1) {
                return 1;
            }
        }
        else {
            continue;
        }
    }
}
