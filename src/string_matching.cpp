#include "algos.h"
#include <fstream>
#include <sstream>

using namespace std;

int main(int argc, char *argv[]) {

  //MODIFICARE - idea:
  //(1) file di input con: - testo
  //                       - pattern
  //                       - algoritmo
  //(2) file di output testo_pattern_algoritmo con: - shifts
  //                                                - numero shifts
  //                                                - tempo
  //(3) funzioni compatte per: - lettura file input
  //                           - lettura file testo
  //                           - stampa su file output

  string filename_in; //ATTENZIONE: inserire files di testo senza caratteri strani - risolvere
  string p; // c'è modo più conveniente di leggere da file? senza convertire string --> char*
  string t;
  const char* pattern;
  const char* text;
  int shifts[100]; //c'è modo di non fissarlo?

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

  cout << endl << "NAIVE:" << endl;

  clock_t ti = clock();
  naive(text, pattern, shifts);
  clock_t tf = clock();
  double dt = double(tf-ti)*1000 /CLOCKS_PER_SEC;

  int i{};
  cout << "P found with shifts: ";
  do{
    cout << shifts[i] << "  ";
    i++;
  }while(shifts[i]!=0);

  cout << endl << "time: " << dt << endl;
  cout << "P found " << i << " times" << endl;

  cout << endl << "FINITE AUTOMATON:" << endl;

  ti = clock();
  finite_automaton(text, pattern, shifts);
  tf = clock();
  dt = double(tf-ti)*1000 /CLOCKS_PER_SEC;

  i=0;
  cout << "P found with shifts: ";
  do{
    cout << shifts[i] << "  ";
    i++;
  }while(shifts[i]!=0);

  cout << endl << "time: " << dt << endl;
  cout << "P found " << i << " times" << endl;


  cout << endl << "KMP:" << endl;

  ti = clock();
  kmp(text, pattern, shifts);
  tf = clock();
  dt = double(tf-ti)*1000 /CLOCKS_PER_SEC;

  i=0;
  cout << "P found with shifts: ";
  do{
    cout << shifts[i] << "  ";
    i++;
  }while(shifts[i]!=0);

  cout << endl << "time: " << dt << endl;
  cout << "P found " << i << " times" << endl;


  return 0;
}
