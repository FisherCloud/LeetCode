/*
 * @Description: https://leetcode-cn.com/problems/compare-strings-by-frequency-of-the-smallest-character/
 * @Author: 鱼摆摆
 * @Github: https://github.com/FisherCloud
 * @Date: 2019-08-29 20:18:01
 * @LastEditTime: 2019-08-29 21:15:14
 */
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> numSmallerByFrequency(vector<string> &queries, vector<string> &words)
{
    int n = queries.size();
    int m = words.size();
    vector<int> result(n, 0);
    vector<int> temp;

    for (int i = 0; i < m; i++)
    {
        vector<int> count(26, 0);
        for (int j = 0; j < words[i].size(); j++)
        {
            ++count[words[i][j] - 'a'];
        }
        for (int j = 0; j < 26; j++)
        {
            if (count[j] > 0)
            {
                temp.push_back(count[j]);
                break;
            }
        }
    }

    sort(temp.begin(), temp.end());

    for (int i = 0; i < n; i++)
    {
        vector<int> count(26, 0);
        for (int j = 0; j < queries[i].size(); j++)
        {
            ++count[queries[i][j] - 'a'];
        }
        for (int j = 0; j < 26; j++)
        {
            if (count[j] > 0)
            {
                vector<int>::iterator it = upper_bound(temp.begin(), temp.end(), count[j]);
                result[i] = temp.end() - it;
                break;
            }
        }
    }

    return result;
}

int main(int argc, char const *argv[])
{
    vector<string> q = {"bbb", "cc"};
    vector<string> w = {"a", "aa", "aaa", "aaaa"};

    vector<int> res = numSmallerByFrequency(q, w);

    for (auto &&it : res)
    {
        cout << it << ends;
    }

    return 0;
}
