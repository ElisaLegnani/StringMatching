#include <iostream>

using namespace std;

inline string filename_in;
inline string pattern;
inline string algorithm;

inline const char *P;
inline char *T;

inline int shifts[100000];
inline double dt;

inline string filename_out;

void init(void);
void print(void);