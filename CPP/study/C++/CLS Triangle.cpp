#include <string>
#include <iostream>
using namespace std;

//请在这里定义类及相关函数
class ExamInfo
{
    private:
    string name;
    enum mode{GRADE,PASS,PERCENTAGE};
    union
    {
        char grade;
        bool pass;
        int percent;
    };
    public:
    ExamInfo(string name,char grade):name(name),grade(grade){}
     ExamInfo(string name,bool grade):name(name),bool(grade){}
     ExamInfo(string name,int grade):name(name),percent(grade){}
   void show()
    {
        cout<<string<<":"<<union<<endl;
    }
};
//请不要修改 main 函数
int main() {
	ExamInfo course1("English", 'B');
	ExamInfo course2("Calculus", true);
	ExamInfo course3("Programming", 85);
	course1.show();
	course2.show();
	course3.show();
	return 0;
}