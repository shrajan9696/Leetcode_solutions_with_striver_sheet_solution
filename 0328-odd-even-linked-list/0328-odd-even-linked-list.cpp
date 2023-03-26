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
    ListNode* oddEvenList(ListNode* head) {
        ListNode *es=NULL,*ee=NULL,*os=NULL,*oe=NULL;
        ListNode* curr = head;
          int x = 1;
        while(curr!=NULL){
          
            if(x%2==0){
                if(es==NULL) ee=es=curr;
                else{
                    ee->next = curr;
                    ee = curr;
                }
            }
            else{
                 if(os==NULL) oe=os=curr;
                else{
                    oe->next = curr;
                    oe = curr;
                }
            }
            curr = curr->next;
            x++;
        }
      
        if(es==NULL or os == NULL) return head;
          oe->next = es;
        ee->next = NULL;
        return os;
        
        
    }
};