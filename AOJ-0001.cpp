#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int heights[10];
    for (int i = 0; i < 10; ++i) {
        cin >> heights[i]; 
    }
    sort(heights, heights+10);
    for (int i = 9; i > 6; --i) {
        cout << heights[i] << endl;
    }
    return 0;
}
