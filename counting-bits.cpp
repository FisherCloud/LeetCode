/*
 * @Description: https://leetcode-cn.com/problems/counting-bits/
 * @Author: 鱼摆摆
 * @Email: fishercloud@qq.com
 * @Github: https://github.com/FisherCloud
 * @Date: 2019-08-30 21:49:28
 * @LastEditTime: 2019-08-30 21:53:59
 */
#include <iostream>
#include <vector>

using namespace std;

vector<int> countBits(int num)
{
    vector<int> count(num + 1, 0);
    for (int i = 1; i <= num; i++)
    {
#if 0
        // 动态规划+最低有效位
        count[i] = count[i >> 1] + (i & 1); // x / 2 is x >> 1 and x % 2 is x & 1
#else
        // 动态规划+最后设置位
        count[i] = count[i & (i - 1)] + 1;
#endif
    }
    return count;
}

int main(int argc, char const *argv[])
{

    return 0;
}
