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

        while (temp) {

            Node* copy = temp->next;
            Node* nextOriginal = copy->next;

            // Restore original list
            temp->next = nextOriginal;

            // Connect copy to next copy
            if (nextOriginal) {
                copy->next = nextOriginal->next;
            } else {
                copy->next = nullptr;
            }

            temp = nextOriginal;
        }

        return ans;

    }
};
