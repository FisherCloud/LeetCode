/*
 * @Author: FisherCloud 
 * @Date: 2020-02-26 17:25:30 
 * @Last Modified by: FisherCloud
 * @Last Modified time: 2020-02-26 17:32:43
 */
// https://leetcode-cn.com/problems/ti-huan-kong-ge-lcof/
#include <iostream>

using namespace std;

class Solution
{
public:
    string replaceSpace(string s)
    {
        string res = "";
        size_t const len = s.size();
        for (size_t i = 0; i < len; i++)
            if (s[i] == ' ')
                res += "%20";
            else
                res += s[i];

        return res;
    }
};

int main(int argc, char const *argv[])
{

    return 0;
}
