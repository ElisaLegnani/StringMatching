#include "functions.h"
#include <fstream>

void init(void) {

  cout << endl << "***** String-matching *****" << endl;
  cout << "Reading text file '" << filename_in << "'" << endl;
  cout << "and searching for pattern '" << pattern << "' matches" << endl;
  cout << "with " << algorithm << " algorithm" << endl << endl;

  if (algorithm == "automaton") {
    cout << "NOTE: automaton algorithm works with the finite alphabet " 
    << "of the first 255 ASCII characters." << endl << endl;
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

    print << dt << endl;
    print << shifts.size() << endl;
    for (int i{}; i<shifts.size(); ++i){
      print << i << " " << shifts[i] << endl;
    }

  print.close();

  } else {
    cerr << "Error: unable to open output file." << endl;
    abort();
  }
}