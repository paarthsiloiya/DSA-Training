"""
Problem: 5. Longest Palindromic Substring
Link: https://leetcode.com/problems/longest-palindromic-substring/
Difficulty: Medium
"""
class Solution(object):
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        res = ""
        length = 0

        for i in range(len(s)):
            lef, rig = i, i
            while lef >= 0 and rig < len(s) and s[lef] == s[rig]:
                if length <= rig - lef + 1:
                    res = s[lef:rig+1]
                    length = rig - lef + 1
                lef -= 1
                rig += 1

            lef, rig = i, i + 1
            while lef >= 0 and rig < len(s) and s[lef] == s[rig]:
                if length <= rig - lef + 1:
                    res = s[lef:rig+1]
                    length = rig - lef + 1
                lef -= 1
                rig += 1
        
        return res
