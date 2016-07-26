#include <iostream>
#include <vector>
using namespace std;

struct Value {
    Value(int _status, int _len) : status(_status), len(_len) {}
    int status;
    int len;
};

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.size() == 0) return 0;

        size_t size = nums.size();
        int max_len = 1;
        vector<Value> dp(size, Value(0, 1));

        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < i; ++j) {
                if (dp[j].status == 0 && nums[i] != nums[j] ||
                    dp[j].status == 1 && nums[i] < nums[j] ||
                    dp[j].status == -1 && nums[i] > nums[j])
                {
                    if (dp[j].len + 1 > dp[i].len) {
                        dp[i].len = dp[j].len + 1;
                        max_len = max(max_len, dp[i].len);
                    } else {
                        continue;
                    }

                    dp[i].status = nums[i] > nums[j] ? 1 : -1;
                }
            }
        }

        return max_len;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {0, 0};

    printf("%d\n", solution.wiggleMaxLength(nums));

    return 0;
}