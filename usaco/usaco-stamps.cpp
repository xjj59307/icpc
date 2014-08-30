/*
ID: xjj_hdl1
PROG: stamps
LANG: C++
*/

#include <fstream>
#include <iostream>
#include <algorithm>
using namespace std;

const int SIZE = 200 * 10000 + 5;
int _dp[SIZE];

int main() {
  ofstream fout("stamps.out");
  ifstream fin("stamps.in");

  int k;
  int n;
  int stamps[55];
  
  fin >> k >> n;
  for (int i = 0; i < n; ++i)
    fin >> stamps[i];

  int result = 1;

  while (true) {
    int min_val = k + 1;
    for (int i = 0; i < n; ++i) {
      if (result < stamps[i]) continue;

      if (_dp[result - stamps[i]] < min_val)
        min_val = _dp[result - stamps[i]];
    }

    min_val++;
    if (min_val > k) break;
    else _dp[result] = min_val;

    result++;
  }

  result--;
  fout << result << endl;

  return 0;
}

