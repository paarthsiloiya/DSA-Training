"""
Problem: 8. String to Integer (atoi)
Link: https://leetcode.com/problems/string-to-integer-atoi/
Difficulty: Medium
"""
class Solution(object):
    def myAtoi(self, s):
        """
        :type s: str
        :rtype: int
        """
        isNeg = 1
        res = 0
        l = []

        s = s.strip()

        for i in range(len(s)):
            if len(l)==0:
                if s[i] == '-':
                    isNeg = -1
                    l.append(0)
                    continue
                elif s[i] == "+":
                    isNeg = 1
                    l.append(0)
                    continue

            try:
                l.append(int(s[i]))
            except:
                break

        print(l)
        
        for j in range(len(l)):
            res += l[j] * (10**(len(l) - j - 1))

        res = int(res) if isNeg==1 else int(-1*res)

        if res > int(2**31 - 1):
            return int(2**31 - 1)
        elif res < int(-2**31):
            return int(-2**31)
        
        return res