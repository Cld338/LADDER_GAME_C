#ifndef LADDER_H
#define LADDER_H

#define LADDER_SIZE 6 // 격자점의 수
#define ARR_SIZE (LADDER_SIZE * 2 - 1) // 격자점 및 다리 저장 배열의 크기
#define WORD_LENGTH_LIMIT 10 // 단어의 최대 길이
#define HORIZONTAL_LENGTH 5 // 사다리에서 가로 선의 길이, 보석 가운데 위치하므로 홀수
#define VERTICAL_LENGTH HORIZONTAL_LENGTH / 5 * 2 + 1// 사다리에서 세로 선의 길이
#define GEM_LIMIT 6 // 보석 개수 제한
#define HORIZONTAL_LINE_CHAR "━"
#define VERTICAL_LINE_CHAR "┃"

void create_ladder(int (*ladder_ptr)[ARR_SIZE][ARR_SIZE]);
void print_ladder(int ladder[ARR_SIZE][ARR_SIZE]);
#endif