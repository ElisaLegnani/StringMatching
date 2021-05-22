#include "functions.h"
#include <fstream>

void init(void) {

  cout << endl << "***** String-matching *****" << endl;
  cout << "Reading text file '" << filename_in << "'" << endl;
  cout << "and searching for pattern '" << pattern << "' matches" << endl;
  cout << "with " << algorithm << " algorithm" << endl << endl;

  for (int s{}; s < 1000; ++s) {
    shifts[s] = -1;
  }

  P = pattern.c_str(); // invece: usare direttamente char* e leggere anche più
                       // di una parola? (fino a \n)

  ifstream read(filename_in);
  if(read.is_open()){

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

  cout << "Printing shifts to file " << filename_out << endl << endl;
  ofstream print(filename_out);

  print << dt;

  int i{};
  while (shifts[i] != -1){
    print << endl << i << " " << shifts[i];
    i++;
  }

  print.close();
}