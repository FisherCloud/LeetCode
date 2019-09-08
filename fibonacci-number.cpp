/*
 * @Description: https://leetcode-cn.com/problems/fibonacci-number/
 * @Author: 鱼摆摆
 * @Email: fishercloud@qq.com
 * @Github: https://github.com/FisherCloud
 * @Date: 2019-09-06 15:37:17
 * @LastEditTime: 2019-09-06 15:45:29
 */
#include <iostream>
#include <vector>

using namespace std;

/**
 * 方式一：暴力法，效率太低
 * 方式二：动态规划 DP
 */
class Solution
{
public:
    int fib(int N)
    {
        if (0 == N)
        {
            return 0;
        }
        else if (N <= 2)
        {
            return 1;
        }
        else
        {
            // vector<int> dp(N + 1, 0);
            int dp[31] = {0};
            dp[1] = 1;
            dp[2] = 1;
            for (int i = 3; i <= N; i++)
            {
                dp[i] = dp[i - 1] + dp[i - 2];
            }
            return dp[N];
        }
    }
};

int main(int argc, char const *argv[])
{

    return 0;
}
