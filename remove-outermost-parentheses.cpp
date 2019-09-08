/*
 * @Description: https://leetcode-cn.com/problems/remove-outermost-parentheses/
 * @Author: 鱼摆摆
 * @Github: https://github.com/FisherCloud
 * @Date: 2019-08-26 13:58:49
 * @LastEditTime: 2019-08-26 15:44:51
 */
#include <iostream>
#include <string>

using namespace std;
/**
 * 效率高 
 */
// string removeOuterParentheses(string S)
// {
//     int L = 1;
//     int R = 0;
//     string str;
//     for (int i = 1; i < S.size(); i++)
//     {
//         if (S[i] == '(')
//         {
//             L++;
//         }
//         else
//         {
//             R++;
//         }
//         if (R != L)
//         {
//             str.push_back(S[i]);
//         }
//         else
//         {
//             i++;
//             L = 1;
//             R = 0;
//         }
//     }
//     return str;
// }

/**
 * 效率低
 */
string removeOuterParentheses(string S)
{
    int L = 1;
    int R = 0;
    S.erase(0, 1);
    for (int i = 0; i < S.size(); i++)
    {
        if (S[i] == '(')
        {
            L++;
        }
        else
        {
            R++;
        }
        if (R == L)
        {
            S.erase(i, 2);
            i--;
            L = 1;
            R = 0;
        }
    }
    return S;
}

int main(int argc, char const *argv[])
{
    string str = "(()())(())(()(()))";
    cout << str << endl;
    cout << removeOuterParentheses(str) << endl;
    return 0;
}
