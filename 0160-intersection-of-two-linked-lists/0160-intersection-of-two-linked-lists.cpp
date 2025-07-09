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
    ListNode* inter(ListNode* headA, ListNode* headB, int d){
        ListNode* l1 = headA;
        ListNode* l2 = headB;

        while(d){
            l1 = l1->next;
            d--;
        }

        while(l1 != l2){
            l1 = l1->next;
            l2 = l2->next;
        }
        return l1;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // brute
        // map<ListNode*, int> mpp;
        // ListNode* temp1 = headA;
        // ListNode* temp2 = headB;
        // while(temp1!=NULL){
        //     mpp[temp1]++;
        //     temp1 = temp1->next;
        // }
        // while(temp2!=NULL){
        //     mpp[temp2]++;
        //     temp2 = temp2->next;
        // }

        // for(auto mp : mpp){
        //     if (mp.second > 1){
        //         return mp.first;
        //     }
        // }
        // return NULL;

        //optimal


        int n1 = 0;
        int n2 = 0;
        ListNode* t1 = headA;
        ListNode* t2 = headB;

        while(t1 != NULL){
            n1++;
            t1 = t1->next;
        }

        while(t2 != NULL){
            n2++;
            t2 = t2->next;
        }
        
        if(n1 > n2){
            return inter(headA, headB, n1-n2);
        }
        else{
            return inter(headB, headA, n2-n1);
        }
        return NULL;
    }
};