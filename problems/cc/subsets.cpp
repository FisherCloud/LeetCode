/*
 * @Description: https://leetcode-cn.com/problems/subsets/
 * @Author: 鱼摆摆
 * @Github: https://github.com/FisherCloud
 * @Date: 2019-08-29 21:33:31
 * @LastEditTime: 2019-08-29 21:45:33
 */
#include <iostream>
#include <vector>

using namespace std;

#define _BN

#ifdef _BIT
/**
 * 位运算
 */
vector<vector<int>> subsets(vector<int> &nums)
{
    int S = nums.size();
    int N = (1 << S);
    vector<vector<int>> res;
    for (int i = 0; i < N; ++i)
    {
        vector<int> v;
        for (int j = 0; j < S; ++j)
            if (i & (1 << j))
                v.push_back(nums[j]);
        res.push_back(v);
    }
    return res;
}
#endif

#ifdef _BN
/**
 * 层序遍历
 */
vector<vector<int>> subsets(vector<int> &nums)
{
    vector<vector<int>> result(1);

    for (int i = 0; i < nums.size(); i++)
    {
        int len = result.size();
        for (int j = 0; j < len; j++)
        {
            vector<int> temp = result[j];
            temp.push_back(nums[i]);
            result.push_back(temp);
        }
    }
    return result;
}
#endif
#ifdef _RES
/**
 * 回溯算法
 */
vector<vector<int>> subsets(vector<int> &nums)
{
    vector<vector<int>> res;
    vector<int> tmp;
    helper(res, tmp, nums, 0);
    return res;
}
void helper(vector<vector<int>> &res, vector<int> tmp, vector<int> &nums, int level)
{
    if (tmp.size() <= nums.size())
    {
        res.push_back(tmp);
    }
    for (int i = level; i < nums.size(); i++)
    {
        tmp.push_back(nums[i]);
        helper(res, tmp, nums, i + 1);
        tmp.pop_back();
    }
}
#endif
#ifdef _DFS
/**
 * 深度优先搜索
 */
void helper(vector<vector<int>> &res, vector<int> tmp, vector<int> &nums, int level)
{
    if (level >= nums.size())
    {
        res.push_back(tmp);
        return;
    }
    tmp.push_back(nums[level]);
    helper(res, tmp, nums, level + 1);
    tmp.pop_back();
    helper(res, tmp, nums, level + 1);
}

vector<vector<int>> subsets(vector<int> &nums)
{
    vector<vector<int>> res;
    vector<int> tmp;
    helper(res, tmp, nums, 0);
    return res;
}
#endif

int main(int argc, char const *argv[])
{
    return 0;
}
