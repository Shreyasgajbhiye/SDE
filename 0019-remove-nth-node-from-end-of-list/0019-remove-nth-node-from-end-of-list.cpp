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
        // Brute
        // if(head == NULL) return NULL;
        // int cnt = 0;
        // ListNode* temp = head;
        // while(temp != NULL){
        //     cnt++;
        //     temp = temp->next;
        // }

        // if (n == cnt) {
        //     ListNode* newHead = head->next;
        //     delete head;
        //     return newHead;
        // }
        // if(n==1 && cnt==1 )return NULL;
        // int sz = cnt-n;
        // temp = head;
        // for(int i=1;i<sz;i++){
        //     temp = temp->next;
        // }
        // ListNode* dummy = temp->next;
        // temp->next = temp->next->next;
        // delete dummy;
        // return head;

        ListNode* f = head;
        ListNode* s = head;

        for(int i=0;i<n;i++){
            f = f->next;
        }

        if (f == nullptr) {
            ListNode* newHead = head->next;
            delete head;
            return newHead;
        }

        while(f->next!=NULL){
            f = f->next;
            s = s->next;
        }

        ListNode* toDelete = s->next;
        s->next = s->next->next;
        delete toDelete;

        return head;
    }
};