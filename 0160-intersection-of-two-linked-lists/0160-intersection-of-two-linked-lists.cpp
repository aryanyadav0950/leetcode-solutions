class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) return nullptr;
        
        ListNode *ptrA = headA;
        ListNode *ptrB = headB;
        
        while (ptrA != ptrB) {
            ptrA = (ptrA != nullptr) ? ptrA->next : headB;
            ptrB = (ptrB != nullptr) ? ptrB->next : headA;
        }
        
        return ptrA;
    }
};