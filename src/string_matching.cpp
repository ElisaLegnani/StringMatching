#include "algos.h"
#include "functions.h"

using namespace std;

int main(int argc, char *argv[]) {

  input();

  clock_t ti;

  if(algorithm=="naive"){
    ti = clock();
    naive(T, P, shifts);

  } else if(algorithm=="automaton"){
    ti = clock();
    automaton(T, P, shifts);

  } else if(algorithm=="kmp"){
    ti = clock();
    kmp(T, P, shifts);
  }

  clock_t tf = clock();
  dt = double(tf-ti)*1000 /CLOCKS_PER_SEC;

  print();

  return 0;
}
