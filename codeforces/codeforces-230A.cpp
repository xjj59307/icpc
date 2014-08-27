#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
  string str;
  cin >> str;

  int n = 0;
  int t = 0;
  int e = 0;
  int i = 0;

  for (int j = 0; j < str.length(); ++j) {
    if (str[j] == 'n') n++;
    if (str[j] == 't') t++;
    if (str[j] == 'e') e++;
    if (str[j] == 'i') i++;
  }

  if (n >= 3) n = (n - 3) / 2 + 1;
  else n = 0;
  e /= 3;
  int res = min(n, e);
  res = min(res, t);
  res = min(res, i);
  cout << res << endl;

  return 0;
}
