#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    void reverseWords(string &s) {
        size_t index = 0;

        for (size_t i = 0; i < s.length(); ++i) {
            if (s[i] != ' ' || (i > 0 && s[i - 1] != ' ')) {
                s[index++] = s[i];
            }
        }

        if (s[index - 1] == ' ') {
            index--;
        }

        s = s.substr(0, index);
        reverse(s.begin(), s.end());

        size_t start = 0;
        for (size_t i = 0; i < s.length(); ++i) {
            if (s[i] == ' ') {
                reverse(s.begin() + start, s.begin() + i);
                start = i + 1;
            }

            if (i == s.length() - 1) {
                reverse(s.begin() + start, s.end());
            }
        }
    }
};

int main() {
    Solution solution;
    string test = "   a   b  c d   e  ";
    solution.reverseWords(test);
    cout << test;

    return 0;
}