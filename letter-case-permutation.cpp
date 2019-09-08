/*
 * @Description: https://leetcode-cn.com/problems/letter-case-permutation/
 * @Author: 鱼摆摆
 * @Github: https://github.com/FisherCloud
 * @Date: 2019-08-29 21:50:41
 * @LastEditTime: 2019-08-30 18:07:30
 */
#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>

using namespace std;

vector<string> letterCasePermutation(string S)
{
    vector<string> result;
    result.push_back(S);

    // 记录每个字母的位置
    vector<int> pos;
    for (int i = 0; i < S.size(); i++)
    {
        if ((S[i] >= 'A' && S[i] <= 'Z') || (S[i] >= 'a' && S[i] <= 'z'))
        {
            pos.push_back(i);
        }
    }

    if (pos.empty())
    {
        return result;
    }

    int len = pow(2, pos.size());
    for (int i = 1; i < len; i++)
    {
        result.push_back(S);
    }

    for (int i = 0; i < len; i++)
    {
        int b = log2(i);
        for (int j = 0; j <= b; j++)
        {
            if (i & (1 << j))
            {
                int p = pos[j];
                result[i][p] ^= 1 << 5;
            }
        }
    }

    return result;
}

int main(int argc, char const *argv[])
{
    string s = "abcdefg";
    vector<string> res = letterCasePermutation(s);
    for (auto &&it : res)
    {
        cout << it << endl;
    }

    return 0;
}
