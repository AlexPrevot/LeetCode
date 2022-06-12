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
    ListNode* detectCycle(ListNode* head)
    {
        if (!head) return head;

        ListNode* slow = head;
        ListNode* fast = head;

        do {
            slow = slow->next;
            fast = fast->next;
            if (fast) fast = fast->next;
        } while (fast && slow != fast);

        if (!fast) return fast;

        slow = head;

        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }


        return fast;
    }
};