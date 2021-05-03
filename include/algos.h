#include <iostream>
#include <string.h>

#define tot_chars 10000 //ATTENZIONE: aumentare se il testo è lungo?

using namespace std;

void naive(const char*, const char*);

int calc_nextstate(const char*, int, int, int);
void transition(const char*, int, int[][tot_chars]);
void finite_automaton(const char*, const char*);

void prefix(const char*, int, int[]);
void kmp(const char*, const char*);