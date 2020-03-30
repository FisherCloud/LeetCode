/*
 * @Description: https://leetcode-cn.com/problems/integer-replacement/solution/
 * @Author: 鱼摆摆
 * @Email: fishercloud@qq.com
 * @Github: https://github.com/FisherCloud
 * @Date: 2019-09-04 12:07:22
 * @LastEditTime: 2019-09-04 12:50:26
 */
#include <iostream>

using namespace std;

/**
 * 如果数位上是0，直接到下一个bit并且步数+1；如果是1，则步数+2，
 * 并且根据下一位到底是1/0，执行加减操作。如果下一位同为1，
 * 则+1（一步去掉2个‘1’）；如为0，则-1。（即不做任何操作）
 */
int integerReplacement(int n)
{
    int ret = 0;
    while (n > 3)
    {
        if (n % 2)
        {
            n >>= 1;
            if (n % 2)
                n++;
            ret += 2;
        }
        else
        {
            n >>= 1;
            ret++;
        }
    }
    return ret + n - 1;
}

int main(int argc, char const *argv[])
{
    cout << integerReplacement(8);
    return 0;
}
