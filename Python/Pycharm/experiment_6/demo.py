# 1.练习python中类的基本操作具体要求如下。
# 1）设计一个Circle（圆）类，该类中包括属性radius（半径），
# 还包括__init__()、get_perimeter()（求周长）和get_area()（求面积）共三个方法。
# 设计完成后，创建Circle类的对象求圆的周长和面积。
"""
class Circle:
    __pi = 3.14

    def __init__(self, r):
        self.radius = r

    def get_perimeter(self):
        return 2 * self.radius * self.__pi

    def get_area(self):
        return self.radius ** 2 * self.__pi


r = int(input("Please input the radius:"))
R1 = Circle(r)

print(f"Perimeter= %.2f"%R1.get_perimeter())
print(f"Area= %.2f"%R1.get_area())
"""

# （2）设计一个Course（课程）类，该类中包括number（编号）、name（名称）、teacher（任课教师）、location（上课地点）共4个属性，
# 其中location是私有属性；还包括__init__()、show_info()（显示课程信息）共两个方法。
# 设计完成后，创建Course类的对象显示课程的信息。

class Course:
    def __init__(self, _number, _name, _teacher, _location):
        self.number = _number
        self.name = _name
        self.teacher = _teacher
        self.__location = _location

    def show_info(self):
        return "Number: %d\nName: %s\nTeacher: %s\nLocation: %s" % (
        self.number, self.name, self.teacher, self.__location)


C1 = Course(13, "Chou", "Lee", "Paris")
print(C1.show_info())

"""
2.实现一个基于面向思想的、具有开户、查询、取款、存款、转账、锁定、解锁和退出功能的银行管理系统。
如图所示的“功能菜单”界面显示了银行管理系统的欢迎界面和功能界面。全部功能，包括开户、查询、取款、存款、转账、锁定、解锁和退出、每个功能的介绍如下。


1）开户功能：用户根据提示依次输入姓名、身份证号、手机号、预存全额、密码等信息。抗入无误后会获取系统随机生成的一个不重复的由6位数字组成的卡号。
2）查询功能：用户根据提示输入正确的卡号、密码后，可以查询卡中余额，若连续3次输入错误的密码，则卡号会被锁定。
3）取款功能：用户根据提示输入正确的卡号、密码后，可以看到系统显示的卡中余额，之后输入取款金额，会看到系统显示取款后的卡中余额。如果用户连续3次输入错误的密码，那么用户的卡号会被锁定；如果用户输入的取款金额大于卡中余额或小于0，那么系统进行提示并返回“功能菜单”界面。
4）存款功能：用户根据提示输入正确的卡号、密码后，可以看到系统显示的卡中余额，之后输入存款金额，会看到系统显示取款后的卡中余额。如果用户输入的存款全额小于0．那么系统进行提示并返回“功能菜单”界面。
5）转账功能：用户根据提示分别输入转出卡号和转入卡号，之后输入转账金额，并再次确认是否执行转账功能，确定执行转账功能后，转出卡与转入卡做相应金额计算；取消转账功能后，回退到之前的操作。如果用户连续3次输入错误的密码，那么用户的卡号会被锁定。
6）锁定功能：用户根据提示输入卡号、密码后，会看到系统显示的锁定成功的信息。钱定的卡号不能进行查询、取款、存款、转账等操作。
7）解锁功能：用户根据提示输入卡号、密码后，会看到系统显示的解锁成功的信息。解锁的卡号可以重新进行查询、取款、存款、转账等操作。
8）退出功能：工作人员根据提示输入管理员的账户和密码，如果输入了错误的账户或密码，会返回到系统的“功能菜单”界面；如果输入正确的账户和密码，那么会退出系统。
"""
