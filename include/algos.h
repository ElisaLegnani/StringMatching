#include <string.h>

#define tot_chars 10000

void naive(char *, const char *, int[]);

int nextstate(const char *, int, int, int);
void transition(const char *, int, int[][tot_chars]);
void automaton(char *, const char *, int[]);

void prefix(const char *, int, int[]);
void kmp(char *, const char *, int[]);