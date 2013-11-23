#include <iostream>
#include <algorithm>
using namespace std;

int _a[100005];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> _a[i];
    
    if (n <= 2) {
        cout << n << endl;
    } else {
        int current = 2;
        int longest = 2;
        for (int i = 2; i < n; ++i) {
            if (_a[i] == _a[i-2] + _a[i-1]) {
                current++;
            } else {
                longest = max(longest, current);
                current = 2;
            }
        }
        cout << max(longest, current) << endl;
    }

    return 0;
}
