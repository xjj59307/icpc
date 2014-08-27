#include <iostream>
#include <algorithm>
using namespace std;

bool _sub_merged[105][105];
bool _visited[105][105];
int _n;
int _m;
int _size;

void dfs(int x, int y) {
  if (!_sub_merged[x][y] ||
      _visited[x][y] ||
      x <= 0 ||
      x > _n ||
      y <= 0 ||
      y > _m) {
    return;
  }

  _size++;
  _visited[x][y] = true;
  dfs(x + 1, y);
  dfs(x - 1, y);
  dfs(x, y + 1);
  dfs(x, y - 1);
}

int main() {
  int k;
  int x;
  int y;
  int result = -1;
  
  cin >> _n >> _m >> k;
  for (int i = 0; i < k; ++i) {
    cin >> x >> y;
    _sub_merged[x][y] = true;
  }

  for (int i = 1; i <= _n; ++i) {
    for (int j = 1; j <= _m; ++j) {
      _size = 0;
      dfs(i, j);
      result = max(result, _size);
    }
  }

  cout << result << endl;

  return 0;
}
