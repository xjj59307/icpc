/*
ID: xjj_hdl1
PROG: kimbits
LANG: C++
*/

#include <fstream>
#include <iostream>
#include <algorithm>
using namespace std;

const int SIZE = 50;
long long _dp[SIZE][SIZE];

int main() {
  ofstream fout("kimbits.out");
  ifstream fin("kimbits.in");

  int n;
  int l;
  long long ith;
  fin >> n >> l >> ith;

  for (int i = 0; i <= n; ++i)
    _dp[i][0] = _dp[0][i] = 1;

  for (int i = 1; i < n; ++i) {
    for (int j = 1; j <= l; ++j) {
      _dp[i][j] = _dp[i-1][j] + _dp[i-1][j-1];
    }
  }

  while (n) {
    if (ith > _dp[n-1][l]) {
      fout << "1";
      ith -= _dp[n-1][l--];
    } 
    else fout << "0";

    n--;
  }

  fout << endl;

  return 0;
}

