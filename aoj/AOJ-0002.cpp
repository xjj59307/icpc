#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int a, b;
    while (cin >> a >> b) {
        int sum = a + b;
        int cnt = log10(sum) + 1;
        cout << cnt << endl;
    }
    return 0;
}
