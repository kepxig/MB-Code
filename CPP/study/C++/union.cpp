#include <string>
#include <iostream>
using namespace std;

//请在这里定义类及相关函数
class ExamInfo
{
private:
    string name;
    enum {GRADE, PASS, PERCENTAGE
}mode;
    union 
    {
        char grade;
        bool pass;
        int percent;
    };
public:
    ExamInfo(string name, char grade) :name(name), grade(grade),mode(GRADE) {}
    ExamInfo(string name, bool grade) :name(name), pass(grade),mode(PASS) {}
    ExamInfo(string name, int grade) :name(name), percent(grade), mode(PERCENTAGE) {}
    void show()
    {
        cout << name << ":";
        switch (mode)
        {
        case GRADE:
            cout << grade;
            break;
        case PASS:
            if (PASS)
                cout << "pass";
            else
                cout << "falt";
            break;
        case PERCENTAGE:
            cout << percent;
            break;
        }  cout << endl;
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