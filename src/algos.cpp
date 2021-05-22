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

int nextstate(const char *P, int m, int q, int i) {
  if (q < m && i == P[q]) {
    return q + 1;
  }
  for (int k = q; k > 0; k--) {
    if (P[k - 1] == i) {
      for (int j{}; j < k - 1; ++j) {
        if (P[i] != P[q - k + 1 + j]) {
          break;
        }
        if (j == k - 1) {
          return k;
        }
      }
    }
  }
  return 0;
}

void transition(const char *P, int m, int delta[][tot_chars]) {
  for (int q{}; q < m; ++q) {
    for (int i{}; i < tot_chars; ++i) {
      delta[q][i] = nextstate(P, m, q, i);
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
    q = delta[q][T[i]];
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