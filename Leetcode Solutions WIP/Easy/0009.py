"""
Problem: 9. Palindrome Number
Link: https://leetcode.com/problems/palindrome-number/
Difficulty: Easy
"""
class Solution(object):
    def isPalindrome(self, x):
        """
        :type x: int
        :rtype: bool
        """
        
        return True if str(x) == str(x)[::-1] else False