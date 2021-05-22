#include "algos.h"
#include <cmath>
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {

  char *text = "baabacaa cba";
  const char *pattern = "ba";
  int shifts[10];

  // naive

  naive(text, pattern, shifts);

  if (shifts[0] != 0 || shifts[1] != 3 || shifts[2] != 10) {
    cout << "Error: naive algorithm not working properly." << endl;
    abort();
  }

  // automaton

  automaton(text, pattern, shifts);

  if (shifts[0] != 0 || shifts[1] != 3 || shifts[2] != 10) {
    cout << "Error: finite automaton algorithm not working properly." << endl;
    abort();
  }

  // KMP

  kmp(text, pattern, shifts);

  if (shifts[0] != 0 || shifts[1] != 3 || shifts[2] != 10) {
    cout << "Error: kmp algorithm not working properly." << endl;
    abort();
  }

  return 0;
}