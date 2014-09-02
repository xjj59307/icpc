/*
ID: xjj_hdl1
PROG: spin
LANG: C++
*/

#include <utility>
#include <fstream>
#include <iostream>
#include <algorithm>
using namespace std;

struct Wheel {
  int speed;
  int count;
  pair<int, int> ranges[5];

  Wheel() {}

  Wheel(int speed_, int count_, pair<int, int>* ranges_) {
    speed = speed_;
    count = count_;
    for (int i = 0; i < count; ++i)
      ranges[i] = ranges_[i];
  }
} _wheels[5];

int main() {
  ofstream fout("spin.out");
  ifstream fin("spin.in");

  int speed;
  int count;
  pair<int, int> ranges[5];

  for (int i = 0; i < 5; ++i) {
    fin >> speed >> count;
    for (int j = 0; j < count; ++j) {
      int l_range;
      int extent;

      fin >> l_range >> extent;
      int r_range = (l_range + extent) % 360;
      ranges[j] = make_pair(l_range, r_range);
    }

    _wheels[i] = Wheel(speed, count, ranges);
  }

  for (int t = 0; t <= 360; ++t) {
    for (int angle = 0; angle < 360; ++angle) {
      bool pass_all = true;;

      for (int i = 0; i < 5; ++i) {
        bool pass = false;

        for (int j = 0; j < _wheels[i].count; ++j) {
          int l_range = _wheels[i].ranges[j].first;
          int r_range = _wheels[i].ranges[j].second;
          
          if ((angle >= l_range && angle <= r_range) ||
              (l_range > r_range && (angle >= l_range || angle <= r_range))) {
            pass = true;
            break;
          }
        }

        if (!pass) {
          pass_all = false;
          break;
        }
      }

      if (pass_all) {
        fout << t << endl;
        return 0;
      }
    }

    for (int i = 0; i < 5; ++i) {
      int speed = _wheels[i].speed;

      for (int j = 0; j < _wheels[i].count; ++j) {
        _wheels[i].ranges[j].first += speed;
        _wheels[i].ranges[j].first %= 360;

        _wheels[i].ranges[j].second += speed;
        _wheels[i].ranges[j].second %= 360;
      }
    }
  } 

  fout << "none" << endl;

  return 0;
}

