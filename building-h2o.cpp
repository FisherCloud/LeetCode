/*
 * @Description: https://leetcode-cn.com/problems/building-h2o/
 * @Author: 鱼摆摆
 * @Email: fishercloud@qq.com
 * @Github: https://github.com/FisherCloud
 * @Date: 2019-09-02 16:29:52
 * @LastEditTime: 2019-09-02 21:41:55
 */
#include <iostream>
#include <mutex>
#include <condition_variable>

using namespace std;

class H2O
{
public:
    H2O()
    {
    }

    void hydrogen(function<void()> releaseHydrogen)
    {
        unique_lock<mutex> lk(m);
        cv.wait(lk, [this]() { return count_h < 2; });
        // releaseHydrogen() outputs "H". Do not change or remove this line.
        releaseHydrogen();
        count_h++;
        if (2 == count_h && 1 = count_o)
        {
            count_h = 0;
            count_o = 0;
        }
        cv.notify_all();
    }

    void oxygen(function<void()> releaseOxygen)
    {
        unique_lock<mutex> lk(m);
        cv.wait(lk, [this]() { return count_o < 1; });
        // releaseOxygen() outputs "O". Do not change or remove this line.
        releaseOxygen();
        count_o++;
        if (2 == count_h && 1 = count_o)
        {
            count_h = 0;
            count_o = 0;
        }
        cv.notify_one();
    }

public:
    int count_h = 0;
    int count_o = 0;
    mutex m;
    condition_variable cv;
};

int main(int argc, char const *argv[])
{

    return 0;
}
