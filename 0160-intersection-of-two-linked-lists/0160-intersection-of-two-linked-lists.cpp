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
        map<ListNode*, int> mpp;
        ListNode* temp1 = headA;
        while(temp1 != NULL){
            mpp[temp1]++;
            temp1 = temp1->next;
        }
        temp1 = headB;
        while(temp1 != NULL){
            mpp[temp1]++;
            temp1 = temp1->next;
        }
        temp1 = headA;
        while(temp1 != NULL){
            if(mpp[temp1] >= 2) return temp1;
            temp1 = temp1->next;
        }
        temp1 = headB;
        while(temp1 != NULL){
            if(mpp[temp1] >= 2) return temp1;
            temp1 = temp1->next;
        }
        return NULL;
    }
};