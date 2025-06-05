#ifndef LADDER_H
#define LADDER_H

#define LADDER_SIZE 6 // �������� ��
#define ARR_SIZE (LADDER_SIZE * 2 - 1) // ������ �� �ٸ� ���� �迭�� ũ��
#define WORD_LENGTH_LIMIT 10 // �ܾ��� �ִ� ����
#define HORIZONTAL_LENGTH 5 // ��ٸ����� ���� ���� ����, ���� ��� ��ġ�ϹǷ� Ȧ��
#define VERTICAL_LENGTH HORIZONTAL_LENGTH / 5 * 2 + 1// ��ٸ����� ���� ���� ����
#define GEM_LIMIT 6 // ���� ���� ����
#define HORIZONTAL_LINE_CHAR "��"
#define VERTICAL_LINE_CHAR "��"

void create_ladder(int (*ladder_ptr)[ARR_SIZE][ARR_SIZE]);
void print_ladder(int ladder[ARR_SIZE][ARR_SIZE]);
#endif