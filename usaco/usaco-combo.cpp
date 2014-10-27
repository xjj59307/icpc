/*
ID: xjj_hdl1
PROG: combo
LANG: C++
*/

#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

int _n;
int _farmer[3];
int _master[3];

bool judge_farmer(int i, int j, int k) {
  if (abs(i - _farmer[0]) > 2 && abs(i - _farmer[0]) < (_n - 2)) return false;
  if (abs(j - _farmer[1]) > 2 && abs(j - _farmer[1]) < (_n - 2)) return false;
  if (abs(k - _farmer[2]) > 2 && abs(k - _farmer[2]) < (_n - 2)) return false;

  return true;
}

bool judge_master(int i, int j, int k) {
  if (abs(i - _master[0]) > 2 && abs(i - _master[0]) < (_n - 2)) return false;
  if (abs(j - _master[1]) > 2 && abs(j - _master[1]) < (_n - 2)) return false;
  if (abs(k - _master[2]) > 2 && abs(k - _master[2]) < (_n - 2)) return false;

  return true;
}

int main() {
  ofstream fout("combo.out");
  ifstream fin("combo.in");

  fin >> _n;
  fin >> _farmer[0] >> _farmer[1] >> _farmer[2];
  fin >> _master[0] >> _master[1] >> _master[2];

  int cnt = 0;

  for (int i = 1; i <= _n; ++i) {
    for (int j = 1; j <= _n; ++j) {
      for (int k = 1; k <= _n; ++k) {
        if (judge_farmer(i, j, k) || judge_master(i, j, k))
          cnt++;
      }
    }
  }

  fout << cnt << endl;

  return 0;
}


