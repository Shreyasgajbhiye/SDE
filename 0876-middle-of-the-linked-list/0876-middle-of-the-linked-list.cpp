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
    ListNode* middleNode(ListNode* head) {
        // int cnt = 0;
        // ListNode* temp = head;
        // while(temp != NULL){
        //     cnt++;
        //     temp = temp->next;
        // }

        // int mid = cnt/2;
        // temp = head;
        // while(mid != 0){
        //     temp = temp->next;
        //     mid--;
        // }
        // return temp;

        ListNode* s = head;
        ListNode* f = head;
        while( f != NULL && f->next != NULL){
            s = s->next;
            f = f->next->next;
        }
        return s;
    }
};