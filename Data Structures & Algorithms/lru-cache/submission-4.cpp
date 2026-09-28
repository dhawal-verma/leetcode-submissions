struct ListNode {
    int val;
    ListNode* next;
    ListNode* prev;

    ListNode(int key) {
        val = key;
        next = nullptr;
        prev = nullptr;
    }
};

class LRUCache {
public:

    unordered_map<int, int> mp;

    int cap;
    int size = 0;

    ListNode* start = nullptr;
    ListNode* end = nullptr;

    LRUCache(int capacity) {
        cap = capacity;
    }

    int get(int key) {

        // Key doesn't exist
        if (mp.find(key) == mp.end()) {
            return -1;
        }

        // Find node in linked list
        ListNode* curr = start;

        while (curr != nullptr) {

            if (curr->val == key) {

                // Move to front if not already there
                if (curr != start) {

                    // Remove curr
                    curr->prev->next = curr->next;

                    if (curr->next != nullptr) {
                        curr->next->prev = curr->prev;
                    }
                    else {
                        end = curr->prev;
                    }

                    // Put curr at front
                    curr->next = start;
                    curr->prev = nullptr;

                    start->prev = curr;
                    start = curr;
                }

                return mp[key];
            }

            curr = curr->next;
        }

        return -1;
    }

    void put(int key, int value) {

        // Check if key already exists
        if (mp.find(key) != mp.end()) {

            mp[key] = value;

            // Find existing node
            ListNode* curr = start;

            while (curr != nullptr) {

                if (curr->val == key) {

                    // Move to front
                    if (curr != start) {

                        curr->prev->next = curr->next;

                        if (curr->next != nullptr) {
                            curr->next->prev = curr->prev;
                        }
                        else {
                            end = curr->prev;
                        }

                        curr->next = start;
                        curr->prev = nullptr;

                        start->prev = curr;
                        start = curr;
                    }

                    return;
                }

                curr = curr->next;
            }
        }

        // New key
        ListNode* curr = new ListNode(key);

        mp[key] = value;

        // Empty cache
        if (start == nullptr) {
            start = curr;
            end = curr;
            size++;
            return;
        }

        // Insert at front
        curr->next = start;
        start->prev = curr;
        start = curr;

        size++;

        // Capacity exceeded
        if (size > cap) {

            ListNode* temp = end;

            end = end->prev;
            end->next = nullptr;

            mp.erase(temp->val);

            delete temp;

            size--;
        }
    }
};