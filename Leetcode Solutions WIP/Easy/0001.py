"""
Problem: 1. Two Sum
Link: https://leetcode.com/problems/two-sum/
Difficulty: Easy
"""
class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        for i in range(len(nums)):
            for j in range(i,len(nums)):
                if nums[i] + nums[j] == target and i != j:
                    return [i,j]