#打开成绩的csv文件
csv_f=open('score.csv',encoding='utf-8')
#创建一个存储带有总分的数据的csv文件
f_new=open('count.csv','w+',encoding='utf-8')
lines=[]
for line in csv_f:
    line=line.replace('\n','')#去掉line中最后回车符号，line是csv文件中的每行字符串
    lines.append(line.split(','))#line.split(',')将line表示的字符串转换为列表
# print(lines)
#添加表头字段
lines[0].append('总分')
# print(lines)
#添加总分分数
for i in range(len(lines)-1):#因为下面idx=i+1所以len(lines)要减去1才能访问到最后一项
    idx=i+1 #应为第一列表项为文字说明不需要求和，从第二个列表项开始，既下标为1开始
    sum=0
    for j in range(len(lines[idx])):
        if (lines[idx][j]).isdigit():#判断是否为数据
            sum+=int(lines[idx][j])
    lines[idx].append(str(sum))
# print(lines)
#将列表lines中的数据写入count.csv
for line in lines:
    f_new.write(','.join(line)+'\n')
    #以','作为分隔符，将line所有的元素合并成一个新的字符串,返回值：返回一个以分隔符'''连接各个元素后生成的字符串,每个字符串结束回行
csv_f.close()
f_new.close()