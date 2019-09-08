/*
 * @Description: https://leetcode-cn.com/problems/print-zero-even-odd/
 * @Author: 鱼摆摆
 * @Email: fishercloud@qq.com
 * @Github: https://github.com/FisherCloud
 * @Date: 2019-09-02 22:09:48
 * @LastEditTime: 2019-09-03 19:21:46
 */
#include <mutex>

using namespace std;

class ZeroEvenOdd
{
private:
    int n;
    mutex mZero, mEven, mOdd;

public:
    ZeroEvenOdd(int n)
    {
        this->n = n;
        mEven.lock();
        mOdd.lock();
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber)
    {
        for (int i = 1; i <= n; i++)
        {
            mZero.lock();
            printNumber(0);
            if (i % 2)
            {
                mOdd.unlock();
            }
            else
            {
                mEven.unlock();
            }
        }
    }

    void even(function<void(int)> printNumber)
    {
        for (int i = 2; i <= n; i += 2)
        {
            mEven.lock();
            printNumber(i);
            mZero.unlock();
        }
    }

    void odd(function<void(int)> printNumber)
    {
        for (int i = 1; i <= n; i += 2)
        {
            mOdd.lock();
            printNumber(i);
            mZero.unlock();
        }
    }
};

int main(int argc, char const *argv[])
{

    return 0;
}
