/*
 * @Description: https://leetcode-cn.com/problems/degree-of-an-array/
 * @Author: 鱼摆摆
 * @Github: https://github.com/FisherCloud
 * @Date: 2019-08-29 14:12:20
 * @LastEditTime: 2019-08-29 15:13:45
 */
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int findShortestSubArray(vector<int> &nums)
{
    int len = nums.size();
    if (1 == len)
    {
        return 1;
    }

    unordered_map<int, vector<int>> um;
    for (int i = 0; i < len; ++i)
    {
        um[nums[i]].push_back(i);
    }

    int degree = 0;
    for (auto &&it : nums)
    {
        degree = max(degree, (int)um[it].size());
    }

    for (auto &&it : nums)
    {
        if (degree == um[it].size())
        {
            len = min(len, (um[it][degree - 1] - um[it][0] + 1));
        }
    }

    return len;
}

int main(int argc, char const *argv[])
{
    vector<int> nums = {1, 2, 2, 3, 1, 2};
    cout << findShortestSubArray(nums);
    return 0;
}
