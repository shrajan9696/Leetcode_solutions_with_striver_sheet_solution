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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        set<ListNode*> s1;
        
        while(headA!=NULL){
            s1.insert(headA);
            headA = headA->next;
        }
        while(headB!=NULL){
            if(s1.find(headB)!=s1.end()) return headB;
            headB = headB->next;
        }
        return NULL;
        
    }
};