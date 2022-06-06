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
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        if (!headA || !headB) return nullptr;

        ListNode* cpy1 = headA;
        ListNode* cpy2 = headB;

        while ((cpy1 || cpy2) && (cpy1 != cpy2)) {
            if (!cpy1) cpy1 = headB;
            if (!cpy2) cpy2 = headA;

            if (cpy1 == cpy2) return cpy1;

            cpy1 = cpy1->next;
            cpy2 = cpy2->next;
        }

        return cpy1;
    }
};