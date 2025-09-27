"""
Problem: 14. Longest Common Prefix
Link: https://leetcode.com/problems/longest-common-prefix/
Difficulty: Easy
"""
class Solution(object):
    def longestCommonPrefix(self, strs):
        """
        :type strs: List[str]
        :rtype: str
        """
        if not strs:
            return ""
        
        strs.sort()
        
        first, last = strs[0], strs[-1]
        i = 0
        
        while i < len(first) and i < len(last) and first[i] == last[i]:
            i += 1
        
        return first[:i]
            