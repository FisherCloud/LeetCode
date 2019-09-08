/*
 * @Description: https://leetcode-cn.com/problems/reverse-string/
 * @Author: 鱼摆摆
 * @Github: https://github.com/FisherCloud
 * @Date: 2019-08-27 15:38:23
 * @LastEditTime: 2019-09-06 10:54:50
 */
#include <iostream>
#include <vector>
#include <utility>

using namespace std;

void reverseString(vector<char> &s)
{
    int i = 0;
    int j = s.size() - 1;
    while (i <= j)
    {
        swap(s[i], s[j]);
        ++i;
        --j;
    }
}

int main(int argc, char const *argv[])
{
    vector<char> s = {'h', 'e', 'l', 'l', 'o'};
    reverseString(s);
    for (auto &&it : s)
    {
        cout << it;
    }

    return 0;
}
