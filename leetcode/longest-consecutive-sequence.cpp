#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

class Solution {

    typedef map<int, int>::iterator map_iter;
    typedef vector<int>::iterator vec_iter;

private:
    // Create a map to record the position of values.
    map<int, int> *value_index;
    // Create a map to memorize search.
    map<int, int> *max_length;

    int dp(int index, vector<int> &num) {
        int value = num[index];
        if (max_length->find(value) != max_length->end())
            return max_length->at(value);

        int length = 1;
        map_iter has_left = value_index->find(value - 1);
        map_iter has_right = value_index->find(value + 1);

        if (has_left != value_index->end())
            length = max(length, dp(value_index->at(value - 1), num) + 1);
        if (has_right != value_index->end())
            length = max(length, dp(value_index->at(value + 1), num) + 1);

        return length;
    }

public:
    Solution() {
        this->value_index = new map<int, int>();
        this->max_length = new map<int, int>();
    }

    int longestConsecutive(vector<int> &num) {
        // Initialize value_index.
        int index = 0;
        for (vec_iter iter = num.begin(); iter != num.end(); iter++)
            value_index->insert(make_pair(*iter, index++));

        // Calculate longest consecutive sequence.
        int longest = 1;
        index = 0;
        for (int i = 0; i < num.size(); ++i)
            longest = max(longest, dp(i, num));

        return longest;
    }
};

int main()
{
    Solution *solution = new Solution();
    vector<int> *num = new vector<int>();
    num->push_back(100);
    num->push_back(4);
    num->push_back(200);
    num->push_back(1);
    num->push_back(3);
    num->push_back(2);

    cout << solution->longestConsecutive(*num) << endl;

    return 0;
}
