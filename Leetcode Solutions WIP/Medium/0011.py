"""
Problem: 11. Container With Most Water
Link: https://leetcode.com/problems/container-with-most-water/
Difficulty: Medium
"""
class Solution(object):
    def maxArea(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        l = 0
        r = len(height) - 1
        res = 0 
        
        while l < r:
            width = r - l
            h = min(height[l], height[r])
            water = width * h
            res = max(res, water)
            if height[l] < height[r]:
                l += 1
            else:
                r -= 1
        
        return res
