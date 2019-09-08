/*
 * @Description: https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number/
 * @Author: 鱼摆摆
 * @Email: fishercloud@qq.com
 * @Github: https://github.com/FisherCloud
 * @Date: 2019-09-04 15:41:56
 * @LastEditTime: 2019-09-04 15:57:12
 */
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    vector<string> letterCombinations(string digits)
    {
        vector<string> key{"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> result;
        if (digits.empty())
            return result;
        result.push_back("");
        for (int i = 0; i < digits.size(); i++)
        {
            int res = digits[i] - '2';    //当前按键对应的字符串索引
            int len = result.size();      //前一次处理好的字符串数
            for (int i = 0; i < len; i++) //遍历前一次处理好的字符串
            {
                for (char m : key[res]) //遍历按键对应字符
                {
                    result.push_back(result[i] + m); //将每一种组合放到末端
                }
            }
            result.erase(result.begin(), result.begin() + len); //清除前一次的组合
        }
        return result;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<string> res = s.letterCombinations("23");

    for (auto &&it : res)
    {
        cout << it << ends;
    }

    return 0;
}
