class Solution:
    def minMoves(self, nums: List[int]) -> int:
        min_num = min(nums)
        max_num = max(nums)

        return sum(max_num - num for num in nums)