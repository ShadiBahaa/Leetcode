def subsets(self, nums: List[int]) -> List[List[int]]:
    def backTrack(start, cur_list):
        ans.append(cur_list[:])
        
        for j in range(start, n):
            cur_list.append(nums[j])
            backTrack(j+1, cur_list)
            cur_list.pop()
    
    n = len(nums)
    ans = []

    backTrack(0, [])
    
    return ans