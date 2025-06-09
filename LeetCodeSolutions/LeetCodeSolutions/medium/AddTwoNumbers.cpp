
class Solution {
    struct ListNode {
        int val;
        ListNode* next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode* next) : val(x), next(next) {}
        
    };
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* list3 = new ListNode();
        ListNode* head = list3;
        int carry = 0;
        int sum = 0;
        while (l1 && l2)
        {
            sum = l1->val + l2->val;
            sum = sum + carry;
            if (sum > 9)
            {
                carry = 1;
                sum = sum % 10;
            }
            else
                carry = 0;
            list3->val = sum;
            list3->next = new ListNode();
            list3 = list3->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        if (l1)
        {
            while (l1)
            {
                sum = l1->val + carry;
                if (sum > 9)
                {
                    carry = 1;
                    sum = sum % 10;
                }
                else
                    carry = 0;
                list3->val = sum;
                list3->next = new ListNode();
                list3 = list3->next;
                l1 = l1->next;
            }
        }
        else
        {
            while (l2)
            {
                sum = l2->val + carry;
                if (sum > 9)
                {
                    carry = 1;
                    sum = sum % 10;
                }
                else
                    carry = 0;
                list3->val = sum;
                list3->next = new ListNode();
                list3 = list3->next;
                l2 = l2->next;
            }
        }
        if (carry == 1)
        {
            list3->val = 1;
            list3->next = new ListNode();
            list3 = list3->next;

        }
        list3 = head;
        ListNode* prev;
        while (list3->next)
        {
            prev = list3;
            list3 = list3->next;
        }
        delete list3;
        prev->next = nullptr;
        return head;
    }
};