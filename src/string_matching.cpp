#include "algos.h"
#include <fstream>
#include <sstream>

using namespace std;

int main(int argc, char *argv[]) {

  string filename_in; //ATTENZIONE: inserire files di testo senza caratteri strani
  string p; // c'è modo più conveniente di leggere da file? senza convertire string --> char*
  string t;
  const char* pattern;
  const char* text;

  if (argv[1] == NULL) {
    cout << "Insert input filename: ";
    cin >> filename_in;
    cout << "Insert string to search in text: ";
    cin >> p;
  } else {
    filename_in = argv[1];
    pattern = argv[2];
  }

  pattern = p.c_str();

  ifstream stream(filename_in);
  t = string((istreambuf_iterator<char>(stream)), istreambuf_iterator<char>());
  text = t.c_str();

  cout << "NAIVE:" << endl;
  naive(text, pattern);

  cout << "FINITE AUTOMATON:" << endl;
  finite_automaton(text, pattern);

  // stampare tempi

  return 0;
}
