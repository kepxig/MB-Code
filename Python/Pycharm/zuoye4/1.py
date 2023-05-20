#coding=gbk
class Student():
    def __init__(self,wenli):
        self.wenli=wenli

    def xuexi(self):
        pass
    def kaoshi(self):
        print('高考.')
class Likesheng(Student):
    def xuexi(self):
        print('%s:刷题为主，背诵为辅'%(self.wenli))
        return super().xuexi()
class Wenkesheng(Student):
    def xuexi(self):
        print('%s:背诵为主，刷题为辅'%self.wenli)
        return super().xuexi()

xiaoming=Likesheng('理科')
xiaohong=Wenkesheng('文科')
xiaoming.xuexi()
xiaoming.kaoshi()
xiaohong.xuexi()
xiaohong.kaoshi()

