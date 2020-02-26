/*
 * @Description: https://leetcode-cn.com/problems/reverse-integer/
 * @Author: 鱼摆摆
 * @Email: fishercloud@qq.com
 * @Github: https://github.com/FisherCloud
 * @Date: 2019-09-04 14:04:08
 * @LastEditTime: 2019-09-04 14:37:02
 */
#include <iostream>

using namespace std;

class Solution
{
public:
    int reverse(int x)
    {
#if __SIZEOF_POINTER__ == 4
        // 32位机器
        int res = 0;
        while (x != 0)
        {
            int pop = x % 10;
            if (res > Integer.MAX_VALUE / 10 || (res == Integer.MAX_VALUE / 10 && pop > 7))
                return 0;
            if (res < Integer.MIN_VALUE / 10 || (res == Integer.MIN_VALUE / 10 && pop < -8))
                return 0;
            res = res * 10 + pop;
            x /= 10;
        }
        return res;
#elif __SIZEOF_POINTER__ == 8
        // 64位机器
        long res = 0;
        while (x)
        {
            int pop = x % 10;
            x /= 10;
            res = res * 10 + pop;
        }
        return (res > INT_MAX || res < INT_MIN) ? 0 : static_cast<int>(res);
#endif
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    cout << s.reverse(125);
    return 0;
}
