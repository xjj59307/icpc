#include <iostream>
#include <algorithm>
using namespace std;

int _dp[2][260];
int _code[20];
int _input[20005];

int Range(int value) {
    if (value < 0)
        value = 0;
    if (value > 255)
        value = 255;

    return value;
}

int Square(int value) {
    return value * value;
}

int main()
{
    int n;
    int m;
    while(cin >> n >> m, n+m) {
        for (int i = 0; i < m; ++i) 
            cin >> _code[i];
        for (int i = 0; i < n; ++i)
            cin >> _input[i];
        fill_n(_dp[0], 260, -1);
        _dp[0][128] = 0;

        int current = 0;
        for (int i = 0; i < n; ++i) {
            int former = current;
            int latter = (current+1) % 2;
            fill_n(_dp[latter], 260, -1);
            for (int value = 0; value <= 255; ++value) {
                if (_dp[former][value] == -1)
                    continue;
                for (int k = 0; k < m; ++k) {
                    int lvalue = Range(value + _code[k]);
                    int rvalue = _dp[former][value] + Square(lvalue - _input[i]);
                    _dp[latter][lvalue] =
                        (_dp[latter][lvalue] == -1) ? rvalue : min(_dp[latter][lvalue], rvalue);
                }
            }
            current = latter;
        }

        int res = -1;
        for (int i = 0; i <= 255; ++i) {
            if (_dp[current][i] == -1)
                continue;
            if (res == -1)
                res = _dp[current][i];
            else
                res = min(res, _dp[current][i]);
        }
        cout << res << endl;
    }

    return 0;
}

