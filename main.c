#include "startScreen.h"
#include "loginScreen.h"
#include "GameInfo.h"
#include "user.h"
#include "ladder.h"
#include "ladderPlayer.h"
#include "util.h"
#include "word.h"
#include "level.h"
#include "selectGameScreen.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>


#include <conio.h>

int main(void) {
    struct User* user;
    struct WORDLIST wordlist;
    int mode, level = 0;
    int ladder[ARR_SIZE][ARR_SIZE];
    int i = 20, j = 10;
    make_list(&wordlist);
    srand(time(NULL));  
    hide_cursor(); // 커서 숨기기
    setColor(14);
    gotoxy(i, j++);
    printf("    __    ___    ____  ____  __________     ___________ _________    ____  ______\n"); gotoxy(i, j++);
    printf("   / /   /   |  / __ \\/ __ \\/ ____/ __ \\   / ____/ ___// ____/   |  / __ \\/ ____/\n"); gotoxy(i, j++);
    printf("  / /   / /| | / / / / / / / __/ / /_/ /  / __/  \\__ \\/ /   / /| | / /_/ / __/   \n"); gotoxy(i, j++);
    printf(" / /___/ ___ |/ /_/ / /_/ / /___/ _, _/  / /___ ___/ / /___/ ___ |/ ____/ /___   \n"); gotoxy(i, j++);
    printf("/_____/_/  |_/_____/_____/_____/_/ |_|  /_____//____/\\____/_/  |_/_/   /_____/   \n"); gotoxy(0, 0);
    setColor(15);
    while (keyControl() != SUBMIT);
    while (1) {
        system("cls");
        titleDraw(); // 제목 출력
        if (menuDraw()==0) break;
        system("cls");
        hide_cursor();
        mode = selectMode(); // 연습 0, 실전 1
        system("cls");
        if (mode == 0) {
            system("cls");
            level = selectLevel(); // 초급 0, 중급 1, 고급 2
        }
        else if (mode == 1) {
            system("cls");
            user = loginScreen();
            while (keyControl() != SUBMIT);
        }
        system("cls");
        
        game(&user, &wordlist, mode, level);
    }
    return 0;
}


