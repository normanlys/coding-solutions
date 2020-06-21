struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1)
            return l2;
        if (!l2)
            return l1;

        ListNode* result;
        ListNode* smaller;
        ListNode* larger;
        if (l1->val < l2->val)
        {
            smaller = l1;
            larger = l1->next;
            l1->next = l2;
        }
        else
        {
            smaller = l2;
            larger = l2->next;
            l2->next = l1;
        }
        result = smaller;

        while (larger && smaller->next)
        {
            if (larger->val < smaller->next->val)
            {
                ListNode* tmp = larger;
                larger = smaller->next;
                smaller->next = tmp;
            }
            smaller = smaller->next;
        }

        if (larger)
            smaller->next = larger;

        return result;
    }
};
