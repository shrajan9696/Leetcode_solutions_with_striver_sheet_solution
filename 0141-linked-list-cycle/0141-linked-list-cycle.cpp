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
        map<ListNode*,bool> m;
        ListNode*curr = head;
        while(curr!=NULL){
            if(m[curr] == true) return true;
            m[curr] = true;
            curr = curr->next;
            
        }
        return false;
    }
};