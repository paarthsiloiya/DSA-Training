"""
Problem: 6. Zigzag Conversion
Link: https://leetcode.com/problems/zigzag-conversion/
Difficulty: Medium
"""
class Solution(object):
    def generate_list(self, n, m):
        l = []
        for i in range(1, n + 1):
            l.append(i-1)
            
        for i in range(n - 1, 1, -1):
            l.append(i-1)
            
        while len(l) < m:
            l += l[:m - len(l)]
            
        return l[:m]

    def convert(self, s, numRows):
        """
        :type s: str
        :type numRows: int
        :rtype: str
        """
        # I know how to do it the correct way but this is more fun
        
        finalList = [[[] for _ in range(len(s))] for _ in range(numRows)]
        res = ""

        for i in range(len(s)):
            j = self.generate_list(numRows, len(s))
            finalList[j[i]][i].append(s[i])

        for i in finalList:
            for j in i:
                if j:
                    res += j[0]


        return (res)

        