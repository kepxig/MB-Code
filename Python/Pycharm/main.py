"""class Car:
    wheels = 3

    @classmethod
    def drive(cls):
        print(cls.wheels)
        cls.wheels = 4
        # 输出原来的属性 后修改


c1 = Car()
c1.drive()
print(c1.wheels)"""
# 静态方法 可以通过类和对象调用
class Car:
    @staticmethod
    def drive():
        print("static mothod")
c1=Car()
c1.drive()#通过实例调用
Car.drive()#通过类调用