#include <iostream>
#include <vector>

using namespace std;

inline string filename_in;
inline string pattern;
inline string algorithm;
inline string filename_out;

inline const char *P;
inline char *T;

inline vector<int> shifts;

inline clock_t ti;
inline clock_t tf;
inline double dt;

void init(void);
void print(void);