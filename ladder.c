#include "ladder.h" 
#include "util.h" 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void check_ladder(int (*ladder_ptr)[ARR_SIZE][ARR_SIZE]) {
    for (int i = 0; i < ARR_SIZE; i++) {
        for (int j = 0; j < ARR_SIZE; j++) {
            printf("%d ", (*ladder_ptr)[i][j]);
        }
        printf("\n");
    }
}

void random_ladder(int* ptr) {
    if (rand() % 4 == 0) {
        *ptr = 2;
    }
    else {
        *ptr = 1;
    }
}

void make_path(int (*ladder_ptr)[ARR_SIZE][ARR_SIZE], int row, int col) {
    int pos_row = ARR_SIZE - 1;
    int pos_col = 0;
    while (1) {
        if (pos_row == row && pos_col == col) {
            break; // 경로 완성
        }
        int can_move_up = (pos_row > row);     // 위로 이동 가능
        int can_move_right = (pos_col < col); // 오른쪽으로 이동 가능
        if (!can_move_up && !can_move_right) {
            break;
        }
        int moved_this_iteration = 0;
        if (rand() % 2 == 0) { // 0이 나오면: 위로 우선 이동 시도
            if (can_move_up) {
                pos_row--;
                if (pos_row >= row) {
                    pos_row--;
                }
                else {
                    pos_row++;
                }
            }
            else if (can_move_right) { // 위로 이동할 수 없다면 오른쪽으로 이동 시도
                pos_col++;
                if (pos_col <= col) {
                    (*ladder_ptr)[pos_row][pos_col] = 1;
                    pos_col++;
                }
                else {
                    pos_col--;
                }
            }
        }
        else { // 1이 나오면: 오른쪽으로 우선 이동 시도
            if (can_move_right) {
                pos_col++;
                if (pos_col <= col) {
                    (*ladder_ptr)[pos_row][pos_col] = 1;
                    pos_col++;
                }
                else {
                    pos_col--;
                }
            }
            else if (can_move_up) { // 오른쪽으로 이동할 수 없다면 위로 이동 시도
                pos_row--;
                if (pos_row >= row) {
                    (*ladder_ptr)[pos_row][pos_col] = 1;
                    pos_row--;
                }
                else {
                    pos_row++;
                }
            }
        }
        if (!moved_this_iteration && (can_move_up || can_move_right)) {
        }
    }
}


void put_gem(int (*ladder_ptr)[ARR_SIZE][ARR_SIZE]) {
    int gem_count = 0;
    int row, col;
    while (gem_count < GEM_LIMIT) { // 젬을 정해진 개수 만큼 넣기
        row = rand() % LADDER_SIZE * 2;
        col = rand() % LADDER_SIZE * 2;
        if (rand() % 2 == 0) col++;
        else row++;
        // i, j는 홀, 짝이면 세로선, 짝, 홀이면 가로선
        if ((*ladder_ptr)[row][col] == 1) {
            // 선이 있는 곳에 아직 보석이 없으면
            (*ladder_ptr)[row][col] = 2; // 보석 넣기
            gem_count++;
        }

    }
}
void create_ladder(int (*ladder_ptr)[ARR_SIZE][ARR_SIZE]) {
    int (*ladder)[ARR_SIZE] = *ladder_ptr;

    // 그냥 아무데나 선 긋기
    for (int i = 0; i < ARR_SIZE; i++) {
        for (int j = 0; j < ARR_SIZE; j++) {
            if ((i % 2 == 0 && j % 2 == 1)) { // 가로줄 위치 (i 짝수, j 홀수)
                if (rand() % 2 != 0) { // 선을 그을지 말지
                    (*ladder_ptr)[i][j] = 1;
                }
                else {
                    ladder[i][j] = 0;
                }
            }
            else if (i % 2 == 0 && j % 2 == 0) { // 격자점 위치 (i 짝수, j 짝수)
                ladder[i][j] = 1;
            }
            else if (i % 2 == 1 && j % 2 == 0) { // 세로줄 위치 (i 홀수, j 짝수)
                (*ladder_ptr)[i][j] = 1;
            }
            else { // 공백 위치 (i 홀수, j 홀수)
                ladder[i][j] = 0;
            }
        }
    }
    make_path(ladder_ptr, 0, ARR_SIZE - 1); // 종료 지점 까지 길 만들기
    put_gem(ladder_ptr);
}

void print_ladder(int ladder[ARR_SIZE][ARR_SIZE]) {
    setColor(15); //사다리 출력하기 전에 색 하얀색으로 바꾸기
    for (int i = 0; i < ARR_SIZE; i++) {
        if (i % 2 == 0) {
            for (int j = 0; j < ARR_SIZE; j++) {
                if (j % 2 == 0) {
                    printf("%s", VERTICAL_LINE_CHAR);
                }
                else {
                    if (ladder[i][j] == 1) {
                        printf("%s", char_mul(HORIZONTAL_LINE_CHAR, HORIZONTAL_LENGTH));
                    }
                    else if (ladder[i][j] == 2) {
                        printf("%s", char_mul(HORIZONTAL_LINE_CHAR, HORIZONTAL_LENGTH / 2));
                        setColor(4);
                        printf("◆");
                        setColor(15);
                        printf("%s", char_mul(HORIZONTAL_LINE_CHAR, HORIZONTAL_LENGTH / 2));
                        
                    }
                    else {
                        printf("%s", char_mul(" ", HORIZONTAL_LENGTH));
                    }
                }
            }
            printf("\n");

        }
        else {
            for (int row_segment = 0; row_segment < VERTICAL_LENGTH; row_segment++) {
                for (int j = 0; j < ARR_SIZE; j++) {
                    if (j % 2 == 0) {
                        if (ladder[i][j] == 1) {
                            printf("%s", VERTICAL_LINE_CHAR);
                        }
                        else if (ladder[i][j] == 2) {
                            if (row_segment == VERTICAL_LENGTH / 2 - 1) {
                                setColor(4);
                                printf("◆");
                                setColor(15);
                            }
                            else {
                                printf("%s", VERTICAL_LINE_CHAR);
                            }
                        }
                        else {
                            printf(" ");
                        }
                    }
                    else {
                        printf("%s", char_mul(" ", HORIZONTAL_LENGTH));
                    }
                }
                printf("\n");
            }
        }
    }
}


