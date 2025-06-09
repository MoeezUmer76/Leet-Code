class Solution {
    struct ListNode {
        int val;
        ListNode* next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode* next) : val(x), next(next) {}

    };
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head)
            return head;
        int key;
        ListNode* curr = head;
        ListNode* temp = curr;
        key = curr->val;
        while (temp->next)
        {
            temp = temp->next;
            if (temp->val != key)
            {
                key = temp->val;
                curr->next = temp;
                curr = curr->next;
            }
        }
        curr->next = nullptr;
        return head;
    }
};