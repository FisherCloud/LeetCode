// https://leetcode-cn.com/problems/the-masseuse-lcci/
// dp[i][0] = max(dp[i-1][0], dp[i-1][1])
// dp[i][1] = dp[i-1][0] + nums[i]
// return max(dp[i][0], dp[i][1])

class Solution {
public:
    int massage(vector<int>& nums) {
        int len = nums.size();
        if (nums.empty())
            return 0;
        else if (nums.size() == 1)
            return nums[0];
        else if (nums.size() == 2)
            return *max_element(nums.begin(), nums.end());
        else {
            vector<int> dp(2, 0);
            dp[1] = nums[0];
            for (int i = 1; i < len; ++i) {
                int dp0 = max(dp[0], dp[1]);
                int dp1 = dp[0] + nums[i];
                dp[0] = dp0;
                dp[1] = dp1;
            }
            return max(dp[0], dp[1]);
        }
    }
};
