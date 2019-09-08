/*
 * @Description: https://leetcode-cn.com/problems/print-in-order/
 * @Author: 鱼摆摆
 * @Email: fishercloud@qq.com
 * @Github: https://github.com/FisherCloud
 * @Date: 2019-09-02 21:54:35
 * @LastEditTime: 2019-09-02 22:06:43
 */
#include <mutex>
#include <iostream>

using namespace std;

class Foo
{
public:
    Foo()
    {
        m2.lock();
        m3.lock();
    }

    void first(function<void()> printFirst)
    {
        m1.lock();
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        m2.unlock();
    }

    void second(function<void()> printSecond)
    {
        m2.lock();
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        m3.unlock();
    }

    void third(function<void()> printThird)
    {
        m3.lock();
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
        m1.unlock();
    }

private:
    mutex m1, m2, m3;
};

int main(int argc, char const *argv[])
{

    return 0;
}
