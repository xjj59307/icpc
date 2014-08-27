#include <iostream>
#include <list>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

typedef list<pair<int, int> >::iterator iter;
list<pair<int, int> > _ranges;

int main() {
  int n;
  int left;
  int right;

  cin >> n;
  cin >> left >> right;
  _ranges.push_back(make_pair(left, right));

  for (int i = 1; i < n; ++i) {
    cin >> left >> right;
    int length = _ranges.size();
    int count = 0;
    for (iter i = _ranges.begin(); count < length; ++i, count++) {
      int cur_left = (*i).first;
      int cur_right = (*i).second;

      if (left <= cur_left && right > cur_left && right < cur_right)
        (*i).first = right;
      else if (left > cur_left && left < cur_right && right >= cur_right)
        (*i).second = left;
      else if (left <= cur_left && right >= cur_right)
        _ranges.erase(i);
      else if (left > cur_left && right < cur_right) {
        _ranges.erase(i);
        _ranges.push_back(make_pair(cur_left, left));
        _ranges.push_back(make_pair(right, cur_right));
      }
    }
  }

  int result = 0;

  for (iter i = _ranges.begin(); i != _ranges.end(); ++i) {
    int left = (*i).first;
    int right = (*i).second;
    result += right - left;
  }

  cout << result << endl;

  return 0;
}
