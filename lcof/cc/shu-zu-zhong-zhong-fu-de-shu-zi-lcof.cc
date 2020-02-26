/*
 * @Description: https://leetcode-cn.com/problems/shu-zu-zhong-zhong-fu-de-shu-zi-lcof/
 * @Author: 鱼摆摆
 * @Email: fishercloud@qq.com
 * @Github: https://github.com/FisherCloud
 * @Date: 2020-02-21 19:20:37
 * @LastEditTime : 2020-02-21 19:36:49
 */
#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution
{
public:
    int findRepeatNumber(vector<int> &nums)
    {
        unordered_set<int> tmp;
        for (auto &&item : nums)
        {
            if (tmp.find(item) == tmp.end()) // 如果找不到
            {
                tmp.insert(item); // 插入到set中
            }
            else
            {
                return item;
            }
        }
        return -1;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> nums = {2, 3, 1, 0, 2, 5, 3};
    cout << s.findRepeatNumber(nums);
    return 0;
}
