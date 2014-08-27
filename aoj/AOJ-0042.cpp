#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int _value[1005];
int _weight[1005];
int _dp[1005];
int _used[1005][1005];

int main(int argc, const char *argv[])
{
    int w;
    int cnt = 1;
    while (cin >> w, w) {
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> _value[i];
            getchar();
            cin >> _weight[i];
        }

        for (int i = 0; i <= w; ++i)
            fill_n(_used[i], n, false);
        fill_n(_dp, w+1, 0);
        for (int i = 0; i < n; ++i) {
            _dp[_weight[i]] = _value[i];
            _used[_weight[i]][i] = _value[i];
        }

        for (int i = 1; i <= w; ++i) {
            for (int j = 0; j < n; ++j) {
                if (_weight[j] > i)
                    continue;
                if (_dp[i] < _dp[i - _weight[j]] + _value[j]
                    && !_used[i - _weight[j]][j]
                    && _dp[i - _weight[j]] != 0) { 
                    copy(_used[i - _weight[j]], _used[i - _weight[j]]+n, _used[i]);
                    _used[i][j] = true;
                    _dp[i] = _dp[i - _weight[j]] + _value[j];
                }
            }
        }

        int res_v = 0;
        int res_w;
        for (int i = 1; i <= w; ++i) {
            if (_dp[i] > res_v) {
                res_v = _dp[i];
                res_w = i;
            }

        }
        cout << "Case " << cnt++ << ":\n" << res_v << "\n" << res_w << endl;
    }
    return 0;
}
