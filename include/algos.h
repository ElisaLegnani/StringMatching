#include <iostream>
#include <string.h>

#define tot_chars 10000 //ATTENZIONE: aumentare se il testo è lungo

using namespace std;

void naive(const char*, const char*);

int calc_nextstate(const char*, int, int, int);
void delta(const char*, int, int[][tot_chars]); // Transition function
void finite_automaton(const char*, const char*);