/*
 * @Description: https://leetcode-cn.com/problems/minimum-time-difference/
 * @Author: 鱼摆摆
 * @Github: https://github.com/FisherCloud
 * @Date: 2019-08-29 15:14:04
 * @LastEditTime: 2019-08-29 15:49:36
 */
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int findMinDifference(vector<string> &timePoints)
{
    vector<int> times;
    for (auto &&it : timePoints)
    {
        int minutes = ((it[0] - '0') * 10 + (it[1] - '0')) * 60 + (it[3] - '0') * 10 + (it[4] - '0');
        times.push_back(minutes);
    }

    sort(times.begin(), times.end());

    int minMinutes = 1440, temp;
    for (int i = 1; i < times.size(); ++i)
    {
        temp = times[i] - times[i - 1];
        temp = min(temp, 1440 - temp);
        minMinutes = min(minMinutes, temp);

        if (0 == minMinutes)
        {
            return 0;
        }
    }

    temp = times[times.size() - 1] - times[0];
    temp = min(temp, 1440 - temp);
    minMinutes = min(minMinutes, temp);

    return minMinutes;
}

int main(int argc, char const *argv[])
{
    vector<string> tim = {"23:59", "00:00", "12:00", "13:54", "11:30"};
    cout << findMinDifference(tim);
    return 0;
}
