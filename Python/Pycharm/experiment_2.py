# 1.py.列表、元组与集合

# 1.py.1列表 []
"""
# ————创建————
list1 = ['python', 2018, 'python3', 1994]
list2 = [1.py, 2, 3, 4]
list3 = ['a', 'b', 'c', 'd']
# ————获取列表元素个数————
print(len(list1))
# ————访问————
# (1.py)索引
print(list1[0])
print(list2[1.py])
print(list3[2])
print(list3[-1.py])  # -1.py：倒数第一个
print(list3[-2])  # -1.py：倒数第一个
# （2）切片
print(list1[0: 3])  # list1[:3]:0为起点可省略
print(list1[-3])  # 倒数第三个元素
print(list1[:4:2])  # 前4个元素，每两个取一个
print(list1[:])  # 复制一个列表
# ————合并————
list4 = list2 + list3
print(list4)
# ————更新————
list1 = ['python', '2018', 'python3', '1994']
list1[1.py] = [2018]
print(list1)
# ————删除————
del list1
# ————清空————
list2.clear()
print(list2)
"""

# 1.py.2元组 ()
'''
# ————创建————
tup1 = ('python', 2018, 'python3', 1994)
print(tup1)
tup2 = (1.py, 2, 3, 4)
print(tup2)
tup3 = ('a', 'b', 'c', 'd')
print(tup3)
tup4 = ('hello',)  # 当元组中只有一个元素时，需加逗号以消除歧义
# ————合并————
tup5 = tup2 + tup3
print(tup5)
# ————删除————
del tup5
print(tup5)#此时tup5已不存在 报错

'''
# 1.py.3集合 {}
"""
# ————创建————;
set1 = set()
print(set1)  # 创建空集合
set2 = {'a', 1.py, 'apple', 11.22}
print(set2)
set3 = set([1.py, 2, 3])  # 其实set（tuple）就是把列表转化为set（tuple）
print(set3)
# ————判断元素是否在集合内————
print('apple' in set2)
# ————添加元素————
set2.add('car')
print(set2)  # 如果集合已有该元素则不变（集合元素唯一性）
set2.update({2, 3})
print(set2)  # 另一种添加方式，参数可以是列表、元组、字典等（添加后自动排序）
# ————删除元素————
set2.remove('car')
print(set2)
# ————计算集合元素个数————
print(len(set2))
# ————清空集合————
set2.clear()
print(set2)
"""

"""
————————————————————————————————————————
        列表	    元组	   字典	  集合
名称     list  tuple   dict    set
能否更改 	 能	   不能	    能     能
能否重复	 能     能	    能    不能
能否排序	 能     能     不能    不能
————————————————————————————————————————
"""

# 1.py.已知列表li_num1=[4, 5, 2, 7]和li_num2=[3, 6],请将这两个列表合并为一个列表，并将合并后的列表中的元素按降序排列。
'''
li_num1 = [4, 5, 2, 7]
li_num2 = [3,6]
li_num3 = li_num2 + li_num1
li_num3.sort(reverse=True)
print(li_num3)
'''
# 2.已知元组 tu_num1=('p','y','t',['o','n']），请向元组的最后一个列表中添加新元素＇h'.
'''
tu_num1 = ('p', 'y', 't', ['o', 'n'])
tu_num1 = ('p', 'y', 't', ['o', 'n','h'])
print(tu_num1)
'''
# 3.已知字符串str1='skdaskerkjsalkj',请统计该字符串中各字母出现的次数。
'''
str1 = 'skdaskerkjsalkj'
dict1={}
for i in str1:
    dict1[i] = str1.count(i)
for key in dict1:
    print(f"{key}:{dict1[key]}次")
'''
# 4.已知列表li_one=[1.py, 2, 1.py, 2, 3, 5, 4, 3, 5, 7, 4, 7, 8],请删除列表li_one中的重复数据。
'''
li_one = [1.py, 2, 1.py, 2, 3, 5, 4, 3, 5, 7, 4, 7, 8]
set1=set(li_one)
print(set1)
'''
# 5.为丰富校园文化生活，学校拟组织一场歌手大赛，从参赛选手中选拔出十名相对突出的学生，授予“校园十大歌手”称号。
# 比赛之中设置有评委组，每名选手演唱完毕之后会由评委组的十名评委打分。
# 为保证比赛公平公正，防止作弊和恶意打分，计算得分时会先去掉最高分和最低分，再计算平均分。
# 本实例要求编写程序，实现根据需求计算平均分的功能。
a = input('请输入十位评委的打分')
lst = a.split(',')
newlst = []
for i in lst:
    newlst.append(int(i))
newlst.sort()
print(f'去掉最低分；{newlst[0]}')
del newlst[0]
print(f'去掉最高分{newlst.pop()}')
print(f'该学生成绩总和：{sum(newlst) / len(newlst)}')
