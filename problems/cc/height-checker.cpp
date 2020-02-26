/*
 * @Description: https://leetcode-cn.com/problems/height-checker/
 * @Author: 鱼摆摆
 * @Email: fishercloud@qq.com
 * @Github: https://github.com/FisherCloud
 * @Date: 2019-09-29 16:23:50
 * @LastEditTime: 2019-09-29 21:46:35
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    // 1051. 高度检查器
    int heightChecker(vector<int> &heights)
    {
        int len = heights.size();
        vector<int> array = heights;

        sort(array.begin(), array.end());

        int result = 0;
        for (int i = 0; i < len; i++)
        {
            result += (array[i] != heights[i]);
        }

        return result;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> heights = {1, 1, 5, 4, 2, 1, 3};
    cout << s.heightChecker(heights) << endl;
    return 0;
}
