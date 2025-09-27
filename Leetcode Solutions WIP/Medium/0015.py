"""
Problem: 15. 3Sum
Link: https://leetcode.com/problems/3sum/
Difficulty: Medium
"""
class Solution(object):
    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        nums.sort()
        n = len(nums)
        res = []
        for i, num in enumerate(nums):
            if i > n - 3:
                break

            l, r = i+1, n-1
            while l < r:
                s = num + nums[l] + nums[r]
                if s == 0:
                    new_sol = [num, nums[l], nums[r]]                    
                    if new_sol not in res: 
                        res.append(new_sol)
                    r -= 1
                    l += 1
                elif s > 0:
                    r -= 1
                else:
                    l += 1

        return res

