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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
      // ListNode*l1;
      //   ListNode*l2;
        int c=0;
        ListNode*curr = new ListNode(0);
        ListNode*head = curr;
        while(l1!=NULL or l2!=NULL){
            int sum=0;
            if(l1!=NULL and l2!=NULL) {
                sum = sum+(l1->val) + (l2->val) + c;
                l1 = l1->next;
                l2 = l2->next;
            }
            else if(l1==NULL and l2!=NULL) {
                 sum = sum+(l2->val)+ c;
                  l2 = l2->next;
            }
            else if(l2==NULL and l1!=NULL){
                 sum = sum+(l1->val)+ c;
                l1 = l1->next;
            }
            curr->next = new ListNode(sum%10);
            c = sum/10;
            
            
            curr = curr->next;
        }
        if(c>0){
            curr->next = new ListNode(c);
            
        }
        head = head->next;
        return head;
    }
};