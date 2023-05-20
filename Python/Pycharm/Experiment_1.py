# 1.py.编写程序，要求程序能根据用户输入的数据计算圆的面积（圆的面积公式：），
# 并分别输出圆的直径和面积。
"""
radius = float(input("Please input radius: "))
circumference = float(2 * 3.14 * radius)
area = float(3.14 * radius ** 2)
print("circumference: %f\narea: %f" % (circumference, area))
"""
# 2.已知某煤场有29.5顿煤，先用一辆载重4顿的汽车运3次，
# 剩下的用一辆载重为2.5顿的汽车运送，请计算还需要运送几次才能送完？编写程序，解答此问题。
"""
t = (29.5 - 4 * 3) / 2.5
print("need %d more times to complete" % t)
"""
# 3.编写程序，实现利用while循环输出100以内偶数的功能。
"""
i = 2
while i <101:
    print(i, end=" ")
    i += 2
"""
# 4.编写程序，实现输出100以内质数的功能。
"""
list = []
flag = True
for i in range(2, 101):
    for j in range(2, i):
        if i % j == 0:
            flag = False
            break
        else:
            flag = True
    if flag == True:
        list.append(i)
print(list)
"""
# 5.编写程序，已知字符串s = 'AbcDeFGhIJ'，请计算该字符串中小写字母的数量。
"""
s = "AbcDeFGhIJ"
total = 0
for i in s:
    if i.islower():
        total += 1.py
print(total)
"""
# 6.编写程序，检查字符串" Life is short. I use python"中是否包含字符串"python"，
# 若包含则替换为"Python"后输出新字符串，否则输出原字符串。
'''
s = 'Life is short. I use python'
if 'python' in s:
    print(s.replace('python', 'Python'))
else:
    print(s)
'''
# 7.五子棋是一种由双人对弈的纯策略型棋类游戏，它使用的棋盘一般由横纵等距的各15条平行线构成，
# 这些线垂直交叉形成的225个交叉点为对弈双方的落子点。要求编写代码，
# 实现按用户要求打印指定大小的五子棋棋盘的程序。
# 第一行
'''
print('┌', end=' ')
for i in range(13):
    print('┬', end=' ')
print('┐')
# 第2到14行
for i in range(13):
    print('├', end=' ')
    for j in range(13):
        print('┼', end=' ')
    print('┤')
# 第15行
print('└',end=' ')
for i in range(13):
    print('┴',end=' ')
print('┘',end=' ')
'''
# 8.绘制多个起点相同单大小不同的五角星
import turtle


def star(x, y, left_angle, edge_len, color='yellow'):
    """
        画一个五角星
        :param x: 起始x坐标
        :param y: 起始y坐标
        :param left_angle: 画笔方向逆时针转动度数
        :param edge_len: 五角星边的长度
        :param color: 五角星颜色
        :return:
    """


# 五角星边的颜色
turtle.pencolor(color)
# 五角星填充色
turtle.fillcolor(color)
# 绘制速度，0代表最快，数字越大越快
turtle.pu()  # 抬起画笔
turtle.goto(x, y)  # 移动到初始位置
turtle.pd()  # 放下画笔
turtle.begin_fill()  # 开始填充
# 画笔以水平方向为基准
# 逆时针旋转left_angle度
turtle.left(left_angle)
# 循环绘制五角星的五条边
for i in range(5):
    # 向画笔方向移动edge_len像素长度
    # 即：绘制五角星的一条边
    turtle.forward(edge_len)
    # 画笔方向顺时针旋转144度
    # 由于五角星内角是36度，因此旋转180-36=144度
    turtle.right(144)
turtle.end_fill()
# 填充完成
# 将画笔方向恢复为水平方向，以免影响后续画图
turtle.left(-left_angle)

turtle.screensize(800, 600, "white")
star(20, 100, 50, 100, color='red')
star(150, 150, 100, 150, color='blue')
star(-200, -200, 150, 100, color='blue')
turtle.done()
