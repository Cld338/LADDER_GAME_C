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
        printf("Ż�⿡ �����߽��ϴ�.\n");
        printf("Ż�� ���� : .\n");
        for (int i = 0; i < 3; i++) printf("\n");
    }
    menuDraw();

    return 0;
}