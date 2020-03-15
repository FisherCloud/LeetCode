/*
 * @Description: https://leetcode-cn.com/problems/er-wei-shu-zu-zhong-de-cha-zhao-lcof/
 * @Author: 鱼摆摆
 * @Email: fishercloud@qq.com
 * @Github: https://github.com/FisherCloud
 * @Date: 2020-02-21 19:40:03
 * @LastEditTime : 2020-02-21 20:15:41
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    bool findNumberIn2DArray(vector<vector<int>> &matrix, int target) // 从左下角开始查找
    {
        if (matrix.empty() || matrix[0].empty())
        {
            return false;
        }
        auto n = matrix.size();
        auto m = matrix[0].size();
        int c = n - 1;
        int r = 0;
        do
        {
            if (matrix[c][r] == target)
            {
                return true;
            }
            else if (matrix[c][r] > target)
            {
                c--;
            }
            else
            {
                r++;
            }
        } while (c >= 0 && c != n && r >= 0 && r != m);
        return false;
    }
};

int main(int argc, char const *argv[])
{
    return 0;
}
