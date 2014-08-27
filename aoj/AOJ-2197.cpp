#include <iostream>
#include <cmath>
using namespace std;

int main(int argc, const char *argv[])
{
    int n;
    while (cin >> n, n) {
        int limit = n;
        int res = 0;
        for (int start = 1; start <= limit; start++) {
            for (int end = start+1; end <= limit; end++) {
                int count = end - start + 1;
                if (count * (start + end) / 2 == n)
                    res++;
            }
        }
        cout << res << endl;
    }
    return 0;
}
