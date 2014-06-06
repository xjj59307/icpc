#include <iostream>
using namespace std;

int pow(int exponent) {
  int ret = 1;
  while (exponent--) {
    ret *= 10;
  }
  return ret;
}

int main() {
  int p;
  int x;
  cin >> p >> x;

  int res = -1;
  for (int i = 1; i <= 10e6; ++i) {
    int left = i * x;
    int right = i / 10 + (i % 10) * pow(p - 1);
    if (left == right) {
      res = i;
      break;
    }
  }

  if (res == -1) cout << "Impossible" << endl;
  else cout << res << endl;

  return 0;
}
