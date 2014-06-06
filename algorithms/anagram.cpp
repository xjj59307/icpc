#include <iostream>
#include <string>
using namespace std;

bool _visisted[100];
string _input;
string _current;

void dfs(int depth) {
  if (depth == _input.length()){
    cout << _current << endl;
    return;
  }

  for (int i = 0; i < _input.length(); ++i) {
    if (!_visisted[i]) {
      _visisted[i] = true;
      _current.push_back(_input[i]);
      dfs(depth + 1);
      _visisted[i] = false;
      _current.pop_back();
    }
  }
}

int main() {
  cin >> _input;
  dfs(0);

  return 0;
}
