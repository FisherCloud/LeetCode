// https://leetcode-cn.com/problems/find-words-that-can-be-formed-by-characters/

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution
{
public:
    int countCharacters(vector<string> &words, string chars)
    {
        unordered_map<char, int> char_s;
        for (auto &&c : chars)
            ++char_s[c];
        int ans = 0;
        for (auto &&w : words)
        {
            unordered_map<char, int> word_s;
            for (auto &&c : w)
                ++word_s[c];
            bool flag = true;
            for (auto &&c : w)
            {
                if (char_s[c] < word_s[c])
                {
                    flag = false;
                    break;
                }
            }
            ans += (flag ? w.size() : 0);
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{

    return 0;
}
