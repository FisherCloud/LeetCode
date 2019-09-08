/*
 * @Description: https://leetcode-cn.com/problems/unique-morse-code-words/
 * @Author: 鱼摆摆
 * @Github: https://github.com/FisherCloud
 * @Date: 2019-08-26 17:48:33
 * @LastEditTime: 2019-08-26 18:00:12
 */
#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

int uniqueMorseRepresentations(vector<string> &words)
{
    vector<string> morse = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};
    set<string> res;

    auto last = words.end();
    for (auto itw = words.begin(); itw != last; itw++)
    {
        string str = "";
        int len = (*itw).size();
        for (int i = 0; i < len; i++)
        {
            str += morse[(*itw)[i] - 'a'];
        }
        res.insert(str);
    }
    return res.size();
}

int main(int argc, char const *argv[])
{

    return 0;
}
