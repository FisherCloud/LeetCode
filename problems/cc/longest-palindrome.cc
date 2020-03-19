// https://leetcode-cn.com/problems/longest-palindrome/

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution
{
public:
    int longestPalindrome(string s)
    {
        unordered_map<char, int> chars;
        for (auto &&c : s)
        {
            ++chars[c];
        }
        int count = 0;
        for (auto &&item : chars)
        {
            if (item.second % 2)
            {
                ++count;
            }
        }
        return count == 0 ? s.size() : s.size() - count + 1;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    cout << s.longestPalindrome("abccccdd") << endl;
    return 0;
}
