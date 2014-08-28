/*
ID: xjj_hdl1
PROG: contact
LANG: C++
*/

#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

struct Pattern {
  int count;
  string bit_seq;

  Pattern(int count_, string bit_seq_) :
    count(count_),
    bit_seq(bit_seq_) {}
};

bool sorter(const Pattern& lhs, const Pattern& rhs) {
  if (lhs.count != rhs.count)
    return lhs.count > rhs.count;
  if (lhs.bit_seq.size() != rhs.bit_seq.size())
    return lhs.bit_seq.size() < rhs.bit_seq.size();
  return lhs.bit_seq < rhs.bit_seq;
}

vector<Pattern> _patterns;

map<string, int> _pattern_map;
map<string, int>::iterator it;

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
      string sub_seq = seq.substr(i, len);
      it = _pattern_map.find(sub_seq);

      if (it == _pattern_map.end())
        _pattern_map.insert(pair<string, int>(sub_seq, 1));
      else
        _pattern_map[sub_seq]++;
    }
  }

  for (it = _pattern_map.begin(); it != _pattern_map.end(); ++it)
    _patterns.push_back(Pattern(it->second, it->first));

  sort(_patterns.begin(), _patterns.end(), sorter);

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
      else { fout << endl << pattern.bit_seq; count = -1; }
    }

    index++;
  }

  fout << endl;

  return 0;
}

