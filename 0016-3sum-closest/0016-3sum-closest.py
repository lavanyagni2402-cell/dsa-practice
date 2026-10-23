class Solution:
    def threeSumClosest(self, nums: list[int], target: int) -> int:
        nums.sort()
        closest = nums[0] + nums[1] + nums[2]

        for i in range(len(nums) - 2):
            left = i + 1
            right = len(nums) - 1

            while left < right:
                s = nums[i] + nums[left] + nums[right]

                if abs(target - s) < abs(target - closest):
                    closest = s

                if s == target:
                    return s
                elif s < target:
                    left += 1
                else:
                    right -= 1

        return closest