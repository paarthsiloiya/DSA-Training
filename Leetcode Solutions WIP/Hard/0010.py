"""
Problem: 10. Regular Expression Matching
Link: https://leetcode.com/problems/regular-expression-matching/
Difficulty: Hard
"""
class Solution(object):
    def isMatch(self, s, p):
        """
        :type s: str
        :type p: str
        :rtype: bool
        """
        text_len, pattern_len = len(s), len(p)
        dp_table = [[False] * (pattern_len + 1) for _ in range(text_len + 1)]
        dp_table[0][0] = True
        for i in range(text_len + 1):
            for j in range(1, pattern_len + 1):
                if p[j - 1] == "*":
                    dp_table[i][j] = dp_table[i][j - 2]
                    if i > 0 and (p[j - 2] == "." or s[i - 1] == p[j - 2]):
                        dp_table[i][j] |= dp_table[i - 1][j]
                elif i > 0 and (p[j - 1] == "." or s[i - 1] == p[j - 1]):
                    dp_table[i][j] = dp_table[i - 1][j - 1]

        return dp_table[text_len][pattern_len]
        