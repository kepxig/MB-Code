# 1.n! = 1 * 2 * 3 * … * n，请输入一个正整数，算出次数的阶乘，并打印出来。
# 提示：可以分为以下两种情况：1）当n=1时，所得的结果为1。2）当n>1时，所得的结果为n*(n-1)!
"""
import math
n = int(input("请输入一个整数："))
print(math.factorial(n))
"""
# 2.兔子一般在出生两个月之后就有了繁殖能力，每对兔子每月可以繁殖一对小兔子，假如所有的兔子都不会死。
# 要求编写代码，利用递归实现根据键盘输入的月份计算兔子总数量。
# 提示：如图分析兔子繁殖过程，实际按照斐波那契数列计算。
"""
def fibonacci(n):
    return n if n<2 else fibonacci(n-1)+fibonacci(n-2)
n=int(input("Please input an integer:"))
print(fibonacci(n))
"""


# 3.先将待排序的序列划分成若干长度为1的子序列，依次将两个子序列排序后合并成长度为2的子序列；（归并排序）
# 再依次将两个子序列排序后合并成长度为4的子序列，直至合并成最初长度的序列为止，
# 得到一个排序后的序列。利用递归实现归并排序算法。
def merge_sort(lst):
    if len(lst) == 1:
        return lst
    mid = len(lst) // 2  # // 取整除 - 返回商的整数部分（向下取整）
    left_lst = merge_sort(lst[:mid])
    right_lst = merge_sort(lst[mid:])
    return merge(left_lst, right_lst)


def merge(left_lst, right_lst):
    left_index, right_index, merge_lst = 0, 0, []
    while left_index < len(left_lst) and right_index < len(right_lst):
        if left_lst[left_index] <= right_lst[right_index]:
            merge_lst.append(left_lst[left_index])
            left_index += 1
        else:
            merge_lst.append(right_lst[right_index])
            right_index += 1

    merge_lst = merge_lst + left_lst[left_index:] + right_lst[right_index:]  # 剩下的
    return merge_lst


if __name__ == '__main__':
    a = [1, 3, 5, 2, 6, 7, 8, 4]
    print(merge_sort(a))
