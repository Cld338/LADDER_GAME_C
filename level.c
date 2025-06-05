//#include "start.h"
#include "ladderPlayer.h"
#include "util.h"
#include "word.h"
#include "level.h"
#include "user.h"
#include <windows.h>
#include <stdio.h>

void game(struct USER* user, struct wordlist_ptr* wordlist_ptr, int mode, int level) {
    int ladder[ARR_SIZE][ARR_SIZE];
    int clear = 0;
    int total_score = 0;
    int run_clear;
    switch (mode) {
    case 0:
        printf("���: %s", "����");
        switch (level) {
        case 0:
            printf(", ����: %s", "�ʱ�");
            break;
        case 1:
            printf(", ����: %s", "�߱�");
            break;
        case 2:
            printf(", ����: %s", "���");
            break;
        }
    case 1:
        printf("���: %s", "����");
        break;
    }
    while (keyControl() != SUBMIT);
    system("cls");

    while (level < MAX_LEVEL - 1) {
        // ������ ���� �Լ��� ���Ƽ�, switch-case���� �ƴ϶� �ݺ������� ������ ������ ��
        create_ladder(ladder);
        system("cls");
        run_clear = run(ladder, wordlist_ptr, level);
        if (run_clear == 0) {
            system("cls");
            printf("Ŭ��� �����ϼ̽��ϴ�.");
            while (keyControl() != SUBMIT);
            return;
        }
        if (run_clear == 2) {
            return;
        }
        if (mode == 0) {                /* ���� ��� */
            if (level == 2) {
                system("cls");
                printf("Ŭ���� �ϼ̽��ϴ�.");
                while (keyControl() != SUBMIT);
                return;
            }
            clear = level_clear();      /* 1: ���, 2: �ߴ� */
            system("cls");
            if (clear == 1) {  /* ���� ������ */
                ++level;
                continue;
            }
            else {
                return;
            }
        }
        else {                          /* mode == 1, ���� ��� */
            ++level;                    /* �׳� ���� ������ */
            /* MAX_LEVEL �ʰ� �� Ż�� */
        }
    }
}


int level_clear() {
    char ch;
    system("cls"); printf("���� �ܰ赵 �����Ͻðڽ��ϱ�? (y: ���� �ܰ�, n: �޴�): ");
    while (1) {
        while ((ch = getchar()) == '\n');
        if (ch == 'y') {
            return 1;
        }
        else if (ch == 'n') {
            return 0;
        }
        else {
            printf("�ٽ� �Է��ϼ���: ");
        }
    }
}