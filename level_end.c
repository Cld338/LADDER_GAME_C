#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include "util.h"
#include "startScreen.h"

void ClearDraw() {
    char key = _getch();
    while (key != "\n") {
        for (int i = 0; i < 3; i++) printf("\n");

        for (int i = 0; i < 50; i++) printf(" ");
        setColor(14);
        printf("탈출에 성공했습니다.\n");
        printf("탈출 점수 : .\n");
        for (int i = 0; i < 3; i++) printf("\n");
    }
    menuDraw();

    return 0;
}