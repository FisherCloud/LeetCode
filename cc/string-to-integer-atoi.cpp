/*
 * @Description: https://leetcode-cn.com/problems/string-to-integer-atoi/
 * @Author: 鱼摆摆
 * @Email: fishercloud@qq.com
 * @Github: https://github.com/FisherCloud
 * @Date: 2019-09-04 14:40:58
 * @LastEditTime: 2019-09-04 15:34:53
 */
#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>

using namespace std;

class Solution
{
public:
    int myAtoi(string str)
    {
#if 0
         int sign = 1;
        int i=0;
        while(str[i]==' ') i++;
        if(str[i]=='-')
        {
            sign = -1;
            i++;
        }
        else if(str[i]=='+')
            i++;
        
        int tmp = 0;
        int num;
        while(str[i]>='0'&&str[i]<='9')
        {
            if(sign==-1 && INT_MIN/10>tmp)
                return INT_MIN;
            else if(sign==1 && INT_MAX/10<tmp)
                return INT_MAX;
            else
            {
                tmp = 10*tmp;
                num = str[i] - '0';
                if(sign==-1 && INT_MIN-tmp<=-num)
                    tmp = tmp - num;
                else if(sign==-1)
                    return INT_MIN;
                else if(sign==1 && INT_MAX-tmp>=num)
                    tmp = tmp + num;
                else 
                    return INT_MAX;
            }
            i++;
        }
        
        return tmp;
#else
        // 借鉴别人的，666啊，除了效率低一点。#include <sstream>
        int digit = 0;
        istringstream is(str);
        is >> digit;
        return digit;
#endif
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    cout << s.myAtoi("-91283472332");
    return 0;
}
