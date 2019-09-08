/*
 * @Description: https://leetcode-cn.com/problems/implement-strstr/
 * @Author: 鱼摆摆
 * @Github: https://github.com/FisherCloud
 * @Date: 2019-08-29 16:07:40
 * @LastEditTime: 2019-08-29 16:41:50
 */
#include <iostream>
#include <string>

using namespace std;

int strStr(string haystack, string needle)
{
    if (needle.empty() || needle == haystack)
    {
        return 0;
    }

    if (needle.size() > haystack.size())
    {
        return -1;
    }

    for (int i = 0; i <= haystack.size() - needle.size(); i++)
    {
        if (haystack[i] == needle[0])
        {
            int j = 1;
            for (; j < needle.size();)
            {
                if (haystack[i + j] == needle[j])
                    ++j;
                else
                    break;
            }
            if (j == needle.size())
            {
                return i;
            }
        }
    }

    return -1;
}

int main(int argc, char const *argv[])
{
    cout << strStr("mississippi", "pi") << endl;
    return 0;
}
