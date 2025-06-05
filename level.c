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
        printf("모드: %s", "연습");
        switch (level) {
        case 0:
            printf(", 레벨: %s", "초급");
            break;
        case 1:
            printf(", 레벨: %s", "중급");
            break;
        case 2:
            printf(", 레벨: %s", "고급");
            break;
        }
    case 1:
        printf("모드: %s", "실전");
        break;
    }
    while (keyControl() != SUBMIT);
    system("cls");

    while (level < MAX_LEVEL - 1) {
        // 레벨에 따라 함수가 같아서, switch-case문이 아니라 반복문으로 돌려도 괜찮을 듯
        create_ladder(ladder);
        system("cls");
        run_clear = run(ladder, wordlist_ptr, level);
        if (run_clear == 0) {
            system("cls");
            printf("클리어에 실패하셨습니다.");
            while (keyControl() != SUBMIT);
            return;
        }
        if (run_clear == 2) {
            return;
        }
        if (mode == 0) {                /* 연습 모드 */
            if (level == 2) {
                system("cls");
                printf("클리어 하셨습니다.");
                while (keyControl() != SUBMIT);
                return;
            }
            clear = level_clear();      /* 1: 통과, 2: 중단 */
            system("cls");
            if (clear == 1) {  /* 다음 레벨로 */
                ++level;
                continue;
            }
            else {
                return;
            }
        }
        else {                          /* mode == 1, 실전 모드 */
            ++level;                    /* 그냥 다음 레벨로 */
            /* MAX_LEVEL 초과 시 탈출 */
        }
    }
}


int level_clear() {
    char ch;
    system("cls"); printf("다음 단계도 도전하시겠습니까? (y: 다음 단계, n: 메뉴): ");
    while (1) {
        while ((ch = getchar()) == '\n');
        if (ch == 'y') {
            return 1;
        }
        else if (ch == 'n') {
            return 0;
        }
        else {
            printf("다시 입력하세요: ");
        }
    }
}