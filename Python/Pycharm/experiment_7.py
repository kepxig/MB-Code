#第九章 异常

#1.练习异常的捕获。

# 1)使用try-except语句捕获异常
# 异常捕获语句 try-expect
"""
try:
    可能出错的代码
expect 异常类型 as error:   #as error 将捕获到的异常对象赋error,可以捕获异常描述信息
    捕获异常后的处理代码
    print (error) #捕获异常描述信息
"""

#2)输入下面的代码,练习捕获单个异常
"""
num_one = int(input("请输入被除数:"))
num_two = int(input("请输入除数:"))
try:
    print("结果为", num_one / num_two)
except ZeroDivisionError:
    print("出错了")
"""

#3)输入下面的代码,练习捕获多个异常
"""
num_one = int(input("请输入被除数:"))
num_two = int(input("请输入除数:"))    
try:
    print("结果为", num_one / num_two)
except (ZeroDivisionError,ValueError) as error:
    print("出错了,原因:",error)
"""

#4)输入下面的代码,练习捕获全部异常
"""
num_one = int(input("请输入被除数:"))
num_two = int(input("请输入除数:"))
try:
    print("结果为", num_one / num_two)
except Exception as error:
    print("出错了,原因:", error)
"""
#5)输入下面的代码练习异常结构中的else子句
'''
else子句可以与try-except语句组合成try-except-else结构,
若try监控的代码没有异常,程序会执行else子句后的代码。
'''
"""
first_num = int(input("请输入被除数:"))
second_num = int(input("请输入除数:"))
try:
    res = first_num/second_num
except ZeroDivisionError as error:
    print('异常原因:',error)
else:
    print(res)
"""

#6)finally子句可以和try-except一起使用,无论try子句监控的代码是否产生异常,
# finally子句都会被执行。finally子句多用于预设资源的清理操作,
# 如关闭文件、关闭网络连接,输入下面的代码练习finally子句的使用
"""
try:
    file = open('text.txt', mode='r', encoding='utf-8')
    print(file.read())
except (FileNotFoundError,NameError) as error:
    file = open('text.txt', mode='w', encoding='utf-8')
finally:
    file.close()
    print('文件已关闭')
"""

#2.练习raise语句和assert语句的使用

#1)使用raise语句可以显式地抛出异常, raise语句的语法格式如下
"""
raise 异常类				# 格式1:使用异常类名引发指定的异常
raise 异常类对象				# 格式2:使用异常类的对象引发指定的异常
raise 					# 格式3: 使用刚出现过的异常重新引发异常
"""

#练习下面异常抛出的语句
#1.1)
#raise IndexError()

#1.2)
#raise IndexError('索引下标超出范围')

#1.3)
"""
try:
    raise IndexError
except:
    raise
"""
#2)使用assert语句抛出异常
"""
assert 表达式, 异常信息
(表达式为false会出发asserterror异常,表达式为true什么都不做)
"""

#练习下面的assert语句的使用
"""
num_one = int(input("请输入被除数:"))
num_two = int(input("请输入除数:"))
assert num_two != 0, '除数不能为0'  # assert语句判定num_two不等于0
result = num_one / num_two
print(num_one, '/', num_two, '=', result)
"""

#3.自定义异常编程练习
#有时需要自定义异常类,以满足当前程序的需求。就是将不满足程序逻辑的情况反馈给用户,
# 用来报错。自定义异常的方法比较简单,只需要创建一个继承Exception类或Exception子类
# 的类(类名一般以“Error”为结尾)即可。
#需求:
# 密码长度不足,则报异常(用户输入密码,如果输入不足3位,则报错,即抛出自定义异常,
# 并捕获该异常。)
# 步骤如下:
#1)自定义异常类
#2)抛出异常
#3)捕获该异常
#输入下面代码,练习自定义异常使用
"""
class ShortInputError(Exception):
    def __init__(self, length,atleast):
        self.length=length #输入的密码长度
        self.atleast=atleast #设置最小密码长度
try:
    passwd=input("请输入密码:")
    if len(passwd)<3:
        raise ShortInputError(len(passwd),3)
except ShortInputError as result:
    print("ShortInputError:输入的长度是%d,长度至少应是 %d"
    %(result.length,result.atleast))
else:
    print("密码设置成功!")
"""

#4.用自定义异常解决问题	(请自己动手编写代码解决下面的问题。)
#1)编写程序,计算圆的面积,若半径为负值则抛出异常(圆的面积公式:)。
"""
pi=3.14159
radius=float(input("请输入半径:"))
assert radius>=0,"RadiusNegativeError:半径不能为负值！"
print("圆的面积为:%.2f"%(2*pi**radius))
"""
#2)编写程序,输入三角形三条边判断能否构成三角形,
# 若能构成则计算三角形的面积和周长,否则引发异常。
"""
import math as m
a,b,c=map(float,input("请输入三角形的三条边(以空格隔开):").split())
assert a+b>=c and a+c>=b and b+c>=a ,"TriangleError:不能构成一个正确的三角形！"
premeter=(a+b+c)
p=premeter/2
area=m.sqrt(p*(p-a)*(p-b)*(p-c))
print("三角形的周长为：%.2f\n面积为:%.2f"%(premeter,area))
"""