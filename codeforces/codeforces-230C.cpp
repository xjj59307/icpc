#include <iostream>
using namespace std;

int square(int x) {
  return x * x;
}

int main() {
  int n;
  cin >> n;

  int res = 0;
  int square_n = square(n);

  for (int i = n - 1; i > 0; i--) {
    for (int j = n - 1; j > 0; j--) {
      if (square(i + 1) + square(j + 1) <= square_n) break;
      if (square(i) + square(j) > square_n) continue;
      if (square(i + 1) + square(j) > square_n ||
          square(i) + square(j + 1) > square_n) res++;
    }
  }

  res = (res + 1) * 4;
  if (n == 0) res = 1;
  cout << res << endl;

  return 0;
}
