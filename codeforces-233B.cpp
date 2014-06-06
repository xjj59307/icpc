#include <iostream>
#include <string>
using namespace std;

int main() {
  int64_t move[50];
  int64_t sum = 0;
  for (int i = 0; i < 50; ++i) {
    move[i] = sum + 1;
    sum += move[i];
  }

  // for (int i = 0; i < 50; ++i) {
  //   cout << move[i] << endl;
  // }

  int n;
  string str;
  cin >> n >> str;

  int64_t result = 0;
  for (int i = 0; i < n; ++i) {
    if (str[i] == 'B') result += move[i];
  }

  cout << result << endl;

  return 0;
}
