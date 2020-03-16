// https://leetcode-cn.com/problems/compress-string-lcci/

#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
    string compressString(string S)
    {
        string str;
        size_t count = 0;
        char chtmp = 0;
        for (auto &&ch : S)
        {
            if (ch != chtmp || chtmp == 0)
            {
                chtmp = ch;

                char tmp[50000] = {0};
                if (count != 0)
                {

                    sprintf(tmp, "%d", count);
                    str += tmp;
                }

                str += ch;
                count = 1;
            }
            else
            {
                count++;
            }
        }
        char tmp[50000] = {0};
        sprintf(tmp, "%d", count);
        str += tmp;

        return str.size() < S.size() ? str : S;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    cout << s.compressString("aabcccccaa") << endl;
    return 0;
}
