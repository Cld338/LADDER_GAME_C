#ifndef LEVEL_H
#define LEVEL_H
#define MAX_LEVEL 2 // 0, 1, 2

int level_clear();
void game(struct USER* user, struct WORDLIST* wordlist, int mode, int level);

#endif