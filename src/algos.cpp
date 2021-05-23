#include "algos.h"
#include <cmath>

void naive(char *T, const char *P, int S[]) {

  int n = strlen(T);
  int m = strlen(P);
  int s{};
  int k{};

  for (int i{}; i < n - m + 1; ++i) {

    for (int j{}; j < m; ++j) {
      if (T[i + j] == P[j]) {
        s = i;
      } else {
        s = -1;
        break;
      }
    }
    if (s != -1) {
      S[k] = s;
      k = k + 1;
    }
  }
}

void transition(const char *P, int m, int delta[][tot_chars]) { // scrivere meglio?
  for (int q{}; q <= m; ++q) {
    for (int i{}; i < tot_chars; ++i) {
      int k = min(m + 1, q + 2);
      int pref = 0;
      do {
        pref = 0;
        k = k - 1;
        if (P[k - 1] == A[i] && k == 1)
          pref = 1;
        else if (P[k - 1] == A[i]) {
          for (int j = 1; j < k; ++j) {
            if (P[k - j - 1] != P[q - j]) {
              pref = 0;
              break;
            } else
              pref = 1;
          }
        }
      } while (pref == 0 && k > 0);
      delta[q][i] = k;
    }
  }
}

void automaton(char *T, const char *P, int S[]) {

  int n = strlen(T);
  int m = strlen(P);
  int q{};
  int k{};

  int delta[m + 1][tot_chars];
  transition(P, m, delta);

  for (int i{}; i < n; ++i) {
    int a = A.find(T[i]);
    q = delta[q][a];
    if (q == m) {
      S[k] = i - m + 1;
      k = k + 1;
    }
  }
}

void prefix(const char *P, int m, int pi[]) {

  pi[0] = 0;
  int k{};

  for (int q = 1; q < m; ++q) {
    while (k > 0 && P[k] != P[q]) {
      k = pi[k - 1];
    }
    if (P[k] == P[q]) {
      k = k + 1;
    }
    pi[q] = k;
  }
}

void kmp(char *T, const char *P, int S[]) {

  int n = strlen(T);
  int m = strlen(P);
  int q{};
  int k{};

  int pi[m];
  prefix(P, m, pi);

  for (int i{}; i < n; ++i) {
    while (q > 0 && P[q] != T[i]) {
      q = pi[q - 1];
    }
    if (P[q] == T[i]) {
      q = q + 1;
    }
    if (q == m) {
      q = pi[q - 1];
      S[k] = i - m + 1;
      k = k + 1;
    }
  }
}