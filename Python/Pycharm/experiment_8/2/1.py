import turtle
import matplotlib

'''全局变量'''
#amount = 10  # 词频排列显示个数
amount = int(input("请输入统计高频次的数量:"))
words = []  # 单词集合-x轴数据
wCounts = []  # 单词频数集合-y轴数据
xPoint = -360
yPoint = -200
'''turtle start'''


# 绘制从点(x1,y1)到(x2,y2)的线段
def drawLine(t, x1, y1, x2, y2):
    t.penup()
    t.goto(x1, y1)
    t.pendown()
    t.goto(x2, y2)


# 在坐标(x,y)处写文字
def drawText(t, x, y, text, fontSize=10):
    t.penup()
    t.goto(x, y)
    t.pendown()
    t.write(text, font=('微软雅黑', fontSize,), align='center')


# 绘制矩形
def drawRectangle(t, x, y, rWidth):
    drawLine(t, x - rWidth, yPoint, x - rWidth, y)
    drawLine(t, x - rWidth, y, x + rWidth, y)
    drawLine(t, x + rWidth, y, x + rWidth, yPoint)
    drawLine(t, x + rWidth, yPoint, x - rWidth, yPoint)


# 绘制柱状图
def drawBarchart(t):
    drawText(t, 0, -yPoint - 40, "词频统计结果", 15)  # 绘制标题
    drawRectangle(t, 0, -yPoint, -xPoint)  # 绘制边框
    rWidth = -xPoint / (2 * amount)  # 控制条形柱宽度（2rWidth）
    xScale = -xPoint * 2 / (amount + 1)  # x轴显示放大倍数-可根据amount进行调节
    yScale = -yPoint / wCounts[0]  # y轴显示放大倍数-可根据频数进行调节
    for i in range(amount):
        i = i + 1  # 右移以避免与原点重合
        x = i * xScale + xPoint
        y = wCounts[i - 1] * yScale + yPoint
        drawText(t, x, yPoint - 20, words[i - 1])  # 打印单词
        drawText(t, x, y + 10, wCounts[i - 1])  # 打印频率
        t.begin_fill()
        drawRectangle(t, x, y, rWidth)
        t.end_fill()


# 初始化窗口
def init():
    turtle.title('词频结果柱状图')
    turtle.screensize(900, 750, "#272727")
    t = turtle.Turtle()
    t.hideturtle()  # 隐藏箭头
    t.width(1)  # 线条粗细
    t.color("#EBEBD0", "#006030")
    # t.color("#006030","#FFF68C")
    drawBarchart(t)  # 绘制
    turtle.exitonclick()

'''data Processing'''


# 对文本的每一行计算词频的函数
def processLine(line, wordamounts):
    line = replacePunctuations(line)  # 用空格替换标点符号
    words = line.split()  # 从每一行获取每个词
    for word in words:
        if word in wordamounts:
            wordamounts[word] += 1
        else:
            wordamounts[word] = 1


# 空格替换标点
def replacePunctuations(line):
    for ch in line:
        if ch in "~!@#$%^&*()-_+=<>?/,.:;{}[]|\'\"":
            line = line.replace(ch, ' ')
    return line


# 数据处理，得到文件中出现频率最高的单词及其频数
def dataProcess(filename):
    infile = open(filename, 'r', encoding='UTF-8')
    wordamounts = {}  # 建立用于记录词频的空字典
    for line in infile:
        processLine(line.lower(), wordamounts)
    pairs = list(wordamounts.items())  # 从字典中获取数据对
    items = [[x, y] for (y, x) in pairs]  # 列表中的数据对交换位置，使频数成为元素的键值
    items.sort()  # 列表排序。默认根据键值排序
    # 输出amount个词频结果
    for i in range(len(items) - 1, len(items) - amount - 1, -1):
        print(items[i][1] + "\t" + str(items[i][0]))
        wCounts.append(items[i][0])
        words.append(items[i][1])
    infile.close()


def main():
    # 用户输入一个文件名
    filename = input("enter a filename:").strip()
    dataProcess(filename)
    init()

# 调用main()函数
if __name__ == '__main__':
    main()
