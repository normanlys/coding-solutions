#include <iostream>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        ListNode *previous = nullptr;

        while (head)
        {
            ListNode *next = head->next;
            head->next = previous;
            previous = head;
            head = next;
        }

        return previous;
    }

    ListNode *reverseListRecursively(ListNode *head)
    {
        if (!head || !head->next)
            return head;
        
        ListNode* reversedNext = reverseListRecursively(head->next);
        
        head->next->next = head;
        head->next = nullptr;
        return reversedNext;
    }
};
