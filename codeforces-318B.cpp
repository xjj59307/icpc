#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string _text;
vector<int> _heavy_pos;
vector<int> _metal_pos;
typedef vector<int>::iterator iter;

void find_substring_pos(const string &substring, vector<int> &pos_array) {
    for (int i = 0; i < _text.length() - 4; i++) {
        if (_text.compare(i, 5, substring) == 0)
            pos_array.push_back(i);
    }
}

int main()
{
    cin >> _text;

    find_substring_pos("heavy", _heavy_pos); 
    find_substring_pos("metal", _metal_pos); 
    sort(_heavy_pos.begin(), _heavy_pos.end());
    sort(_metal_pos.begin(), _metal_pos.end());

    long long count = 0;
    for (iter i = _heavy_pos.begin(); i != _heavy_pos.end(); ++i) {
        iter lower = lower_bound(_metal_pos.begin(), _metal_pos.end(), *i);
        if (lower != _metal_pos.end())
            count += _metal_pos.end() - lower;
    }
    cout << count << endl;

    return 0;
}
