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
    ListNode* swapPairs(ListNode* head) {
        ListNode* dNode = new ListNode(-1);
        dNode->next = head;
        ListNode* temp = dNode;
            while(temp->next != NULL && temp->next->next != NULL){
            ListNode* first  = temp->next;
            ListNode* second = temp->next->next;
            first->next  = second->next;   
            second->next = first;         
            temp->next   = second;        
            temp = first;
            }                
    return dNode->next;
    }
};