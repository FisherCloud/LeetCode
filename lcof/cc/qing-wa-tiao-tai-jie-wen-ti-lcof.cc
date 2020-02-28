/*
 * @Author: FisherCloud 
 * @Date: 2020-02-28 19:26:05 
 * @Last Modified by: FisherCloud
 * @Last Modified time: 2020-02-28 20:00:40
 */
// https://leetcode-cn.com/problems/qing-wa-tiao-tai-jie-wen-ti-lcof/
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int numWays(int n)
    {
        vector<int> dp = {1, 1};
        for (size_t i = 2; i <= n; i++)
        {
            dp.push_back((dp[i - 1] + dp[i - 2]) % 1000000007);
        }
        return dp[n];
    }
};

int main(int argc, char const *argv[])
{
    return 0;
}
