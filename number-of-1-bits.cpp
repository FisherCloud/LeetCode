/*
 * @Description: https://leetcode-cn.com/problems/number-of-1-bits/
 * @Author: 鱼摆摆
 * @Email: fishercloud@qq.com
 * @Github: https://github.com/FisherCloud
 * @Date: 2019-08-30 21:23:35
 * @LastEditTime: 2019-08-30 21:48:41
 */
#include <iostream>

using namespace std;

/**
 * 编写一个函数，输入是一个无符号整数，返回其二进制表达式中数字位数为 ‘1’ 的个数（也被称为汉明重量）
 */
int hammingWeight(uint32_t n)
{
#if 0
    // to slow
    return n ? 1 + hammingWeight(n & n - 1) : 0;
#else
    int count = 0;
    while (n)
    {
        if (n & 1)
            count++;
        n >>= 1;
    }
    return count;
#endif
}

int main(int argc, char const *argv[])
{
    uint32_t num = 0x00000000000000000000000000001011;
    cout << hammingWeight(num);
    return 0;
}
