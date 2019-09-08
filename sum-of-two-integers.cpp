/*
 * @Description: https://leetcode-cn.com/problems/sum-of-two-integers/
 * @Author: 鱼摆摆
 * @Email: fishercloud@qq.com
 * @Github: https://github.com/FisherCloud
 * @Date: 2019-08-30 20:35:37
 * @LastEditTime: 2019-08-30 20:58:20
 */
#include <iostream>

using namespace std;

int getSum(int a, int b)
{
    int c = a ^ b;
    unsigned int d = a & b;
#if 1
    // method one(recursion)
    return d ? getSum(c, d << 1) : c;
#else
    // method two(loop)
    while (d)
    {
        d <<= 1;
        int t = c ^ d;
        d = c & d;
        c = t;
    }
    return c;
#endif
}

int main(int argc, char const *argv[])
{
    cout << getSum(11, 13) << endl;
    return 0;
}
