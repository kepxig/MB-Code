#coding=gbk
class Student():
    def __init__(self,wenli):
        self.wenli=wenli

    def xuexi(self):
        pass
    def kaoshi(self):
        print('�߿�.')
class Likesheng(Student):
    def xuexi(self):
        print('%s:ˢ��Ϊ��������Ϊ��'%(self.wenli))
        return super().xuexi()
class Wenkesheng(Student):
    def xuexi(self):
        print('%s:����Ϊ����ˢ��Ϊ��'%self.wenli)
        return super().xuexi()

xiaoming=Likesheng('���')
xiaohong=Wenkesheng('�Ŀ�')
xiaoming.xuexi()
xiaoming.kaoshi()
xiaohong.xuexi()
xiaohong.kaoshi()

