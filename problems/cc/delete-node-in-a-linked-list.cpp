/*
 * @Description: https://leetcode-cn.com/problems/delete-node-in-a-linked-list/
 * @Author: 鱼摆摆
 * @Github: https://github.com/FisherCloud
 * @Date: 2019-08-23 20:31:13
 * @LastEditTime: 2019-08-23 20:43:17
 */

#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void deleteNode(ListNode *node)
{
    ListNode *p = node->next;
    /*
    * 执行用时 :24 ms, 在所有 C++ 提交中击败了37.86%的用户
    * 内存消耗 :9.3 MB, 在所有 C++ 提交中击败了5.55%的用户
    */
    //*node = *p;
    /*
    * 执行用时 :12 ms, 在所有 C++ 提交中击败了99.62%的用户
    * 内存消耗 :9 MB, 在所有 C++ 提交中击败了88.01%的用户
    */
    node->val = p->val;
    node->next = p->next;
    p->next = nullptr;
    delete p;
}

int main(int argc, char const *argv[])
{

    return 0;
}
