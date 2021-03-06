#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

#define tot_chars 256

void naive(char *, const char *, vector<int> &);

void transition(const char *, int, int[][tot_chars]);
void automaton(char *, const char *, vector<int> &);

void prefix(const char *, int, int[]);
void kmp(char *, const char *, vector<int> &);