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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode*slow = head;
        ListNode*fast = head;
        ListNode*prev = NULL;
        while(fast!=NULL and fast->next!=NULL){
             prev = slow;
            slow = slow->next;
            fast= fast->next->next;
           
        }
         if(slow == head and slow->next==NULL) return NULL;
         else if(slow==head and slow->next!=NULL) slow->next = NULL;
        else{
            prev->next = slow->next;
        }
        return head;
    }
};