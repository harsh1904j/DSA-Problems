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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dNode = new ListNode(-1);
        dNode->next = head;
        ListNode* temp = dNode;
        while(temp->next != NULL && temp->next->next != NULL){
            if(temp->next->val == temp->next->next->val){
                int dup = temp->next->val;
                while(temp->next != NULL && temp->next->val == dup){
                ListNode* free = temp->next;
                temp->next = temp->next->next;
                delete free;
                }
            }
            else
            temp = temp->next;
        }
        return dNode->next;
    }
};