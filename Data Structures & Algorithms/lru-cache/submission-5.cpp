struct ListNode {
    int key;
    int value;
    ListNode* next;
    ListNode* prev;

    ListNode(int k, int v) {
        key = k;
        value = v;
        next = nullptr;
        prev = nullptr;
    }
};

class LRUCache {
public:

    unordered_map<int, ListNode*> mp;

    int cap;

    ListNode* start;
    ListNode* end;

    LRUCache(int capacity) {
        cap = capacity;

        start = new ListNode(0, 0);
        end = new ListNode(0, 0);

        start->next = end;
        end->prev = start;
    }

    int get(int key) {

        if (mp.find(key) == mp.end()) {
            return -1;
        }

        ListNode* node = mp[key];

        
        remove(node);
        insertFront(node);

        return node->value;
    }

    void put(int key, int value) {

        if (mp.find(key) != mp.end()) {

            ListNode* node = mp[key];

            node->value = value;

            remove(node);
            insertFront(node);

            return;
        }


        ListNode* node = new ListNode(key, value);

        mp[key] = node;

        insertFront(node);

        if (mp.size() > cap) {

            ListNode* lru = end->prev;

            mp.erase(lru->key);

            remove(lru);

            delete lru;
        }
    }

private:

    void remove(ListNode* node) {

        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void insertFront(ListNode* node) {

        node->next = start->next;
        node->prev = start;

        start->next->prev = node;
        start->next = node;
    }
};