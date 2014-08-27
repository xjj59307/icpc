#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    int k;
    int count = 0;
    cin >> n >> k;

    for (int i = 0; i < n; ++i) {
        int j;
        string a;
        bool check[10] = {false};
        cin >> a;
        for (j = 0; j < a.length(); j++)
            check[a[j] - '0'] = true;
        for (j = 0; j <= k; j++)
            if (!check[j]) break;
        if (j == k+1) count++; 
    }

    cout << count << endl;

    return 0;
}
