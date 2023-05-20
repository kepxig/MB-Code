package com.oracle.oop;
//类的封装性
//定义一个类,将和这个类相关的属性和方法都定义在这个类中即为类的封装
//作用:方便重复调用,方便维护,提高代码复用性
public class Man {
    private String name;
    private int age;
    private boolean sex;
    //如何定义方法:
    //方法的返回类型   void无 String 八大基本类型  自定义类型
    //方法名    首字母小写驼峰  见名知意
    //参数  (参数类型 参数名称,...)形参
    //方法体  具体的实现代码
    //return   后接的值要与方法返回类型一致  如果没有返回值可以省略return
    void say(){
        System.out.println("说话");
    }

    /**
     * 赚钱 根据时间计算周期的钱数
     * @param money
     * @param day
     * @return
     */
    double makeMoney(double money,int day){
        return day*money;
    }
    //构造方法:
    //缺省构造器   在类里没有定义任何的构造方法,系统自动提供一个无参的构造方法
    Man(){}
    //构造方法的作用:用来给属性初始化赋值
    //构造方法与普通方法的区别
    //构造方法无返回类型
    //构造方法无return
    //构造方法名与类同名
    //调用方式   new 构造方法


    public Man(String name, int age, boolean sex) {
        this.name = name;
        this.age = age;
        this.sex = sex;
    }

    public static void main(String[] args) {
        //调用需要在主方法内调用
        //创建对象
        //引用变量 路标变量
        //类型 对象名称 = new 类型();构造方法
        Man man = new Man();
        Man man1 = new Man("A",10,true);
        System.out.println(man1.name);
        System.out.println(man1.age);
        System.out.println(man1.sex);
        //方法调用    对象名 .  方法();
//        man.say();
//        double money = man.makeMoney(100, 30);
//        System.out.println(money);




    }


}
