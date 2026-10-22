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
    ListNode* partition(ListNode* head, int x) {
       ListNode* lNode = new ListNode(-1);
       ListNode* gNode = new ListNode(-1);
       ListNode* g = gNode;
       ListNode* l = lNode;
       ListNode* temp = head;
       while(temp != NULL){
        if(temp->val < x){
            lNode->next = temp;
            lNode = lNode->next;
        }
        else{
            gNode->next = temp;
            gNode = gNode->next;
        }
        temp = temp->next;
       }
       gNode->next = NULL;
       lNode->next = g->next;
       return l->next;
    }
};