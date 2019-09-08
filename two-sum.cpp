/*
 * @Description: https://leetcode-cn.com/problems/two-sum
 * @Author: 鱼摆摆
 * @Github: https://github.com/FisherCloud
 * @Date: 2019-08-23 16:43:19
 * @LastEditTime: 2019-08-23 18:52:46
 */
#include <iostream>
#include <vector>

using namespace std;

vector<int> twoSum(vector<int> &nums, int target)
{
    int i = 0, j = 0;
    auto p = nums.end();
    auto p1 = p - 1;
    auto p2 = nums.begin();

    for (auto l = nums.begin(); l < p1; ++l, ++i)
    {
        j = i + 1;
        for (auto k = l + 1; k < p; ++k, ++j)
        {
            if (target == *k + *l)
            {
                return vector<int>{i, j};
            }
            if (*k - *p2 > target)
            {
                continue;
            }
        }
    }

    return vector<int>{0, 0};
}

// [-3,4,3,90]

int main(int argc, char const *argv[])
{
    vector<int> temp;
    vector<int> nums = {-3, 4, 3, 90};
    int target = 0;
    temp = twoSum(nums, target);
    if (temp.size())
    {
        cout << "[" << *temp.begin() << "," << *(temp.begin() + 1) << "]" << endl;
    }

    return 0;
}
