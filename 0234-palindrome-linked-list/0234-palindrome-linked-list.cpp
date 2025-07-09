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
    ListNode* revr(ListNode* head){
        if(head == NULL || head->next == NULL) return head;

        ListNode* prv = NULL;
        while(head){
            ListNode* fw = head->next;
            head->next = prv;
            prv = head;
            head = fw;
        }

        return prv;
    }
    bool isPalindrome(ListNode* head) {
        // brute
        // string s= "";
        // ListNode* temp = head;
        // while(temp != NULL){
        //     s +=  to_string(temp->val);
        //     temp = temp->next;
        // }

        // string x = s;
        // reverse(s.begin(), s.end());
        // if(s == x) return true;
        // return false;


        int sz = 0;
        ListNode* temp = head;
        while(temp!=NULL){
            sz++;
            temp = temp->next;
        }

        temp = head;
        int mid = sz/2;
        for(int i=0;i<mid;i++){
            temp = temp->next;
        }

        if(sz%2 != 0) temp = temp->next;
        ListNode* temp2 = temp;
        temp = head;

        ListNode* scn = revr(temp2);

        for(int i=0;i<mid;i++){
            if (temp->val != scn->val)
                return false;
            temp = temp->next;
            scn = scn->next;
        }

        return true;
    }
};