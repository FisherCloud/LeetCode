/*
 * @Description: https://leetcode-cn.com/problems/print-foobar-alternately/
 * @Author: 鱼摆摆
 * @Email: fishercloud@qq.com
 * @Github: https://github.com/FisherCloud
 * @Date: 2019-09-02 21:42:50
 * @LastEditTime: 2019-09-02 21:54:23
 */
#include <iostream>
#include <mutex>
#include <condition_variable>

using namespace std;

class FooBar
{
private:
    int n;
    mutex mf;
    mutex mb;

public:
    FooBar(int n)
    {
        this->n = n;
        mb.lock();
    }

    void foo(function<void()> printFoo)
    {
        for (int i = 0; i < n; i++)
        {
            mf.lock();
            // printFoo() outputs "foo". Do not change or remove this line.
            printFoo();
            mb.unlock();
        }
    }

    void bar(function<void()> printBar)
    {
        for (int i = 0; i < n; i++)
        {
            mb.lock();
            // printBar() outputs "bar". Do not change or remove this line.
            printBar();
            mf.unlock();
        }
    }
};

int main(int argc, char const *argv[])
{

    return 0;
}
