#include "algos.h"
#include <cmath>

void naive(const char* T, const char* P, int S[]) {

  int n = strlen(T);
  int m = strlen(P);
  int s{};
  int k{};

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
      S[k] = s-1;
      k = k+1;
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

void transition(const char* P, int m, int delta[][tot_chars]) {
  for (int q{}; q < m; ++q) {
    for (int i{}; i < tot_chars; ++i) {
      delta[q][i] = calc_nextstate(P, m, q, i);
    }
  }
}

void automaton(const char* T, const char* P, int S[]) {

  int n = strlen(T);
  int m = strlen(P);
  int q{};
  int k{};

  int delta[m + 1][tot_chars];
  transition(P, m, delta);

  for (int i = 1; i < n; ++i) {
    q = delta[q][T[i]];
    if (q == m) {
      S[k] = i - m;
      k = k+1;
    }
  }
}



void prefix(const char* P, int m, int pi[]) {
  pi[0]=0;
  int k{};
  for (int q=1; q < m; ++q) {
    while(k>0 && P[k]!=P[q]) {
      k=pi[k-1];
    }
    if(P[k]==P[q]){
        k=k+1;
    }
    pi[q]=k;
  }
}

void kmp(const char* T, const char* P, int S[]) {

  int n = strlen(T);
  int m = strlen(P);
  int q{};
  int k{};

  int pi[m];
  prefix(P, m, pi);

  for (int i = 1; i < n; ++i) {
    while(q>0 && P[q]!=T[i]){
      q=pi[q-1];
    }
    if(P[q]==T[i]){
      q=q+1;
    }
    if (q == m) {
      q = pi[q-1];
      S[k] = i - m;
      k = k+1;
    }
  }
}