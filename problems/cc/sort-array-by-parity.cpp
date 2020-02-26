/*
 * @Description: https://leetcode-cn.com/problems/sort-array-by-parity/
 * @Author: 鱼摆摆
 * @Github: https://github.com/FisherCloud
 * @Date: 2019-08-27 15:48:20
 * @LastEditTime: 2019-08-27 16:09:56
 */
#include <iostream>
#include <vector>
#include <utility>

using namespace std;

vector<int> sortArrayByParity(vector<int> &A)
{
    int i = 0;
    int j = A.size() - 1;

    if (0 == j)
    {
        return A;
    }

    while (i < j)
    {
        if (0 == A[i] % 2)
        {
            ++i;
        }
        else if (1 == A[j] % 2)
        {
            --j;
        }
        else if (1 == A[i] % 2 && 0 == A[j] % 2)
        {
            swap(A[i], A[j]);
            ++i;
            --j;
        }
    }
    return A;
}

int main(int argc, char const *argv[])
{
    vector<int> num = {0, 5};
    vector<int> res = sortArrayByParity(num);
    for (auto &&it : res)
    {
        cout << it << ends;
    }

    return 0;
}
