class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head) return head;
        ListNode* copy = head;
        int size = 1;

        while (copy->next) {
            size++;
            copy = copy->next;
        }

        k = k % size;
        copy->next = head;

        while (size-- > k) copy = copy->next;
        ListNode* ans = copy->next;
        copy->next = nullptr;

        return ans;

    }
};