/*
 * @Description: https://leetcode-cn.com/problems/er-wei-shu-zu-zhong-de-cha-zhao-lcof/
 * @Author: 鱼摆摆
 * @Email: fishercloud@qq.com
 * @Github: https://github.com/FisherCloud
 * @Date: 2020-02-21 19:40:03
 * @LastEditTime : 2020-02-21 20:08:02
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    bool findNumberIn2DArray(vector<vector<int>> &matrix, int target)
    {
        auto n = matrix[0].size();
        auto m = matrix.size();
        int c = n - 1;
        int r = 0;
        do // 左下角开始遍历
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
        } while (c != n && r != m);
        return false;
    }
};

int main(int argc, char const *argv[])
{
    return 0;
}
