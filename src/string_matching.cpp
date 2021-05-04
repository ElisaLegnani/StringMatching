#include "algos.h"
#include "functions.h"

using namespace std;

int main(int argc, char *argv[]) {

  //Read from command line
  if (argv[1] == NULL) {
    cout << "Insert text filename: ";
    cin >> filename_in;
    cout << "Insert pattern to search in text: ";
    cin >> pattern;
    cout << "Insert string-matching algorithm (naive, automaton, kmp): ";
    cin >> algorithm;
  } else {
    filename_in = argv[1];
    pattern = argv[2];
    algorithm = argv[3];
  }

  init();

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
  
  } else{
    cerr << "Error: wrong algorithm name." << endl; 
    return 0;
  }

  clock_t tf = clock();
  dt = double(tf-ti)*1000 /CLOCKS_PER_SEC;

  print();

  return 0;
}
