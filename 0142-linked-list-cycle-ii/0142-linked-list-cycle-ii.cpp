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
    ListNode *detectCycle(ListNode *head) {
        ListNode*curr=head;
        set<ListNode*> s;
        while(curr!=NULL){
            if(s.find(curr)!=s.end()){
                return curr;
            }
            s.insert(curr);
            curr = curr->next;
        }
        return NULL;
    }
};