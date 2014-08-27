#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
  int n;
  int p;
  int k;

  cin >> n >> p >> k;

  int start = p - k;
  int end = p + k;

  if (start > 1) cout << "<< ";
  for (int i = max(start, 1); i <= min(end, n); ++i) {
    if (i == p) cout << "(";

    cout << i;

    string tail = (i == p ? ") " : " ");
    cout << tail;
  }
  if (end < n) cout << ">>" << endl;

  return 0;
}
