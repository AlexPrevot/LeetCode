class Solution {
public:
    ListNode* swapPairs(ListNode* head)
    {
        if (head == nullptr)
            return head;

        if (head->next == nullptr)
            return head;

        ListNode* ans = head->next;

        ListNode* next = swapPairs(head->next->next);

        head->next->next = next;

        ListNode* mem = head->next->next;
        head->next->next = head;
        head->next = mem;


        return ans;
    }
};