#include "functions.h"
#include <fstream>

void input(void) {

  ifstream read;
  read.open("input.dat");

  read >> filename_in;
  read >> pattern;
  read >> algorithm;

  read.close();

  cout << endl << "***** String-matching *****" << endl;
  cout << "Reading text file '" << filename_in << "'" << endl;
  cout << "and searching for pattern '" << pattern << "' matches" << endl;
  cout << "with " << algorithm << " algorithm" << endl << endl;

  for (int s{}; s < 100; ++s) {
    shifts[s] = 0;
  }

  P = pattern.c_str(); // invece: usare direttamente char* e leggere anche più
                       // di una parola? (fino a \n)

  ifstream stream(filename_in);
  stream.seekg(0, stream.end);
  int length = stream.tellg();
  stream.seekg(0, stream.beg);

  T = new char[length];
  stream.read(T, length);
}

void print(void) {

  filename_out = "sm_" + algorithm + "_" + filename_in + "_" + pattern + ".dat";

  cout << "Printing shifts to file " << filename_out << endl << endl;

  ofstream print;
  print.open(filename_out);

  print << dt;

  int i{};
  do {
    print << endl << i << " " << shifts[i];
    i++;
  } while (shifts[i] != 0);

  print.close();
}