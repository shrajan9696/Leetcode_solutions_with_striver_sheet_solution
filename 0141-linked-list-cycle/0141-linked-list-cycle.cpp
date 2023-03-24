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
    bool hasCycle(ListNode *head) {
        
        // changes in structure of linked list
        
//         map<ListNode*,bool> m;
//         ListNode*curr = head;
//         while(curr!=NULL){
//             if(m[curr] == true) return true;
//             m[curr] = true;
//             curr = curr->next;
            
//         }
//         return false;
        
        // changes in the pointer of linked list
        
   ListNode*temp = new ListNode(0);
        ListNode* curr = head;
        while(curr!=NULL){
            if(curr->next == temp) return true;
            ListNode*x = curr->next;
            curr->next = temp;
            curr = x;
            
        }
        return false;
        
        
        
    }
};