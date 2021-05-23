#include "algos.h"
#include <cmath>
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {

  char *text = "ggaagggacaacggagga";
  const char *pattern = "gga";
  int shifts[4];

  // naive

  for (int s{}; s < 4; ++s) {
    shifts[s] = 0;
  }

  naive(text, pattern, shifts);

  if (shifts[0] != 0 || shifts[1] != 5 || shifts[2] != 12 || shifts[3] != 15) {
    cout << "Error: naive algorithm not working properly." << endl;
    abort();
  }

  // automaton

  for (int s{}; s < 5; ++s) {
    shifts[s] = 0;
  }

  automaton(text, pattern, shifts);

  if (shifts[0] != 0 || shifts[1] != 5 || shifts[2] != 12 || shifts[3] != 15) {
    cout << "Error: finite automaton algorithm not working properly." << endl;
    abort();
  }

  // KMP

  for (int s{}; s < 5; ++s) {
    shifts[s] = 0;
  }

  kmp(text, pattern, shifts);

  if (shifts[0] != 0 || shifts[1] != 5 || shifts[2] != 12 || shifts[3] != 15) {
    cout << "Error: kmp algorithm not working properly." << endl;
    abort();
  }

  return 0;
}