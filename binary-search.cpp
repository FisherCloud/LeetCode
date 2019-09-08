/*
 * @Description: https://leetcode-cn.com/problems/binary-search/
 * @Author: 鱼摆摆
 * @Github: https://github.com/FisherCloud
 * @Date: 2019-08-28 22:02:16
 * @LastEditTime: 2019-08-28 22:25:16
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#if 0
/**
 * STL库
 */
int search(vector<int> &nums, int target)
{
    vector<int>::iterator it = lower_bound(nums.begin(), nums.end(), target);
    if (it != nums.end() && !(target < *it))
    {
        return it - nums.begin();
    }

    return -1;
}
#else
/**
 * 迭代
 */
int search(vector<int> &nums, int target)
{
    int low = 0, high = nums.size() - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (nums[mid] == target)
            return mid;
        else if (nums[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}
#endif

int main(int argc, char const *argv[])
{
    vector<int> nums = {-1, 0, 3, 5, 9, 12};
    cout << search(nums, 9) << endl;
    return 0;
}
