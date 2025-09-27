"""
Problem: 7. Reverse Integer
Link: https://leetcode.com/problems/reverse-integer/
Difficulty: Medium
"""
class Solution(object):
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        l = list(str(abs(x)))
        res = 0
        for i in range(len(l)):
            res += (int(l[i]) * (10**i))

        if (res > ((2**31) -1)) or (res < -2**31):
            return 0
        
        return res if x > 0 else -1*res