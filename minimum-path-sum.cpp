/*
 * @Description: https://leetcode-cn.com/problems/minimum-path-sum/
 * @Author: 鱼摆摆
 * @Github: https://github.com/FisherCloud
 * @Date: 2019-08-26 20:12:46
 * @LastEditTime: 2019-08-26 20:30:21
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minPathSum(vector<vector<int>> &grid)
{
    int m = grid[0].size(); // 列
    int n = grid.size();    // 行
    if (0 == n || 0 == m)
    {
        return 0;
    }
    for (int i = 1; i < m; i++)
    {
        grid[0][i] += grid[0][i - 1];
    }
    for (int i = 1; i < n; i++)
    {
        grid[i][0] += grid[i - 1][0];
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            grid[i][j] += min(grid[i][j - 1], grid[i - 1][j]);
        }
    }
    return grid[n - 1][m - 1];
}

int main(int argc, char const *argv[])
{
    vector<vector<int>> grid = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
    cout << minPathSum(grid) << endl;
    return 0;
}
