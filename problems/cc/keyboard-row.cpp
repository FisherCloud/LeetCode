/*
 * @Description: https://leetcode-cn.com/problems/keyboard-row/
 * @Author: 鱼摆摆
 * @Github: https://github.com/FisherCloud
 * @Date: 2019-08-27 16:54:34
 * @LastEditTime: 2019-08-27 20:03:43
 */
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> findWords(vector<string> &words)
{
    vector<string> keyboard = {"qwertyuiop", "asdfghjkl", "zxcvbnm"};
    vector<string> res;
    for (auto &&it : words)
    {
        int i = 0, j = 0, k = 0;
        for (auto &&ch : it)
        {
            char temp;
            if (ch <= 'Z')
            {
                temp = ch + 32;
            }
            else
            {
                temp = ch;
            }

            if (keyboard[0].find(temp) != string::npos && 0 == j && 0 == k)
            {
                ++i;
            }
            else if (keyboard[1].find(temp) != string::npos && 0 == i && 0 == k)
            {
                ++j;
            }
            else if (keyboard[2].find(temp) != string::npos && 0 == i && 0 == j)
            {
                ++k;
            }
            else
            {
                continue;
            }
        }
        int len = it.size();
        if (len == i || len == j || len == k)
        {
            res.push_back(it);
        }
    }
    return res;
}

int main(int argc, char const *argv[])
{
    vector<string> words = {"Hello", "Alaska", "Dad", "Peace"};
    vector<string> res = findWords(words);
    for (auto &&it : res)
    {
        cout << it << endl;
    }

    return 0;
}
