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
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode* start = head;
        int i=0;
        while(start){
            start = start->next;
            i++;
        }

        start = head;
        int find = i-n;
        int temp=0;
        // cout<<find;


        if (find == 0) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
            return head;
        }
        
        ListNode* prev = nullptr;
        while(start){
            prev = start;
            start = start->next;
            temp++;
            if(temp==find){
                cout<<"temp"<<temp;
                prev->next = start->next;
                start->next =nullptr;
                delete(start);
                return head;
            }
        }
        return head;
    }
};
