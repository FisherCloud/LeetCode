/*
 * @Description: https://leetcode-cn.com/problems/hamming-distance/
 * @Author: 鱼摆摆
 * @Email: fishercloud@qq.com
 * @Github: https://github.com/FisherCloud
 * @Date: 2019-09-07 21:13:08
 * @LastEditTime: 2019-09-07 21:21:10
 */
#include <iostream>

using namespace std;

class Solution
{
public:
    int hammingDistance(int x, int y)
    {
        // 不需要额外申请内存空间
        // 异或+移位
        x = x ^ y;
        y = 0;

        while (x)
        {
            y += x & 1;
            x >>= 1;
        }

        return y;
    }
};

int main(int argc, char const *argv[])
{
    int x = 0, y = 0;
    cin >> x >> y;
    Solution s;
    cout << s.hammingDistance(x, y);
    return 0;
}
