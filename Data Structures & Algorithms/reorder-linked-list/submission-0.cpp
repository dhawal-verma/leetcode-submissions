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
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;

        while(fast!=nullptr && fast->next != nullptr){
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* curr = slow->next;
        ListNode* prev = nullptr;
        slow->next = nullptr;

        while(curr){
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        
       ListNode* start = head;
ListNode* second = prev;

while (second) {

    ListNode* temp1 = start->next;
    ListNode* temp2 = second->next;

    start->next = second;
    second->next = temp1;

    start = temp1;
    second = temp2;
}
    }
};
