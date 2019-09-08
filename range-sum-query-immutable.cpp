/*
 * @Description: https://leetcode-cn.com/problems/range-sum-query-immutable/
 * @Author: 鱼摆摆
 * @Github: https://github.com/FisherCloud
 * @Date: 2019-08-26 19:05:32
 * @LastEditTime: 2019-08-26 19:49:30
 */
#include <iostream>
#include <vector>

using namespace std;

class NumArray
{
public:
    NumArray(vector<int> &nums)
    {
        int len = nums.size();
        for (int i = 1; i < len; i++)
        {
            nums[i] += nums[i - 1];
        }
        res = &nums;
    };

    int sumRange(int i, int j)
    {
        return (*res)[j] - (i ? (*res)[i - 1] : 0);
    };

private:
    vector<int> *res;
};

int main(int argc, char const *argv[])
{
    vector<int> nums = {-2, 0, 3, -5, 2, -1};
    NumArray *obj = new NumArray(nums);
    int param = obj->sumRange(2, 5);
    cout << param << endl;
    delete obj;
    return 0;
}
