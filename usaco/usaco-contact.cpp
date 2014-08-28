/*
ID: xjj_hdl1
PROG: contact
LANG: C++
*/

#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>
#include <bitset>
using namespace std;

struct Pattern {
  int count;
  string bit_seq;

  Pattern() : count(0) {}
};

bool sorter(const Pattern& lhs, const Pattern& rhs) {
  if (lhs.count != rhs.count)
    return lhs.count > rhs.count;
  if (lhs.bit_seq.size() != rhs.bit_seq.size())
    return lhs.bit_seq.size() < rhs.bit_seq.size();
  return lhs.bit_seq < rhs.bit_seq;
}

const int SIZE = (1 << 13) + 5;
Pattern _patterns[SIZE];

int main() {
  ofstream fout("contact.out");
  ifstream fin("contact.in");

  int a;
  int b;
  int n;
  string line;
  string seq;
  
  fin >> a >> b >> n;
  while (fin >> line)
    seq += line;

  int size = seq.size();

  for (int len = a; len <= b; ++len) {
    for (int i = 0; i <= size - len; ++i) {
      // add 1 as prefix to differentiate patterns like 0 and 00
      bitset<13> sub_bit("1" + seq.substr(i, len));
      Pattern& pattern = _patterns[sub_bit.to_ulong()];

      if (!pattern.count) pattern.bit_seq = seq.substr(i, len);
      pattern.count++;
    }
  }

  sort(_patterns, _patterns + SIZE, sorter);

  int index = 0;
  int prev_count = -1;
  int count = 0;
  while (_patterns[index].count) {
    Pattern pattern = _patterns[index];

    if (prev_count != pattern.count) {
      if (--n == -1) break;

      if (index)
        fout << endl << pattern.count << endl << pattern.bit_seq;
      else
        fout << pattern.count << endl << pattern.bit_seq;
      
      count = 0;
      prev_count = pattern.count;
    }
    else {
      if (++count < 6) fout << " " << pattern.bit_seq;
      else { fout << endl << pattern.bit_seq; count = 0; }
    }

    index++;
  }

  fout << endl;

  return 0;
}

