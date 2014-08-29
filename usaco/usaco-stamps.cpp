/*
ID: xjj_hdl1
PROG: stamps
LANG: C++
*/

#include <fstream>
#include <iostream>
#include <algorithm>
using namespace std;

const int SIZE = 201 * 10000 + 5;
bool _dp[SIZE];

int main() {
  ofstream fout("stamps.out");
  ifstream fin("stamps.in");

  int k;
  int n;
  int stamps[55];
  int max_value = -1;
  
  fin >> k >> n;

  for (int i = 0; i < n; ++i) {
    fin >> stamps[i];
    max_value = max(max_value, stamps[i]);
  }

  int max_range = max_value * k;
  fill_n(_dp + 1, max_range, false);
  _dp[0] = true;

  for (int i = 0; i < k; ++i) {
    for (int j = max_range; j >= 0; --j) {
      for (int k = 0; k < n; ++k) {
        int value = stamps[k];
        if (_dp[j]) _dp[j + value] = true;
      }
    }
  }

  int result = 0;
  while(_dp[++result]) {}

  fout << (result - 1) << endl;

  return 0;
}

