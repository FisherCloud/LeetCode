/*
 * @Description: https://leetcode-cn.com/problems/number-complement/
 * @Author: 鱼摆摆
 * @Github: https://github.com/FisherCloud
 * @Date: 2019-08-27 16:10:06
 * @LastEditTime: 2019-08-27 16:21:57
 */
#include <iostream>

using namespace std;

int findComplement(int num)
{
    int tmp = 1;
    while (tmp < num)
    {
        tmp <<= 1;
        tmp += 1;
    }
    return (tmp ^ num);
}

int main(int argc, char const *argv[])
{
    int num = 0;
    cin >> num;
    cout << findComplement(num);
    return 0;
}
