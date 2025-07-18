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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL) return head;
        int cnt = 0;
        ListNode* t = head;
        while(t != NULL){
            cnt++;
            t = t->next;
        }
        k = k%cnt;
        
        for(int i=0;i<k;i++){
            ListNode* temp = head;
            while(temp->next->next != NULL){
                temp = temp->next;
            }

            ListNode* dummy = temp->next;
            temp->next = NULL;
            dummy->next = head;
            head = dummy;
        }

        return head;
    }
};