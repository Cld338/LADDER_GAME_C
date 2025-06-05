#include <windows.h>
#include <conio.h>
#include "util.h"

void setColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
int keyControl() {
    char temp = _getch();

    if (temp == 'w' || temp == 'W') {
        return UP;
    }
    else if (temp == 'a' || temp == 'A') {
        return LEFT;
    }
    else if (temp == 'd' || temp == 'D') {
        return RIGHT;
    }
    else if (temp == 's' || temp == 'S') {
        return DOWN;
    }
    else if (temp == ' ') {
        return SUBMIT;
    }
}

void gotoxy(int x, int y) {
    COORD pos = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

// 커서 보이기
void show_cursor() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;

    GetConsoleCursorInfo(hConsole, &cursorInfo);
    cursorInfo.bVisible = TRUE;  // 보이도록 설정
    SetConsoleCursorInfo(hConsole, &cursorInfo);
}


void hide_cursor() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;

    GetConsoleCursorInfo(hConsole, &cursorInfo);
    cursorInfo.bVisible = FALSE;  // 보이지 않도록 설정
    SetConsoleCursorInfo(hConsole, &cursorInfo);
}


int handleInput(char* input, int* i) {
    if (_kbhit()) {
        char ch = _getch();
        if (ch == '\r') {
            input[*i] = '\0';
            return 1; // 입력 완료
        }
        else if (ch == '\b' && *i > 0) {
            (*i)--;
            input[*i] = '\0';
            gotoxy(*i, 1);
            printf(" ");
            gotoxy(*i, 1);
        }
        else if (*i < MAX_INPUT - 1 && ch >= 32 && ch <= 126) {
            input[*i] = ch;
            gotoxy(*i, 1);
            printf("%c", ch);
            (*i)++;
        }
    }
    return 0;
}
#include <string.h>

char* char_mul(const char* s, int k)
{
    static char result[30];
    result[0] = '\0';

    if (!s || k <= 0) return result;

    const size_t seg_len = strlen(s);
    if (seg_len == 0) return result;

    const size_t max_repeat = (sizeof(result) - 1) / seg_len;
    const size_t repeat = (size_t)k < max_repeat ? (size_t)k : max_repeat;

    /* strcat을 repeat 번 호출 */
    for (size_t i = 0; i < repeat; ++i) {
        strcat(result, s);
    }

    return result;
}

//void wait_key(char key, int isSpecial) {
//    char a;
//    while (1) {
//        a = _getch();
//        if (isSpecial) {
//            if ((a == 224) && (_getch() == key)) {
//                return;
//            }
//        }
//        else {
//            if (a == key) {
//                return;
//            }
//        }
//    }
//}