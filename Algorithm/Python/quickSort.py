# -*- coding: utf-8 -*-

def quick_sort(nums):
    if len(nums) <= 1:
        return nums
    else:
        pivot = nums[0]
        left_nums = []
        right_nums = []
        for num in nums[1:]:
            if num < pivot:
                left_nums.append(num)
            else:
                right_nums.append(num)
        sorted_left = quick_sort(left_nums)
        sorted_right = quick_sort(right_nums)
        return sorted_left + [pivot] + sorted_right

#ÊäÈëÊý×é
arr = list(map(int, input().split()))
print(quick_sort(arr))

