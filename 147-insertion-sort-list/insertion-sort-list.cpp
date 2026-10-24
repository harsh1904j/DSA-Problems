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
    ListNode* insertionSortList(ListNode* head) {
        ListNode* dNode = new ListNode(-1);
        ListNode* curr = head;
        while(curr != NULL){
            ListNode* nNode = curr->next;
            ListNode* prev = dNode;
            while(prev->next != NULL && prev->next->val < curr->val){
                prev = prev->next;
            }
            curr->next = prev->next;
            prev->next = curr;
            curr = nNode;
        }
        return dNode->next;
    }
};