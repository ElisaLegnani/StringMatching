#include "algos.h"
#include <cmath>

void naive(const char* T, const char* P) {

  int n = strlen(T);
  int m = strlen(P);
  int s{};

  for (int i{}; i < n - m + 1; ++i) {
    for (int j{}; j < m; ++j) {
      if (T[i + j] == P[j]) {
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

int calc_nextstate(const char* P, int m, int q, int i) {
  if (q < m && i == P[q]){
    return q + 1;
  }
  for (int ns = q; ns > 0; ns--) {
    if (P[ns - 1] == i) {
      for (int j{}; j < ns - 1; ++j) {
        if (P[i] != P[q - ns + 1 + j]) {
          break;
        }
        if (j == ns - 1) {
          return ns;
        }
      }
    }
  }
  return 0;
}

void delta(const char* P, int m, int d[][tot_chars]) { // Transition function
  for (int q{}; q < m; ++q) {
    for (int i{}; i < tot_chars; ++i) {
      d[q][i] = calc_nextstate(P, m, q, i);
    }
  }
}

void finite_automaton(const char* T, const char* P) {

  int n = strlen(T);
  int m = strlen(P);
  int q{};

  int d[m + 1][tot_chars];
  delta(P, m, d);

  for (int i = 1; i < n; ++i) {
    q = d[q][T[i]];
    if (q == m) {
      cout << "P found with shift " << i - m << endl;
    }
  }
}