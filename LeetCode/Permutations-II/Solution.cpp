class Solution:
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        
        results = []
        def bt(start):
            if start == len(nums):
                results.append(nums[:])
                return
            
            
            lookup = set()
            
            for i in range(start,len(nums)):
                if nums[i] not in lookup:
                    nums[start], nums[i]=  nums[i],nums[start]
                    bt(start+1)
                    nums[start], nums[i]=  nums[i],nums[start]
                    lookup.add(nums[i])
        
        bt(0)
        return results