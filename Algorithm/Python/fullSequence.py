#!/usr/bin/env python
# encoding:gbk
import numpy as np

def perm(lst,stack):
    if not lst:
        ##print(stack)  # ���������������
        print('{} {} {}'.format(*stack))
    else:  # û�е�����Ҷ�ӽڵ��ʱ��ʹ�õݹ���������ҡ�
        for i in range(len(lst)):#i:0~n
            stack.append(lst[i])
            del lst[i]
            perm(lst,stack)
            lst.insert(i,stack.pop())

n=int(input())
lst=list(range(1,n+1))
stack=[]
perm(lst,stack)