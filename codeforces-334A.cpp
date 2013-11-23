#include "iostream"
using namespace std;

int main()
{
    int n, i, j;
    cin >> n;

    if (n % 2 == 0) {
        for (i = 1; i <= n; ++i) {
            for (j = 0; j < n; ++j) {
                int value = i + j*n;
                if (j % 2) value = (j+1)*n -i + 1;
                cout << value << " ";
            }
            cout << endl;
        }
    } else {
        for (i = 1; i <= n; ++i) {
            for (j = 0; j < n-2; ++j) {
                int value = i + j*n;
                if (j % 2) value = (j+1)*n -i + 1;
                cout << value << " ";
            }
            int last_two = j*n + i + 1;
            if (i == n) last_two -= n;
            cout << last_two << " ";

            int last_one = (j+1)*n + i - 1;
            if (i == 1) last_one += n;
            cout << last_one << " " << endl;
        }
    }

    return 0;
}