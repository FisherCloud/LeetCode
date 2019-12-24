/*
 * @Description: https://leetcode-cn.com/problems/multiply-strings/
 * @Author: 鱼摆摆
 * @Email: fishercloud@qq.com
 * @Github: https://github.com/FisherCloud
 * @Date: 2019-08-31 13:21:50
 * @LastEditTime: 2019-09-02 16:07:06
 */
#include <iostream>

using namespace std;

string multiply(string num1, string num2)
{
    if ('0' == num1[0] || '0' == num2[0])
    {
        return "0";
    }

#if 1
    // 竖式乘法
    int n1 = num1.size();
    int n2 = num2.size();
    string res(n1 + n2, '0');
    for (int i = n2 - 1; i >= 0; i--)
    {
        for (int j = n1 - 1; j >= 0; j--)
        {
            int temp = (res[i + j + 1] - '0') + (num1[j] - '0') * (num2[i] - '0');
            res[i + j + 1] = temp % 10 + '0'; //当前位
            res[i + j] += temp / 10;          //前一位加上进位，res[i+j]已经初始化为'0'，加上int类型自动转化为char，所以此处不加'0'
        }
    }

    //去除首位'0'
    for (int i = 0; i < n1 + n2; i++)
    {
        if (res[i] != '0')
            return res.substr(i);
    }
#else
    // FFT：数字超大时效率高(但，不会啊)
#endif
    return "0";
}

int main(int argc, char const *argv[])
{

    return 0;
}
