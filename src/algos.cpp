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

void transition(const char* P, int m, int delta[][tot_chars]) {
  for (int q{}; q < m; ++q) {
    for (int i{}; i < tot_chars; ++i) {
      delta[q][i] = calc_nextstate(P, m, q, i);
    }
  }
}

void finite_automaton(const char* T, const char* P) {

  int n = strlen(T);
  int m = strlen(P);
  int q{};

  int delta[m + 1][tot_chars];
  transition(P, m, delta);

  for (int i = 1; i < n; ++i) {
    q = delta[q][T[i]];
    if (q == m) {
      cout << "P found with shift " << i - m << endl;
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

void kmp(const char* T, const char* P) {

  int n = strlen(T);
  int m = strlen(P);
  int q{};

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
      cout << "P found with shift " << i - m << endl;
      q = pi[q-1];
    }
  }
}