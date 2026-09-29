class Solution {
public:

    ListNode* addTwo(ListNode* l1, ListNode* l2) {

        ListNode dummy(0);
        ListNode* temp = &dummy;

        while (l1 && l2) {

            if (l1->val > l2->val) {
                temp->next = l2;
                l2 = l2->next;
            }
            else {
                temp->next = l1;
                l1 = l1->next;
            }

            temp = temp->next;
        }

        if (l1) {
            temp->next = l1;
        }

        if (l2) {
            temp->next = l2;
        }

        return dummy.next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {

        if (lists.empty()) {
            return nullptr;
        }

        int n = lists.size();

        while (n > 1) {

            int index = 0;

            for (int i = 0; i < n; i += 2) {

                if (i + 1 < n) {
                    lists[index] = addTwo(lists[i], lists[i + 1]);
                }
                else {
                    lists[index] = lists[i];
                }

                index++;
            }

            n = index;
        }

        return lists[0];
    }
};