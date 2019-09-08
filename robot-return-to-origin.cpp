/*
 * @Description: https://leetcode-cn.com/problems/robot-return-to-origin/
 * @Author: 鱼摆摆
 * @Email: fishercloud@qq.com
 * @Github: https://github.com/FisherCloud
 * @Date: 2019-09-07 21:23:02
 * @LastEditTime: 2019-09-07 21:27:03
 */
#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
    bool judgeCircle(string moves)
    {
        int x = 0, y = 0;

        int len = moves.size();
        for (int i = 0; i < len; i++)
        {
            if (moves[i] == 'L')
            {
                --x;
            }
            else if (moves[i] == 'R')
            {
                ++x;
            }
            else if (moves[i] == 'U')
            {
                ++y;
            }
            else if (moves[i] == 'D')
            {
                --y;
            }
        }
        return x == 0 && y == 0 ? true : false;
    }
};

int main(int argc, char const *argv[])
{

    return 0;
}
