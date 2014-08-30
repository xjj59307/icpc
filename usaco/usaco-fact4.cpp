/*
ID: xjj_hdl1
PROG: fact4
LANG: C++
*/

#include <fstream>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  ofstream fout("fact4.out");
  ifstream fin("fact4.in");

  int n;
  fin >> n;

  int result = 1;
  int fact = 1;
  while (++fact <= n) {
    result *= fact;
    while (result % 10 == 0) result /= 10;
    result %= 100000;
  }

  result %= 10;
  fout << result << endl;

  return 0;
}

