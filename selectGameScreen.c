// ���� ���, ���̵� �����ΰ�??
#include "util.h"
#include <stdio.h>

int selectMode() {
    int x = 54;
    int y = 10;
    setColor(14);
    gotoxy(x - 1, y);
    printf(">����");
    gotoxy(x, y + 1);
    printf("��ũ");
    while (1) {

        int n = keyControl();
        switch (n) {
        case UP: {
            if (y > 10) {
                gotoxy(x - 1, y);
                printf(" ");
                gotoxy(x - 1, --y);
                printf(">");
            }
            break;
        }
        case DOWN: {
            if (y < 11) {
                gotoxy(x - 1, y);
                printf(" ");
                gotoxy(x - 1, ++y);
                printf(">");
            }
            break;
        }
        case SUBMIT: {
            return y - 10;
        }
        }
    }
    setColor(15);
}

int selectLevel() {
    int x = 54;
    int y = 10;
    setColor(14);
    gotoxy(x - 1, y);
    printf(">�ʱ�");
    gotoxy(x, y + 1);
    printf("�߱�");
    gotoxy(x, y + 2);
    printf("���");
    while (1) {

        int n = keyControl();
        switch (n) {
        case UP: {
            if (y > 10) {
                gotoxy(x - 1, y);
                printf(" ");
                gotoxy(x - 1, --y);
                printf(">");
            }
            break;
        }
        case DOWN: {
            if (y < 12) {
                gotoxy(x - 1, y);
                printf(" ");
                gotoxy(x - 1, ++y);
                printf(">");
            }
            break;
        }
        case SUBMIT: {
            setColor(15);
            return y - 10;
        }
        }
    }
}