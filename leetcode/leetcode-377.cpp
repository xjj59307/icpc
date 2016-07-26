#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        if (dp.find(target) != dp.end()) return dp[target];

        int result = 0;

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] < target) result += combinationSum4(nums, target - nums[i]);
            if (nums[i] == target) result++;
        }

        dp[target] = result;
        return result;
    }

private:
    map<int, int> dp;
};

int main() {
    Solution solution;
    vector<int> nums = {4, 2, 1};

    printf("%d\n", solution.combinationSum4(nums, 32));

    return 0;
}
