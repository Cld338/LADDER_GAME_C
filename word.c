#include "word.h"
#include "util.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <windows.h>
#include <conio.h>

//--------------파일에서 문장열 불러와서 각 배열에 저장하기--------------------------------------------------------------

void make_list(struct WORDLIST * wordlist) {
	int i, cc = 0, jc = 0, gc = 0;
	FILE* f;
	f = fopen("wordlist.txt", "r"); //파일 불러오기
	for (i = 0; i < NUM - 1; i++) {
		fscanf(f, "%s", (wordlist->all)[i]); //파일에 있는 내용 word 변수에 저장
		if (strlen((wordlist->all)[i]) == CHO_SIZE - 1) {
			strcpy((wordlist->cho)[cc++], (wordlist->all)[i]);
		}
		if (strlen((wordlist->all)[i]) == JONG_SIZE - 1) {
			strcpy((wordlist->jung)[jc++], (wordlist->all)[i]);
		}
		if (strlen((wordlist->all)[i]) == GO_SIZE - 1) {
			strcpy((wordlist->go)[gc++], (wordlist->all)[i]);
		}
	}
	wordlist->cho_count = cc;
	wordlist->jung_count = jc;
	wordlist->go_count = gc;
	fclose(f);
}


//------------------------문자열 표시하기------------------------------------

void show_string(char* w, struct WORDLIST* wordlist, int level) {
	switch (level) {
	case 0: strcpy(w, (wordlist->cho)[rand() % (wordlist->cho_count)]); break;
	case 1: strcpy(w, (wordlist->jung)[rand() % (wordlist->jung_count)]); break;
	case 2: strcpy(w, (wordlist->go)[rand() % (wordlist->go_count)]); break;
	}
	gotoxy(55, 1); printf("%s\n", w);
}

//-----------------------문자열 맞추기----------------------------------------

int practice(struct WORDLIST* wordlist, int level, int target_score, clock_t start, double time_limit) {
	//system("cls");
	int word_size;
	char word[GO_SIZE], ch, input[GO_SIZE];
	int s_time, j = 0;
	int score = 0;
	double elapsed, remaining;
	int word_time_limit;
	switch (level) {
	case 0:
		word_size = CHO_SIZE;
		word_time_limit = CHO_WORD_TIME_LIMIT;
		break;
	case 1:
		word_size = JONG_SIZE; 
		word_time_limit = JONG_WORD_TIME_LIMIT;
		break;
	case 2:
		word_size = GO_SIZE; 
		word_time_limit = GO_WORD_TIME_LIMIT;
		break;
	default:
		word_size = GO_SIZE; 
		word_time_limit = GO_WORD_TIME_LIMIT;
		break;
	}
	

	gotoxy(70, 1); printf("score: %d", score);
	show_string(word, wordlist, level);
	gotoxy(55 + j, 2);
	printf("_");
	s_time = time(0);
	hide_cursor();
	while (1) {
		elapsed = (double)(clock() - start) / CLOCKS_PER_SEC;
		remaining = time_limit - elapsed;
		
		gotoxy(35, 0);
		printf("남은 시간: %.2f초", remaining);
		
		gotoxy(55 + j, 2);
		
		if (remaining <= 0.0) {
			return 0;
		}

		if (time(0) > s_time + word_time_limit) {
			system("cls");

			gotoxy(70, 1); printf("score: %d", score);
			show_string(word, wordlist, level);
			s_time = time(0);
			j = 0;
		}
		
		if (j >= word_size - 1) {
			input[word_size - 1] = 0;
			if (!strcmp(word, input)) {
				score++;
			}
			system("cls");
			if (score == target_score) return 1;
			gotoxy(70, 1); printf("score: %d", score);
			show_string(word, wordlist, level);
			s_time = time(0);
			j = 0;
		}
		
		if (_kbhit()) {
			ch = _getch();
			if (ch == 27) {
				break;
			}
			if (ch >= 'a' && ch <= 'z') {
				printf("%c", ch);
				input[j] = ch;
				j++;
				if (j < word_size - 1) printf("_");
			}
			if (ch == 8) {
				if (j > 0) {
					j--;
					printf("\b \b_ ");
				}
			}
		}

		
	}
}