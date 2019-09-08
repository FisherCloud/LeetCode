/*
 * @Description: https://leetcode-cn.com/problems/jewels-and-stones/
 * @Author: 鱼摆摆
 * @Github: https://github.com/FisherCloud
 * @Date: 2019-08-23 20:04:21
 * @LastEditTime: 2019-08-23 20:28:00
 */

#include <iostream>
#include <string>

using namespace std;

int numJewelsInStones(string J, string S)
{
    int amount[58] = {0};
    int ans = 0;
    for (int i = 0; i < S.size(); i++)
    {
        amount[S[i] - 'A']++;
    }
    for (int i = 0; i < J.size(); i++)
    {
        ans += amount[J[i] - 'A'];
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    string J = "z";
    string S = "ZZAbbbb";
    cout << numJewelsInStones(J, S) << endl;
    return 0;
}
