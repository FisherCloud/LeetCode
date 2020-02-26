/*
 * @Author: FisherCloud 
 * @Date: 2020-02-26 19:43:51 
 * @Last Modified by: FisherCloud
 * @Last Modified time: 2020-02-26 19:51:19
 */
// https://leetcode-cn.com/problems/cong-wei-dao-tou-da-yin-lian-biao-lcof/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    vector<int> reversePrint(ListNode *head)
    {
        vector<int> ans;
        while (head != nullptr)
        {
            ans.push_back(head->val);
            head = head->next;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main(int argc, char const *argv[])
{

    return 0;
}
