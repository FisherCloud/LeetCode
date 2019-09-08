/*
 * @Description: https://leetcode-cn.com/problems/remove-element/
 * @Author: 鱼摆摆
 * @Email: fishercloud@qq.com
 * @Github: https://github.com/FisherCloud
 * @Date: 2019-08-30 22:05:38
 * @LastEditTime: 2019-08-30 22:31:51
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int removeElement(vector<int> &nums, int val)
{
#if 0
    // C++ Lib
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); ++i)
    {
        if (val == nums[i])
        {
            nums.erase(nums.begin() + i);
            --i;
        }
    }
    return nums.size();
#else
    // double pointor
    if (nums.empty())
    {
        return 0;
    }

    vector<int>::iterator itb = nums.begin();
    vector<int>::iterator ite = nums.end() - 1;
    int count = 0;
    while (itb <= ite)
    {
        if (val == *ite)
        {
            --ite;
            count++;
        }
        else if (val == *itb)
        {
            swap(*itb, *ite);
            ++itb;
            --ite;
            count++;
        }
        else
        {
            ++itb;
        }
    }
    return nums.size() - count;

#endif
}

int main(int argc, char const *argv[])
{
    vector<int> nums = {1};
    cout << removeElement(nums, 1);
    return 0;
}
