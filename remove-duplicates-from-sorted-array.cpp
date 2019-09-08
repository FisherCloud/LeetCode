/*
 * @Description: https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array/
 * @Author: 鱼摆摆
 * @Github: https://github.com/FisherCloud
 * @Date: 2019-08-28 23:21:08
 * @LastEditTime: 2019-08-28 23:40:17
 */
#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int removeDuplicates(vector<int> &nums)
{
    if (nums.empty())
    {
        return 0;
    }

    int low = 0;
    int len = nums.size();
    for (int i = 1; i < len; ++i)
    {
        if (nums[low] != nums[i])
        {
            ++low;
            swap(nums[low], nums[i]);
        }
    }

    return low + 1;
}

int main(int argc, char const *argv[])
{
    vector<int> nums = {0, 0, 1, 1, 1, 5, 6, 7, 7, 7};
    cout << removeDuplicates(nums) << endl;
    return 0;
}
