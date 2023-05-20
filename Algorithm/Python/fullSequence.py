#!/usr/bin/env python
# encoding:gbk
import numpy as np

def perm(lst,stack):
    if not lst:
        ##print(stack)  # 到树的最后，输出结果
        print('{} {} {}'.format(*stack))
    else:  # 没有到树的叶子节点的时候，使用递归继续往下找。
        for i in range(len(lst)):#i:0~n
            stack.append(lst[i])
            del lst[i]
            perm(lst,stack)
            lst.insert(i,stack.pop())

n=int(input())
lst=list(range(1,n+1))
stack=[]
perm(lst,stack)