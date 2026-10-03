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
    ListNode* findKth(ListNode* curr, int k){

        while(curr && k>0){
            curr = curr->next;
            k--;
        }
        return curr;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {

        ListNode* dummy = new ListNode(0, head);
        ListNode* prevG = dummy;
        
        while(true){
            ListNode* kth = findKth(prevG,k);
            if(!kth){
                break;
            }

            ListNode* curr = prevG->next;
            ListNode* nextG = kth->next;
            ListNode* prev = kth->next;

            while(curr!=nextG){
                ListNode* temp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = temp;
            }

            ListNode* temp = prevG->next;;
            prevG->next = kth;
            prevG = temp; 
        }

        return dummy->next;
    }
};
