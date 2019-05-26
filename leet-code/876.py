# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None


class Solution:
    def middleNode(self, head: ListNode) -> ListNode:
        length = 1
        current_node = head
        while current_node.next:
            current_node = current_node.next
            length += 1
        length = int(length/2)

        current_node = head
        for i in range(length):
            current_node = current_node.next
        return current_node
