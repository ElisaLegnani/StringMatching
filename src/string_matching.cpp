#include "algos.h"
#include "functions.h"

using namespace std;

int main(int argc, char *argv[]) {

  if (argv[1] == NULL) {
    cout << "Insert text filename: ";
    cin >> filename_in;
    cout << "Insert pattern to search in text: ";
    cin >> pattern;
    cout << "Insert string-matching algorithm (naive, automaton, kmp): ";
    cin >> algorithm;
    cout << "Insert output filename: ";
    cin >> filename_out;
  
  } else {
    filename_in = argv[1];
    pattern = argv[2];
    algorithm = argv[3];
    filename_out = argv[4];
  }

  init();

  if (algorithm == "naive") {
    ti = clock();
    naive(T, P, shifts);
    tf = clock();

  } else if (algorithm == "automaton") {
    ti = clock();
    automaton(T, P, shifts);
    tf = clock();

  } else if (algorithm == "kmp") {
    ti = clock();
    kmp(T, P, shifts);
    tf = clock();

  } else {
    cerr << "Error: wrong algorithm name." << endl;
    return 0;
  }

  dt = double(tf - ti) * 1000 / CLOCKS_PER_SEC;

  print();

  return 0;
}
