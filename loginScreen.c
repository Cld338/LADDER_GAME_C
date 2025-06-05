#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdio.h>
#include <windows.h>
#include "util.h"
#include "user.h"

struct User* loginScreen() {

	for (int i = 0; i < 3; i++) printf("\n");

	for (int i = 0; i < 50; i++) printf(" ");
	setColor(14);
	printf("로그인\n");


	for (int i = 0; i < 3; i++) printf("\n");

	struct User user;
	char filename[120];
	FILE* fp;

	printf("아이디를 입력하세요:");
	scanf("%s", user.id);

	sprintf(filename, "Scores/%s.txt", user.id); // 문자열에 서식지정자 적용하기

	fp = fopen(filename, "r");
	if (fp == NULL) {
		fp = fopen(filename, "w");
		printf("새 사용자입니다. 초기 점수는 0입니다.\n");
		user.score = 0;
		fprintf(fp, "%d", user.score);
		fclose(fp);
	}
	else {
		fscanf(fp, "%d", &user.score);
		printf("기존점수:%d\n", user.score);
		fclose(fp);
	}
	setColor(15);
	return &user;
}


