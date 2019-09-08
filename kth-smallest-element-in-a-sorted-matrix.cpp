/*
 * @Description: https://leetcode-cn.com/problems/kth-smallest-element-in-a-sorted-matrix/
 * @Author: 鱼摆摆
 * @Github: https://github.com/FisherCloud
 * @Date: 2019-08-27 20:33:51
 * @LastEditTime: 2019-08-27 20:59:53
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
/**
 * 暴力解题
 */
int kthSmallest(vector<vector<int>> &matrix, int k)
{
    int n = matrix.size();
    for (int i = 1; i < n; i++)
    {
        matrix[0].insert(matrix[0].end(), matrix[i].begin(), matrix[i].end());
    }
    sort(matrix[0].begin(), matrix[0].end());

    return matrix[0][k - 1];
}

int main(int argc, char const *argv[])
{
    vector<vector<int>> matrix = {{1, 5, 9}, {10, 11, 13}, {12, 13, 15}};
    int k = 0;
    cout << "k:";
    cin >> k;
    cout << kthSmallest(matrix, k);
    return 0;
}
