"""
Problem: 2. Add Two Numbers
Link: https://leetcode.com/problems/add-two-numbers/
Difficulty: Medium
"""
# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: Optional[ListNode]
        :type l2: Optional[ListNode]
        :rtype: Optional[ListNode]
        """
        currNode = ListNode()
        temp = currNode

        carry = 0
        while l1 != None or l2 != None or carry > 0:
            sum = carry

            if l1 != None:
                sum += l1.val
                l1 = l1.next

            if l2 != None:
                sum += l2.val
                l2 = l2.next

            carry = sum // 10

            NN = ListNode(sum % 10, None)
            currNode.next = NN
            currNode = currNode.next

        return temp.next