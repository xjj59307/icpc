#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> _words;
typedef vector<string>::iterator iter;
string _letter;
bool _fail = false;

void find_word(int &cur_pos, const string &word) {
    for (int i = 0; i < word.length(); ++i) {
        while (cur_pos != _letter.length() && _letter[cur_pos] != word[i])
            cur_pos++;
        if (cur_pos == _letter.length())
            _fail = true;
    }
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string word;
        cin >> word;
        _words.push_back(word);
    }
    cin >> _letter;

    int cur_pos = 0;
    find_word(cur_pos, "<3");
    for (iter i = _words.begin(); i != _words.end(); ++i) {
        find_word(cur_pos, *i); 
        find_word(cur_pos, "<3");
    }
    if (_fail)
        cout << "no" << endl;
    else
        cout << "yes" << endl;

    return 0;
}
