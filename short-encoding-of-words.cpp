/*
 * @Description: https://leetcode-cn.com/problems/short-encoding-of-words/
 * @Author: 鱼摆摆
 * @Email: fishercloud@qq.com
 * @Github: https://github.com/FisherCloud
 * @Date: 2019-09-08 14:28:03
 * @LastEditTime: 2019-09-08 16:46:58
 */
#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

class Solution
{
public:
    int minimumLengthEncoding(vector<string> &words)
    { // 参考官方题解
#if 1
        // 存储后缀
        set<string> good(words.begin(), words.end());
        for (auto &&word : words)
        {
            for (int i = 1; i < word.size(); i++)
            {
                good.erase(word.substr(i));
            }
        }

        int ans = 0;
        for (auto &&word : good)
        {
            ans += word.size() + 1;
        }

        return ans;
#else
// 字典树
#endif
    }
};

int main(int argc, char const *argv[])
{
    vector<string> words = {"time", "me", "bell"};
    Solution s;
    cout << s.minimumLengthEncoding(words);
    return 0;
}
