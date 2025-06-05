#ifndef WORD_H
#define WORD_H

#define NUM 10000

#define CHO_TIME_LIMIT 100.0
#define JONG_TIME_LIMIT 100.0
#define GO_TIME_LIMIT 100.0

#define CHO_WORD_TIME_LIMIT 10
#define JONG_WORD_TIME_LIMIT 7
#define GO_WORD_TIME_LIMIT 5

#define CHO_SIZE 6
#define JONG_SIZE 8
#define GO_SIZE 11

#include "time.h"

void make_list(struct WORDLIST*);

void show_chostring(char*, char **, int);
void show_jongstring(char*, char*, int);
void show_gostring(char*, char*, int);

int practice(struct WORDLIST*, int, int, clock_t start, double time_limit);

struct WORDLIST {
	char all[NUM][20];
	char cho[NUM][CHO_SIZE];
	char jung[NUM][JONG_SIZE];
	char go[NUM][GO_SIZE];
	int cho_count;
	int jung_count;
	int go_count;
};

#endif