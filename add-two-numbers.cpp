/*
 * @Description: 
 * @Author: 鱼摆摆
 * @Github: https://github.com/FisherCloud
 * @Date: 2019-08-23 18:53:58
 * @LastEditTime: 2019-08-23 19:43:00
 */
#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    ListNode *dummyHead = new ListNode(0);
    ListNode *curr = dummyHead;
    int carry = 0;
    int sum;
    while (l1 || l2)
    {
        sum = 0;
        if (l1)
        {
            sum += l1->val;
            l1 = l1->next;
        }
        if (l2)
        {
            sum += l2->val;
            l2 = l2->next;
        }
        sum += carry;
        carry = sum / 10;
        curr->next = new ListNode(sum % 10);
        curr = curr->next;
    }
    if (carry > 0)
        curr->next = new ListNode(carry);
    return dummyHead->next;
}

int main(int argc, char const *argv[])
{

    return 0;
}
