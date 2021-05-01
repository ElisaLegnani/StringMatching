#include "algos.h"
#include <fstream>
#include <sstream>

using namespace std;

int main(int argc, char *argv[]) {

  string filename_in;
  string pattern;
  string text;

  if (argv[1] == NULL) {
    cout << "Insert input filename: ";
    cin >> filename_in;
    cout << "Insert string to search in text: ";
    cin >> pattern;
  } else {
    filename_in = argv[1];
    pattern = argv[2];
  }

  ifstream stream(filename_in);
  text = string((istreambuf_iterator<char>(stream)), istreambuf_iterator<char>());

  naive(text, argv[2]);

  return 0;
}
