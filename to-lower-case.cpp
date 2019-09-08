/*
 * @Description: https://leetcode-cn.com/problems/to-lower-case/
 * @Author: 鱼摆摆
 * @Github: https://github.com/FisherCloud
 * @Date: 2019-08-26 16:05:05
 * @LastEditTime: 2019-08-26 16:55:58
 */
#include <iostream>
#include <string>

using namespace std;

string toLowerCase(string str)
{
    int len = str.size();
    for (int i = 0; i < len; i++)
    {
        if (str[i] <= 'Z' && str[i] >= 'A')
        {
            str[i] += 32;
        }
    }
    return str;
}

int main(int argc, char const *argv[])
{
    string ss = "Hello";
    cout << toLowerCase(ss) << endl;
    return 0;
}
