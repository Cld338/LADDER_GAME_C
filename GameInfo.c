#include <stdio.h>
#include <windows.h>
#include "util.h"


void GameInfo() {
    int i;
    printf("%s", char_mul("\n", 3));

    printf("%s", char_mul(" ", 50));
    setColor(14);
    printf("게임방법 설명\n\n");
    printf("1.방향키를 이용해 사다리를 타고 올라가는데, 중간에 마주치는 장애물들은 타자를 쳐서 피해가야 합니다.\n");
    printf("2.탈출구까지 도착해야하는 시간이 정해져 있으며, 이는 난이도 별로 다를 수 있습니다.\n");
    printf("3.중간에 색깔이 다른 기호는 보석이며, 사용자는 보석을 얻기 위해 타자를 입력해야 합니다. 보석을 얻으면 점수를 획득합니다.\n");
    printf("4.게임은 실전게임, 연습게임으로 나뉘어 있습니다.\n");
    printf("  실전게임:초급,중급,고급 난이도의 게임을 차례로 수행하여 게임을 클리어하는 것으로 실제 점수가 기록됩니다.\n");
    printf("  연습게임:초급,중급,고급 난이도의 게임 중 하나를 선택하여 자유롭게 연습할 수 있으며 점수가 기록되지 않습니다.\n");
    printf("%s", char_mul("\n", 3));
    setColor(15);
}