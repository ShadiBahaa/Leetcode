def search(self, nums: List[int], target: int) -> int:
    lo, hi = 0, len(nums) - 1
    while lo < hi:
        mid = (lo + hi) // 2
        if nums[mid] >= target:
            hi = mid
        else:
            lo = mid + 1

    if nums[lo] == target:
        return lo
    else:
        return -1