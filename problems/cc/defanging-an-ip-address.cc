/*
 * @Description: https://leetcode-cn.com/problems/defanging-an-ip-address/
 * @Author: 鱼摆摆
 * @Github: https://github.com/FisherCloud
 * @Date: 2019-08-23 19:47:30
 * @LastEditTime: 2019-08-23 20:02:10
 */

#include <iostream>
#include <string>
using namespace std;

string defangIPaddr(string address)
{
    string res = "";
    int i = 0;
    while (address[i] != '\0')
    {
        if ('.' != address[i])
        {
            res += address[i];
        }
        else
        {
            res += '[';
            res += address[i];
            res += ']';
        }

        ++i;
    }

    return res;
}

int main(int argc, char const *argv[])
{
    string str = "192.168.1.1";
    cout << defangIPaddr(str) << endl;
    return 0;
}
