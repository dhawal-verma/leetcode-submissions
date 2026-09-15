/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==nullptr)return nullptr;
        
        Node* temp = head;
        while(temp){
            Node* copy = new Node(temp->val);
            copy->next = temp->next;
            temp->next = copy;
            temp = temp->next->next;
        }
        temp = head;

        Node* curr = head->next;
        while(temp){
            curr = temp->next;
            
            if(temp->random){
                curr->random = temp->random->next;   
            }
            temp = curr->next;
        }
        
        temp = head;
        Node* ans = head->next;
        curr = head->next;

        while (temp) {
            curr = temp->next;
            temp->next = curr->next;
            temp = curr->next;
            if(temp)
            curr->next = temp->next;
        }

        return ans;

    }
};
