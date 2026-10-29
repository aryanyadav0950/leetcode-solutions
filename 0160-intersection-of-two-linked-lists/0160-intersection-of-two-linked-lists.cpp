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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA=0;
        int lenB=0;
        ListNode* tempA=headA;
        ListNode* tempB=headB;
        while(tempA!=NULL){
            lenA++;
            tempA=tempA->next;
        }
        while(tempB!=NULL){
            lenB++;
            tempB=tempB->next;
        }
        tempA=headA;
        tempB=headB;
        if(lenA>lenB){
            int diff=lenA-lenB;
            for(int i=1;i<=diff;i++){
                tempA=tempA->next;
            }
            while(tempA!=tempB){
                tempA=tempA->next;
                tempB=tempB->next;
            }
            return tempA;
        }
        else{
            int diff=lenB-lenA;
            for(int i=1;i<=diff;i++){
                tempB=tempB->next;
            }
            while(tempA!=tempB){
                tempA=tempA->next;
                tempB=tempB->next;
            }
            return tempA;

        }

        
    }
};