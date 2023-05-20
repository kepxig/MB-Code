#include<iostream>
using  namespace  std;

//请在这里编写  Clock  类及相关函数
class Clock {
	public:
		void setTime(int newH=0,int newM=0,int newS=0);
		void showTime();
	private:
		int hour,minute,second;
};
 
void Clock::setTime(int newH,int newM,int newS) {
	hour=newH;
	minute=newM;
	second=newS;
}
void Clock::showTime() {
	cout<<hour<<":"<<minute<<":"<<second<<endl;
}



//请不要修改  main  函数
int  main()  {
          Clock  myClock;
          myClock.setTime(8,  30,  30);
          myClock.showTime();
          return  0;
}