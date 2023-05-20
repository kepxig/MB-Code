package com.oracle.oop;

public class BanJi {
    private Student[] sts;
    BanJi(){
        sts = new Student[3];
    }


    /**
     * 招生
     * 将餐宿赋值到属性数组中,如果满员就输出位置已满
     * @param st
     */
    void recruitStudents(Student st){
        boolean you=false;
        //遍历数组,判断每个位置上是否有值
        for(int i=0;i<sts.length;i++){
            if(sts[i]==null){
                sts[i]=st;
                you=true;
                break;//跳出当前最近的循环
            }
        }
        if(you==false){
            System.out.println("位置已满");
        }
    }

    /**
     * 根据名字输出学生所有信息,如果没有就输出查无此人
     * @param name
     */
    void checkInformation(String name){
        //遍历属性数组
        boolean you=false;
        for(int i=0;i<sts.length;i++){
            //判断数组中的位置上是否有值
            //判断每个位置上的学生对象的姓名是否和参数一致
            if(sts[i]!=null&&sts[i].getName().equals(name)){
                you=true;
                System.out.println("姓名:"+sts[i].getName()+"性别:"+sts[i].isSex()+"分数:"+sts[i].getScore());
            }
        }
        if(you==false){
            System.out.println("查无此人");
        }
    }






    public static void main(String[] args) {
        BanJi bj = new BanJi();
        Student s1 = new Student("小红",false,90);
        Student s2 = new Student("小刚",true,80);
        Student s3 = new Student("小李",true,90);
        Student s4 = new Student("张三",true,70);
        bj.recruitStudents(s1);
        bj.recruitStudents(s2);
        bj.recruitStudents(s3);
//        bj.recruitStudents(s4);
//        for(int i=0;i<bj.sts.length;i++){
//            Student s = bj.sts[i];
//            if(s!=null){
//                System.out.println(s.getName());
//            }
//        }
        bj.checkInformation("小红1");




    }
}
