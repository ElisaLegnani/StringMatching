#include "functions.h"
#include <fstream>

void init(void) {

  cout << endl << "***** String-matching *****" << endl;
  cout << "Reading text file '" << filename_in << "'" << endl;
  cout << "and searching for pattern '" << pattern << "' matches" << endl;
  cout << "with " << algorithm << " algorithm" << endl << endl;

  if (algorithm == "automaton") {
    cout << "NOTE: automaton algorithm is built for pattern searches in genetic code," << endl;
    cout << "thus it works with the finite alphabet 'a', 'c', 'g', 't'." << endl << endl;
  }

  P = pattern.c_str();

  ifstream read(filename_in);
  if (read.is_open()) {

    read.seekg(0, read.end);
    int length = read.tellg();
    read.seekg(0, read.beg);

    T = new char[length];
    read.read(T, length);

    read.close();

  } else {
    cerr << "Error: unable to open text file." << endl;
    abort();
  }
}

void print(void) {

  delete[] T;

  cout << "Printing shifts to file " << filename_out << endl << endl;

  ofstream print(filename_out);
  if (print.is_open()) {

    print << dt;
    for (int i{}; i<shifts.size(); ++i){
      print << endl << i << " " << shifts[i];
    }

  print.close();

  } else {
    cerr << "Error: unable to open output file." << endl;
    abort();
  }
}