/*
 * @Description: https://leetcode-cn.com/problems/coin-change/
 * @Author: 鱼摆摆
 * @Email: fishercloud@qq.com
 * @Github: https://github.com/FisherCloud
 * @Date: 2019-09-05 16:04:36
 * @LastEditTime: 2019-09-07 18:40:24
 */
#include <iostream>
#include <vector>

using namespace std;

/**
 * 332：零钱兑换
 * 第一个想到的就是贪心算法，然而并不太适用于此题，很容易碰到反例
 * 然后发现本题是背包问题中典型的完全背包问题，可以从动态规划入手
 */
class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;

        for (int i = 1; i <= amount; i++)
        {
            for (auto &&coin : coins)
            {
                if (coin <= i)
                {
                    dp[i] = min(dp[i], dp[i - coin] + 1);
                }
            }
        }

        return dp[amount] > amount ? -1 : dp[amount];
    }
};

int main(int argc, char const *argv[])
{
    vector<int> coins = {1, 2, 5};
    int amount = 0;
    cin >> amount;
    Solution s;
    cout << s.coinChange(coins, amount);
    return 0;
}
