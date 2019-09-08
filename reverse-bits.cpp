/*
 * @Description: https://leetcode-cn.com/problems/reverse-bits/
 * @Author: 鱼摆摆
 * @Email: fishercloud@qq.com
 * @Github: https://github.com/FisherCloud
 * @Date: 2019-09-04 12:52:05
 * @LastEditTime: 2019-09-04 14:03:28
 */
// 190. 颠倒二进制位
#include <iostream>

using namespace std;

uint32_t reverseBits(uint32_t n)
{
    uint32_t result = 0;
    for (int i = 0; i < 32; i++)
    {
        result = (result << 1) | (n & 1);
        n >>= 1;
    }
    return result;
}

int main(int argc, char const *argv[])
{
    uint32_t num = 43261596;
    cout << reverseBits(num);
    return 0;
}
