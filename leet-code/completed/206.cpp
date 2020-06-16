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
            // use tmp var to store the next list
            ListNode *next = head->next;
            // only preserve the first node and attach the previously reversed list
            // to its next
            head->next = previous;
            // store the reversed list in previous
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
        // utilises pointers
        // head->next is the tail of reversedNext because of pointers
        head->next->next = head;
        head->next = nullptr;
        return reversedNext;
    }
};
