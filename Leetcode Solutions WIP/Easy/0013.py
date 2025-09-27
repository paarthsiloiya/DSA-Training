"""
Problem: 13. Roman to Integer
Link: https://leetcode.com/problems/roman-to-integer/
Difficulty: Easy
"""
class Solution(object):
    def romanToInt(self, s):
        """
        :type s: str
        :rtype: int
        """
        mapping = {"I":1, "V":5, "X":10, "L":50, "C":100, "D":500, "M":1000}
        res = 0
        i = 0

        while i < len(s):
            s1 = mapping[s[i]]

            if i + 1 < len(s):
                s2 = mapping[s[i+1]]

                if s1 >= s2:
                    res += s1
                else:
                    res += s2 - s1
                    i += 1
            else:
                res += s1
            
            i += 1
        
        return res
