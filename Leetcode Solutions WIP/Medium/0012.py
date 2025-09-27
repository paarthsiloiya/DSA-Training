"""
Problem: 12. Integer to Roman
Link: https://leetcode.com/problems/integer-to-roman/
Difficulty: Medium
"""
class Solution(object):
    def intToRoman(self, num):
        """
        :type num: int
        :rtype: str
        """
        from math import floor
        LUT = {
            1: "I",
            5: "V",
            10: "X",
            50: "L",
            100: "C",
            500: "D",
            1000: "M"
        }
        div = 1
        while num >= div:
            div *= 10
    
        div /= 10
    
        res = ""
    
        while num:
            lastNum = int(num / div)
    
            if lastNum <= 3:
                res += (LUT[div] * lastNum)
            elif lastNum == 4:
                res += (LUT[div] +
                            LUT[div * 5])
            elif 5 <= lastNum <= 8:
                res += (LUT[div * 5] +
                (LUT[div] * (lastNum - 5)))
            elif lastNum == 9:
                res += (LUT[div] +
                            LUT[div * 10])
    
            num = floor(num % div)
            div /= 10
            
        return res