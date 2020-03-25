/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr)
            return nullptr;
        if (head->next == nullptr)
            return head;
        ListNode* p = head;
        head = head->next;
        p->next = nullptr;
        while(head->next != nullptr) {
            ListNode* tmp = head->next;
            head->next = p;
            p = head;
            head = tmp;
        }
        head->next = p;
        return head;
    }
};