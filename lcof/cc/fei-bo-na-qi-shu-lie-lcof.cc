/*
 * @Author: FisherCloud 
 * @Date: 2020-02-27 17:59:15 
 * @Last Modified by: FisherCloud
 * @Last Modified time: 2020-02-27 18:18:07
 */
// https://leetcode-cn.com/problems/fei-bo-na-qi-shu-lie-lcof/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int fib(int n)
    {
        vector<int> dp = {0, 1};
        for (size_t i = 2; i <= n; i++)
        {
            dp.push_back((dp[i - 1] + dp[i - 2]) % 1000000007);
        }
        return dp[n];
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    cout << s.fib(5) << endl;
    return 0;
}
