nums = [23,2,4,6,2,5,1,6,13,54,8]

def quicksort(nums, left, right):   # left为最左索引，righ为最右索引
    if left >= right:
        return
    pivot = left //取第一个元素为pivot
    i, j = left, right
    while i < j:
        while nums[pivot] <= nums[j] and i < j:
            j -= 1
        while nums[pivot] >= nums[i] and i < j:
            i += 1
        if i < j:
            nums[i], nums[j] = nums[j], nums[i]
    nums[pivot], nums[i] = nums[i], nums[pivot]
    quicksort(nums, left, i-1)
    quicksort(nums, i+1, right)

def quicksort2(nums, left, right):          # 用栈代替递归
    if left >= right:
        return
    stack = []
    while stack or left < right:
        if left < right:
            pivot = left
            i, j = left, right
            while i < j:
                while nums[pivot] <= nums[j] and i < j:
                    j -= 1
                while nums[pivot] >= nums[i] and i < j:
                    i += 1
                if i < j:
                    nums[i], nums[j] = nums[j], nums[i]
            nums[pivot], nums[i] = nums[i], nums[pivot]
            stack.append((left, i, right))
            right = i - 1
        else:
            left, mid, right = stack.pop()
            left = mid + 1

quicksort2(nums, 0, len(nums)-1)
print(nums) 