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
	printf("�α���\n");


	for (int i = 0; i < 3; i++) printf("\n");

	struct User user;
	char filename[120];
	FILE* fp;

	printf("���̵� �Է��ϼ���:");
	scanf("%s", user.id);

	sprintf(filename, "Scores/%s.txt", user.id); // ���ڿ��� ���������� �����ϱ�

	fp = fopen(filename, "r");
	if (fp == NULL) {
		fp = fopen(filename, "w");
		printf("�� ������Դϴ�. �ʱ� ������ 0�Դϴ�.\n");
		user.score = 0;
		fprintf(fp, "%d", user.score);
		fclose(fp);
	}
	else {
		fscanf(fp, "%d", &user.score);
		printf("��������:%d\n", user.score);
		fclose(fp);
	}
	setColor(15);
	return &user;
}


