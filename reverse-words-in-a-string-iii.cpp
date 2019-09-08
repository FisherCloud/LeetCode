/*
 * @Description: https://leetcode-cn.com/problems/reverse-words-in-a-string-iii/
 * @Author: 鱼摆摆
 * @Github: https://github.com/FisherCloud
 * @Date: 2019-08-27 16:24:42
 * @LastEditTime: 2019-09-04 16:27:07
 */
#include <iostream>
#include <algorithm>

using namespace std;

string reverseWords(string s)
{
    string ::iterator first = s.begin();
    string ::iterator second;
    string ::iterator last = s.end();
    do
    {
        for (second = first; *second != ' ' && second != last; ++second)
        {
        }

        reverse(first, second);
        if (second != last)
        {
            first = ++second;
        }
    } while (second != last);
    return s;
}

int main(int argc, char const *argv[])
{
    string str = "Hn";
    cout << reverseWords(str) << endl;
    return 0;
}
