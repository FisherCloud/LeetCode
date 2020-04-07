// https://leetcode-cn.com/problems/rotate-matrix-lcci/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        // 水平翻转
        for (int i = 0; i < n / 2; ++i) {
            for (int j = 0; j < n; ++j) {
                swap(matrix[i][j], matrix[n - i - 1][j]);
            }
        }
        // 主对角线翻转
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
};

int main(int argc, char const* argv[]) {
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    Solution s;
    s.rotate(matrix);
    for (auto&& arr : matrix) {
        for (auto&& item : arr) {
            cout << item << ",";
        }
        cout << endl;
    }
    return 0;
}
