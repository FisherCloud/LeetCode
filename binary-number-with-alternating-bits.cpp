/*
 * @Description: https://leetcode-cn.com/problems/binary-number-with-alternating-bits/
 * @Author: 鱼摆摆
 * @Email: fishercloud@qq.com
 * @Github: https://github.com/FisherCloud
 * @Date: 2019-08-30 21:01:56
 * @LastEditTime: 2019-08-30 21:22:17
 */
#include <iostream>

using namespace std;

bool hasAlternatingBits(int n)
{
    n = (n ^ n >> 1);
    return !(n & ((long)n + 1));
}

int main(int argc, char const *argv[])
{
    for (int i = 0; i <= 10; i++)
    {
        cout << hasAlternatingBits(i) << endl;
    }

    return 0;
}
