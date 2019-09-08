/*
 * @Description: https://leetcode-cn.com/problems/detect-capital/
 * @Author: 鱼摆摆
 * @Github: https://github.com/FisherCloud
 * @Date: 2019-08-29 15:50:17
 * @LastEditTime: 2019-08-29 15:57:27
 */
#include <iostream>
#include <string>

using namespace std;

bool detectCapitalUse(string word)
{
    int upper = 0, flag = 0;

    if (word[0] >= 'A' && word[0] <= 'Z')
    {
        flag = 1;
    }

    for (auto &&it : word)
    {
        if (it >= 'A' && it <= 'Z')
        {
            upper++;
        }
    }

    return upper == 0 || upper == word.size() || (flag && upper == 1);
}

int main(int argc, char const *argv[])
{
    string str = "Flag";
    cout << detectCapitalUse(str) << endl;
    return 0;
}
