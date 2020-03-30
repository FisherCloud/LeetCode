/*
 * @Description: https://leetcode-cn.com/problems/add-binary/
 * @Author: 鱼摆摆
 * @Email: fishercloud@qq.com
 * @Github: https://github.com/FisherCloud
 * @Date: 2019-08-31 12:02:20
 * @LastEditTime: 2019-08-31 13:21:17
 */
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string addBinary(string a, string b)
{
#if 0
    string s(a.size() + b.size(), 0);
    int c = 0, i = a.size() - 1, j = b.size() - 1;
    while (i >= 0 || j >= 0 || c == 1)
    {
        c += i >= 0 ? a[i--] - '0' : 0;
        c += j >= 0 ? b[j--] - '0' : 0;
        s.push_back((c & 1) + '0');
        c >>= 1;
    }
    reverse(s.begin(), s.end());
    return s;
#else
    int al = a.size();
    int bl = b.size();
    while (al < bl) //让两个字符串等长，若不等长，在短的字符串前补零，否则之后的操作会超出索引
    {
        a = '0' + a;
        ++al;
    }
    while (al > bl)
    {
        b = '0' + b;
        ++bl;
    }
    for (int j = a.size() - 1; j > 0; --j) //从后到前遍历所有的位数，同位相加
    {
        a[j] = a[j] - '0' + b[j];
        if (a[j] >= '2') //若大于等于字符‘2’，需要进一
        {
            a[j] = (a[j] - '0') % 2 + '0';
            a[j - 1] = a[j - 1] + 1;
        }
    }
    a[0] = a[0] - '0' + b[0]; //将ab的第0位相加
    if (a[0] >= '2')          //若大于等于2，需要进一
    {
        a[0] = (a[0] - '0') % 2 + '0';
        a = '1' + a;
    }
    return a;
#endif
}

int main(int argc, char const *argv[])
{
    cout << addBinary("1010", "1011");
    return 0;
}
