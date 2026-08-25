class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        if len(nums) == 0 : return 0
        n = len(nums)

        st = set(nums)
        start = []

        for x in nums:
            if x-1 not in st : start.append(x)

        ans = 1
        for x in start:
            clen = 1

            while x+clen in st: clen+=1

            ans = max(ans, clen)

        return ans
        