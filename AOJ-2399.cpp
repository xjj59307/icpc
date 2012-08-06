#include <iostream>
#include <set>
using namespace std;

int _p[105][105];
int _M[105];
int _l[105];
set<int> _check;

int main(int argc, const char *argv[])
{
    int n;
    int k;
    while (cin >> n, n) {
        for (int i = 0; i < n; i++) {
            cin >> _M[i];
            for (int j = 0; j < _M[i]; j++)
                cin >> _p[i][j];
        }
        cin >> k;
        for (int i = 0; i < k; i++) 
            cin >> _l[i];
       
        int cnt = 0;
        int id = -1;
        for (int i = 0; i < n; ++i) {
            _check.clear();
            int j;
            for (j = 0; j < _M[i]; ++j)
                _check.insert(_p[i][j]);
            for (j = 0; j < k; ++j) {
                if (_check.find(_l[j]) == _check.end())
                    break;
            }
            if (j == k) {
                cnt++;
                id = i;
            }       
        }

        if (id != -1 && cnt == 1)
            cout << (id+1) << endl;
        else
            cout << "-1" << endl;
    }
    return 0;
}
