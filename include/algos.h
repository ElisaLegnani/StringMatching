#include <iostream>
#include <string.h>

using namespace std;

#define tot_chars 4
inline string A = "acgt";

void naive(char *, const char *, int[]);

void transition(const char *, int, int[][tot_chars]);
void automaton(char *, const char *, int[]);

void prefix(const char *, int, int[]);
void kmp(char *, const char *, int[]);