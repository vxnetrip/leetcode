from typing import List

class Solution:
    def minimumOperations(self, nums: List[int]) -> int:
        li = set()
        for num in nums:
            if num != 0:
                li.add(num)

        return len(li)
    


nums = [1,5,0,3,5]
print(Solution().minimumOperations(nums))
