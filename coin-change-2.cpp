/*
 * @Description: https://leetcode-cn.com/problems/coin-change-2/
 * @Author: 鱼摆摆
 * @Email: fishercloud@qq.com
 * @Github: https://github.com/FisherCloud
 * @Date: 2019-09-10 21:45:15
 * @LastEditTime: 2019-09-10 21:51:02
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int change(int amount, vector<int> &coins)
    {
        if (coins.empty() && amount == 0)
        {
            return 1;
        }

        if (coins.empty())
        {
            return 0;
        }

        vector<int> dp(amount + 1, 0);
        dp[0] = 1;
        for (auto &&coin : coins)
        {
            for (int i = coin; i <= amount; i++)
            {
                dp[i] += dp[i - coin];
            }
        }
        return dp[amount];
    }
};

int main(int argc, char const *argv[])
{
    vector<int> coins = {1, 2, 5};
    Solution s;
    cout << s.change(100, coins);
    return 0;
}
