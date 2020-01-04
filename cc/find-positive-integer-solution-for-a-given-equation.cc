/*
 * @Description: https://leetcode-cn.com/problems/find-positive-integer-solution-for-a-given-equation/
 * @Author: 鱼摆摆
 * @Email: fishercloud@qq.com
 * @Github: https://github.com/FisherCloud
 * @Date: 2020-01-04 12:42:11
 * @LastEditTime : 2020-01-04 13:23:16
 */

#include <iostream>
#include <vector>

using namespace std;

/*
 * // This is the custom function interface.
 * // You should not implement it, or speculate about its implementation
 * class CustomFunction {
 * public:
 *     // Returns f(x, y) for any given positive integers x and y.
 *     // Note that f(x, y) is increasing with respect to both x and y.
 *     // i.e. f(x, y) < f(x + 1, y), f(x, y) < f(x, y + 1)
 *     int f(int x, int y);
 * };
 */

class Solution
{
public:
    vector<vector<int>> findSolution(CustomFunction &customfunction, int z)
    {
        int front = 1;
        int back = z;

        vector<vector<int>> ans;

        while (front <= z && back > 0)
        {
            int res = customfunction.f(front, back);
            if (z == res)
            {
                vector<int> tmp;
                tmp.push_back(front);
                tmp.push_back(back);
                ans.push_back(tmp);
                front++;
                back--;
            }
            else if (z > res)
            {
                front++;
            }
            else
            {
                back--;
            }
        }

        return ans;
    }
};

int main(int argc, char const *argv[])
{
    CustomFunction c;
    Solution s;
    auto res = s.findSolution(c, 2);
    return 0;
}
