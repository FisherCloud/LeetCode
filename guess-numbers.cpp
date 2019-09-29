/*
 * @Description: https://leetcode-cn.com/problems/guess-numbers/
 * @Author: 鱼摆摆
 * @Email: fishercloud@qq.com
 * @Github: https://github.com/FisherCloud
 * @Date: 2019-09-29 16:04:27
 * @LastEditTime: 2019-09-29 16:11:19
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    // LCP 1. 猜数字
    int game(vector<int> &guess, vector<int> &answer)
    {
        return (guess[0] == answer[0]) + (guess[1] == answer[1]) + (guess[2] == answer[2]);
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> guess = {1, 2, 3};
    vector<int> answer = {3, 2, 1};
    cout << s.game(guess, answer) << endl;
    return 0;
}
