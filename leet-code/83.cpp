#include <iostream>
#include <unordered_set>

struct ListNode
{
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next)
            return head;

        ListNode* current = head;
        while (current && current->next)
        {
            if (current->val != current->next->val)
                current = current->next;
            else
                current->next = current->next->next;
            
        }
        return head;
    }

    ListNode* deleteDuplicatesRecursively(ListNode* head) {
        if (!head || !head->next)
            return head;

        head->next = deleteDuplicatesRecursively(head->next);
        if (head->val == head->next->val)
            head->next = head->next->next;
            return head;

        return head;
    }
};