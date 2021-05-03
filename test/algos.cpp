#include "algos.h"
#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, char *argv[]) {

  //AGGIUNGERE test per: calc_nextstate, transition, prefix

  const char* text = "abacaa cba";
  const char* pattern = "ba";
  int shifts[10];
  
  // naive

  naive(text, pattern, shifts);

  if(shifts[0]!=0 || shifts[1]!=7){
    cout << "Error: naive algorithm not working properly." << endl;
    abort();
  }

  // automaton

  automaton(text, pattern, shifts);

  if(shifts[0]!=0 || shifts[1]!=7){
    cout << "Error: finite automaton algorithm not working properly." << endl;
    abort();
  }

  // KMP

  kmp(text, pattern, shifts);

  if(shifts[0]!=0 || shifts[1]!=7){
    cout << "Error: kmp algorithm not working properly." << endl;
    abort();
  }

  return 0;
}