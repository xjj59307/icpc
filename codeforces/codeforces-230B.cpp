#include <iostream>
using namespace std;

const int SIZE = 175;
double _w[SIZE][SIZE];
double _a[SIZE][SIZE];
double _b[SIZE][SIZE];

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> _w[i][j];
    }
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (i != j) _a[i][j] = (_w[i][j] + _w[j][i]) / 2;
      else _a[i][j] = _w[i][j];
    }
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (i != j) _b[i][j] = _w[i][j] - _a[i][j];
      else _b[i][j] = 0;
    }
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cout << _a[i][j] << " ";
    }
    cout << endl;
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cout << _b[i][j] << " ";
    }
    cout << endl;
  }

  return 0;
}
