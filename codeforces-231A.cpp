#include <iostream>
#include <string>
using namespace std;

void print(int count) {
  while (count--) {
    cout << '|';
  }
}

int main() {
  string expr;
  cin >> expr;

  int a;
  int b;
  int c;
  int count = 0;

  for (int i = 0; i < expr.length(); ++i) {
    if (expr[i] == '+') {
      a = count;
      count = 0;
    } else if (expr[i] == '=') {
      b = count;
      count = 0;
    } else {
      count++;
    }
  }
  c = count;

  if (a + b + 2 == c) {
    a++;
    c--;
  } else if (a + b - 2 == c) {
    a--;
    c++;
    if (a == 0) { a++; b--; }
  } else if (a + b != c) {
    cout << "Impossible" << endl;
    return 0;
  }

  print(a);
  cout << '+';
  print(b);
  cout << '=';
  print(c);
  cout << endl;

  return 0;
}
