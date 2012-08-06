#include <iostream>
#include <string>
using namespace std;

int _left[26] = {
    1, 1, 1, 1, 1, 1, 1, 
    0, 0, 0, 0, 0, 0, 0, 
    0, 0, 1, 1, 1, 1, 0, 
    1, 1, 1, 0, 1
};

int main(int argc, const char *argv[])
{
    string input;
    while (cin >> input, input != "#") {
        int res = 0;
        int current = _left[input[0] - 'a'];
        for (int i = 1; i < input.length(); ++i) {
            if (current != _left[input[i] - 'a']) {
                res++;
                current = (current+1) % 2;
            }
        }

        cout << res << endl;
    }   
    return 0;
}
