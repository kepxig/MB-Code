#include <stdio.h>
struct student
{
    int age;
    char num[3];
    char name[17];
    char sex[2];
    float score1;
    float score2;
    float score3;
    /* data */
};
int main()
{
    struct student stu[3] = {
        {18, "01", "zhangsan", "M", 98.01, 95.04, 92.07},
        {18, "02", "zhaosi", "M", 97.02, 94.05, 91.08},
        {18, "03", "xiaoyin", "F", 96.03, 93.06, 90.09}
    };

    for (int i = 0; i < 3; i++)
    {
        float average = (stu[i].score1 + stu[i].score2 + stu[i].score3) / 3.0;
        printf("\n学号：%s\n年龄：%d\n姓名：%s\n性别：%s\n平均成绩：%.2f\n", stu[i].num, stu[i].age, stu[i].name, stu[i].sex, average);
    }
}
