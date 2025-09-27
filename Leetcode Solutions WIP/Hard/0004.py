"""
Problem: 4. Median of Two Sorted Arrays
Link: https://leetcode.com/problems/median-of-two-sorted-arrays/
Difficulty: Hard
"""
class Solution(object):
    def findMedianSortedArrays(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """

        n = len(nums1)
        m = len(nums2)
        i = 0
        j = 0

        m01 = -1
        m02 = -1

        for count in range((m + n) // 2 + 1):
            m02 = m01

            if i != n and j != m:
                if nums1[i] > nums2[j]:
                    m01 = nums2[j]
                    j += 1
                else:
                    m01 = nums1[i]
                    i += 1

            elif i < n:
                m01 = nums1[i]
                i += 1

            else:
                m01 = nums2[j]
                j += 1

        if (m + n) % 2 == 1:
            return m01
        else:
            return (m01 + m02) / 2.0
        