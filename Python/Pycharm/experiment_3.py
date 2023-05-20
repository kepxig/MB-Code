stu_dict = {}
student = []


def menu():
    print('''
    -----学生成绩管理系统-----
    
    1.添加学生成绩
    2.查看所有成绩
    3.删除成绩
    4.修改成绩
    5.查找个人成绩
    0.退出
    
    -----------------------
    ''')


def main():
    ctrl = True  # 标记是否退出系统
    while ctrl:
        menu()
        option = input('请选择：')
        if option == '0':
            print('已退出')
            ctrl = False
        elif option == '1':
            add()
        elif option == '2':
            show()
        elif option == '3':
            delete()
        elif option == '4':
            update()
        elif option == "5":
            query()
        elif option == 0:
            print('已退出系统')
            ctrl = False


def add():
    id = input('请输入学号：')
    name = input('请输入姓名：')
    grade = input('请输入成绩：')
    # 判断输入的是否为空
    if name.strip() == '':
        print('请输入正确信息')

    else:
        stu_dict.update({'学号': id,
                         '姓名': name,
                         '课程':'Python',
                         '成绩': grade, })
        student.append(stu_dict)  # 保存到列表中
        print('保存成功')


def show():
    if len(student) == 0:
        print('无信息')
    for i in student:
        for title, info in i.items():  # items() :以列表返回可遍历的(键, 值) 元组。
            print(title + ':' + info)


def delete():
    if len(student) != 0:
        del_id = input('请输入要删除的学生学号：')
        for i in student:
            if del_id in i.values():
                student.remove(i)  # remove() 函数可以删除列表中的指定元素
                print(student)
                print('删除成功')
                break
            else:
                print('查无此人！')
    else:
        print('成绩表无信息')


def update():
    if len(student) != 0:
        modi_info = input('请输入要修改学生的学号：')
        for i in student:
            if modi_info in i.values():
                # 获取所在元组在列表中的索引位置
                index_num = student.index(i)
                dict_cur_stuinfo = student[index_num]
                for title, info in dict_cur_stuinfo.items():
                    print(title + ':' + info)
                modi_id = input('请输入新的学号：')
                modi_name = input('请输入新的姓名：')
                modi_grade = input('请输入新的成绩：')
                dict_cur_stuinfo.update(学号=modi_id)
                dict_cur_stuinfo.update(姓名=modi_name)
                dict_cur_stuinfo.update(成绩=modi_grade)
                print(student)
    else:
        print('成绩表无信息')


def query():
    if len(student) != 0:
        query_id = input('请输入要查找的学生学号：')
        for i in student:
            if query_id in i.values():
                index_num = student.index(i)
                for title, info in student[index_num].items():
                    print(title + ':' + info)
                break
            else:
                print('查无此人！')
    else:
        print('成绩表无信息')


if __name__ == "__main__":
    main()
