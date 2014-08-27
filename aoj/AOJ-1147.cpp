#include <algorithm>
#include <iostream>
using namespace std;

int _num[105];

int main()
{
	int n;
	while (cin >> n, n) {
        for (int i = 0; i < n; i++) {
            cin >> _num[i]; 
        }
        sort(_num, _num + n);

        int res = 0;
        for (int i = 1; i < n-1; i++) {
            res += _num[i];
        }
        res /= n-2;
        cout << res << endl;
    }

	return 0;
}
