#include "util.h"
#include "startScreen.h";
#include "user.h"
#include "GameInfo.h";
#include "loginScreen.h";

#include <stdio.h>
#include <windows.h>
#include <conio.h>


void titleDraw() {

    for (int i = 0; i < 3; i++) printf("\n");

    for (int i = 0; i < 50; i++) printf(" ");
    setColor(14);
    printf("사다리 탈출 게임\n");


    for (int i = 0; i < 3; i++) printf("\n");
    setColor(15);
}


int menuDraw() {   
    int menu;
    int x = 54;
    int y = 10;
    setColor(14);
    gotoxy(x - 1, y);
    printf(">게임시작");
    gotoxy(x, y+1);
    printf("게임정보");
    gotoxy(x, y+2);
    printf("  종료  ");
    while (1) {
        int n = keyControl();
        switch (n) {
        case UP: 
            if (y > 10) {
                gotoxy(x - 1, y);
                printf(" ");
                gotoxy(x - 1, --y);
                printf(">");
            }
            break;
        
        case DOWN:
            if (y < 12) {
                gotoxy(x - 1, y);
                printf(" ");
                gotoxy(x - 1, ++y);
                printf(">");
            }
            break;
        
        case SUBMIT:
            menu = y - 10;
            break;
        }
        if (n == SUBMIT) break;
    }

    if (menu == 0) {
        system("cls");
        show_cursor();
        return 1;
        
    }
    else if (menu == 1) {
        system("cls");
        GameInfo();      // 게임방법 화면으로
        while (keyControl() != SUBMIT); // 스페이스를 받을 때 까지
        system("cls");
        return menuDraw();
    }
    else if (menu == 2) {
        system("cls");
        setColor(15);
        return 0;
    }


}



