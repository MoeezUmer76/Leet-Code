#include<iostream>
using namespace std;

class Solution {
    struct ListNode {
        int val;
        ListNode* next;
        ListNode() : val(0), next(nullptr){}
        ListNode(int x) : val(x), next(nullptr){}
        ListNode(int x, ListNode* y) : val(x), next(y){}
    };

public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* list3 = new ListNode();
        ListNode* head = list3;
        if (!list1 && list2)
        {
            list3->val = list2->val;
            list2 = list2->next;
            while (list2)
            {
                list3->next = new ListNode(list2->val);
                list2 = list2->next;
                list3 = list3->next;
            }
            list3 = head;
            return list3;
        }
        else if (list1 && !list2)
        {
            list3->val = list1->val;
            list1 = list1->next;
            while (list1)
            {
                list3->next = new ListNode(list1->val);
                list1 = list1->next;
                list3 = list3->next;
            }
            list3 = head;
            return list3;
        }
        else if (!list1 && !list2)
        {
            list3 = nullptr;
            return list3;
        }
        if (list1->val < list2->val)
        {
            list3->val = list1->val;
            list1 = list1->next;
        }
        else
        {
            list3->val = list2->val;
            list2 = list2->next;
        }
        while (list1 && list2)
        {
            if (list1->val < list2->val)
            {
                list3->next = new ListNode(list1->val);
                list3 = list3->next;
                list1 = list1->next;
            }
            else
            {
                list3->next = new ListNode(list2->val);
                list3 = list3->next;
                list2 = list2->next;
            }
        }
        if (list1)
        {
            while (list1)
            {
                list3->next = new ListNode(list1->val);
                list3 = list3->next;
                list1 = list1->next;
            }
        }
        else
        {
            while (list2)
            {
                list3->next = new ListNode(list2->val);
                list3 = list3->next;
                list2 = list2->next;
            }
        }
        list3 = head;
        return list3;
    }
};