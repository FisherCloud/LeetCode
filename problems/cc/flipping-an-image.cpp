/*
 * @Description: https://leetcode-cn.com/problems/flipping-an-image/
 * @Author: 鱼摆摆
 * @Github: https://github.com/FisherCloud
 * @Date: 2019-08-26 18:02:16
 * @LastEditTime: 2019-08-26 18:23:17
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> flipAndInvertImage(vector<vector<int>> &A)
{
    for (auto &&it : A)
    {
        reverse(it.begin(), it.end());
        for (auto &&i : it)
        {
            i ? i = 0 : i = 1;
        }
    }
    return A;
}

int main(int argc, char const *argv[])
{
    vector<vector<int>> A = {{1, 1, 0}, {1, 0, 1}, {0, 0, 0}};
    auto res = flipAndInvertImage(A);

    for (auto &&it : res)
    {
        for (auto &&i : it)
        {
            cout << i << ",";
        }
        cout << endl;
    }

    return 0;
}
