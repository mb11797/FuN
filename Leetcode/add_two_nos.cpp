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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* sum = NULL;
        int prev_carry = 0;
        while(l1 != NULL or l2 != NULL){
            int s = 0;
            if(l1 != NULL){
                s += l1->val;
            }
            if(l2 != NULL){
                s += l2->val;
            }
            s += prev_carry;
            // int s = l1->val + l2->val + prev_carry;
            int rem = s % 10;
            ListNode*temp = new ListNode(rem);
            prev_carry = s / 10;
            temp->next = sum;
            sum = temp;
            if(l1 != NULL){
                l1 = l1->next;
            }
            if(l2 != NULL){
                l2 = l2->next;
            }
        }

        if(prev_carry != 0){
            ListNode*temp = new ListNode(prev_carry);
            temp->next = sum;
            sum = temp;
        }

        //reverse the linked list "sum"
        ListNode*prev=NULL;
        ListNode*curr=sum;
        ListNode*nxt;
        while(curr != NULL){
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        sum = prev;
        return sum;
    }
};
