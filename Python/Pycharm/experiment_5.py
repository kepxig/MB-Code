# 1.文件打开，关闭，读，写
"""
f = open('test.txt', mode='r+', encoding='utf-8', buffering=1)
print(f.read())
f.write('\npython')
f.close()
"""
# 2.目录操作和文件拷贝操作
"""
import os

p = os.getcwd()  # 获取当前工程文件夹
print(p)  # 打印当前文件夹
print(os.listdir())  # 打印当前文件夹下所有文件名列表
os.mkdir('test')  # 在下面创建子文件夹test
os.chdir(p + '\\test')  # 改变当前文件夹路径
f = open('t.txt', 'w+')  # 新建一个文本文件
f.write('this is a test file!')  # 写入一行字符串
f.close()  # 关闭文件后才能继续对文件进行改名和删除操作。
os.rename('t.txt', 't1.txt')  # 文件改名
import shutil  # 引入shutil ，拷贝用

shutil.copy('t1.txt', 't2.txt')
os.remove('t1.txt')
"""
# 3.
import os


def welcome():
    while True:
        print("欢迎使用学生成绩管理程序!")
        print("------------------")
        print("1.成绩录入")
        print("2.成绩查询")
        print("3.成绩删除")
        print("4.成绩修改")
        print("5.退出")
        print("------------------")
        option = input("请选择功能:\n")
        # 用户注册
        if option == '1':
            register()
        # 成绩查询
        elif option == '2':
            query()
        # 注销
        elif option == '3':
            cancel()
        # 修改总分
        elif option == '4':
            modify()
        elif option == '5':
            break


# 将文件中的数据转换为字典
def convert_data():
    info_li = []
    with open('./info.txt', mode='r+', encoding='utf8') as f:
        info_data = f.readlines()
        for i in info_data:
            info_dict = dict()
            # 替换{ 和 } 并去掉空格
            step_one = (i.replace('{', '')).replace('}', '')
            # print(len(step_one))
            # print(step_one)
            # 以冒号进行分隔
            step_two = step_one.split(':')
            # print(len(step_two))
            # print(step_two)
            # 拼接字典
            info_dict["姓名"] = step_two[1].split(',')[0].replace("'", '').strip()  # 用逗号分开两个元素，并取第一个元素姓名再去掉单引号
            info_dict["总分"] = step_two[2].replace("'", '').strip()  # 删除单引号和回车符
            # 保存到列表中
            info_li.append(info_dict)
    return info_li


# 注册
def register():
    if os.path.exists('./info.txt') is not True:
        with open('./info.txt', mode='w', encoding='utf8') as f:
            f.write('')
    # 用户名列表
    name_li = []
    info_li = convert_data()
    # 接收注册信息
    student_info = {}
    name = input("请输入学生姓名：\n")
    # 获取用户列名列表
    for i in info_li:
        name_li.append(i['姓名'])
    # 判断用户是否存在
    if name in name_li:
        print('用户已注册')
    else:
        score = input("请输入总分：\n")
        student_info['姓名'] = name
        student_info['总分'] = score
        # 以追加的形式写入注册信息到info.txt中
        with open('./info.txt', mode='a+', encoding='utf8') as info_data:
            info_data.write(str(student_info) + '\n')


# 登录
def query():
    if os.path.exists('./info.txt') is not True:
        print('当前无数据，请先录入')
    else:
        # 用户名列表
        name_li = []
        info_li = convert_data()
        name = input("请输入学生姓名：\n")

        # 获取用户列名列表
        for i in info_li:
            name_li.append(i['姓名'])
        # 判断用户是否存在
        if name in name_li:
            # 获取修改用户的索引
            modify_index = name_li.index(name)
            print(info_li[modify_index]['总分'])


# 注销
def cancel():
    if os.path.exists('./info.txt') is not True:
        print('当前无数据，请先录入')
    else:
        cancel_name = input("请输入删除成绩的学生姓名\n")

        # 用户名列表
        name_li = []
        info_li = convert_data()
        for i in info_li:
            name_li.append(i['姓名'])
        if cancel_name in name_li:
            # 获取注销用户的索引
            cancel_index = name_li.index(cancel_name)
            # 判断输入的密码是否正确

            info_li.pop(cancel_index)  # 参数为索引值，与del区别：返回删除的元素
            # 写入空数据到info.txt中清空文件中的数据
            with open('./info.txt', mode='w+', encoding='utf8') as f:
                f.write('')
            # 重新写入已经注销用户后剩余的列表中的数据到info.txt中
            for i in info_li:
                with open('./info.txt', mode='a+', encoding='utf8') as info_data:
                    info_data.write(str(i) + '\n')
            print('删除成功!')
        else:
            print('查无此人！')

# 修改密码
def modify():
    if os.path.exists('./info.txt') is not True:
        print('当前无数据，请先注册')
    else:
        # 用户名列表
        name_li = []
        info_li = convert_data()
        modify_name = input("请输入姓名：\n")
        # 获取用户列名列表
        for i in info_li:
            name_li.append(i['姓名'])
        # 判断用户是否存在
        if modify_name in name_li:
            # 获取修改密码用户的索引
            modify_index = name_li.index(modify_name)  # 返回列表中元素为modify_name的索引序号
            # 判断密码是否正确
            # if password == info_li[modify_index]['总分']:
            # 修改密码
            new_password = input("请输入新总分\n")
            info_li[modify_index]['总分'] = new_password
            print('修改成功！')
            with open('./info.txt', mode='w+', encoding='utf8') as f:
                f.write('')
            for i in info_li:
                with open('./info.txt', mode='a+', encoding='utf8') as info_data:
                    info_data.write(str(i) + '\n')

        else:
            print("查无此人!")


if __name__ == '__main__':
    welcome()
