/*
 * @Author: FisherCloud 
 * @Date: 2020-02-27 16:13:47 
 * @Last Modified by: FisherCloud
 * @Last Modified time: 2020-02-27 16:47:50
 */
// https://leetcode-cn.com/problems/yong-liang-ge-zhan-shi-xian-dui-lie-lcof/
#include <iostream>
#include <stack>

using namespace std;

class CQueue
{
public:
    CQueue()
    {
        this->stackone = new stack<int>;
        this->stacktwo = new stack<int>;
    }

    void appendTail(int value)
    {
        this->stackone->push(value);
    }

    int deleteHead()
    {
        if (this->stacktwo->empty())
        {
            if (this->stackone->empty())
                return -1;
            else
            {
                while (!this->stackone->empty())
                {
                    this->stacktwo->push(this->stackone->top());
                    this->stackone->pop();
                }
            }
        }
        int ans = this->stacktwo->top();
        this->stacktwo->pop();
        return ans;
    }

private:
    stack<int> *stackone;
    stack<int> *stacktwo;
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */

int main(int argc, char const *argv[])
{
    cout << "lcof-09" << endl;
    return 0;
}
