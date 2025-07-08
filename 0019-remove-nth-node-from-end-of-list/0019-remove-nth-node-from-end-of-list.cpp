/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL) return NULL;
        int cnt = 0;
        ListNode* temp = head;
        while(temp != NULL){
            cnt++;
            temp = temp->next;
        }
        if(n==1 && cnt==1 )return NULL;
        int sz = cnt-n;
        temp = head;
        for(int i=1;i<sz;i++){
            temp = temp->next;
        }
        ListNode* dummy = temp->next;
        temp->next = temp->next->next;
        delete dummy;
        return head;
    }
};