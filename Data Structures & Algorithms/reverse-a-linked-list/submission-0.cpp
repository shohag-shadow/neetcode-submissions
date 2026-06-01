class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* h1 = nullptr; // Crucial fix: initialize to nullptr
        ListNode* h2;
        ListNode* tmp;
        
        h2 = head;
        while(h2 != nullptr)
        {
            tmp = h2->next;
            h2->next = h1;
            h1 = h2;
            h2 = tmp;
        }
        return h1;
    }
};
