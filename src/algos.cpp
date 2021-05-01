#include "algos.h"

void naive(string T, string P) {

  int n = T.length();
  int m = P.length();
  int s{};

  for (int i{}; i < n-m+1; ++i) {
    for (int j{}; j < m; ++j) {
      if (T[i + j] == P[j]){
        s = i;
      } else {
        s = 0;
        break;
      }
    }
    if (s != 0) {
      cout << "P found with shift " << s - 1 << endl;
    }
  }
}