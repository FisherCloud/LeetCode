// https://leetcode-cn.com/problems/middle-of-the-linked-list/
/**
 * Definition for singly-linked list.
 */
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
    ListNode *middleNode(ListNode *head) // 快慢指针
    {
        if (head == nullptr)
            return nullptr;

        ListNode *slow = head;
        ListNode *fast = head;

        while (fast->next != nullptr)
        {
            fast = fast->next;
            if (fast->next != nullptr)
                fast = fast->next;
            slow = slow->next;
        }

        return slow;
    }
};