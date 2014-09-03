/*
ID: xjj_hdl1
PROG: ratios
LANG: C++
*/

#include <fstream>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  ofstream fout("ratios.out");
  ifstream fin("ratios.in");

  int formula[4][3];

  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 3; ++j) {
      fin >> formula[i][j];
    }
  }

  int sum_min = 300;
  int result_x;
  int result_y;
  int result_z;
  int result_times;

  for (int i = 0; i < 100; ++i) {
    for (int j = 0; j < 100; ++j) {
      for (int k = 0; k < 100; ++k) {
        if (i + j + k == 0) continue;

        int x_sum = i * formula[1][0] + j * formula[2][0] + k * formula[3][0];
        int y_sum = i * formula[1][1] + j * formula[2][1] + k * formula[3][1];
        int z_sum = i * formula[1][2] + j * formula[2][2] + k * formula[3][2];

        if (x_sum % formula[0][0] == 0) {
          int times = x_sum / formula[0][0];
          if (times * formula[0][1] == y_sum && times * formula[0][2] == z_sum) {
            if (sum_min > i + j + k) {
              sum_min = i + j + k;
              result_x = i;
              result_y = j;
              result_z = k;
              result_times = times;
            }
          }
        }
      }
    }
  }

  if (sum_min != 300)
    fout << result_x << " " << result_y << " " << result_z << " " << result_times << endl;
  else fout << "NONE" << endl;

  return 0;
}

