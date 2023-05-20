package 三性质训练;

public class Baby extends People{
    boolean sex;
    Baby(){
        //构造方法第一行必须调用父类的构造方法
        //默认调用父类的无参构造方法
        super();
    }
    public Baby(String name, int age,boolean sex) {
        super(name, age);
        this.sex=sex;
    }

    //校验   验证下面的方法是否为父类的重写方法
    //子类继承父类,子类对父类方法的重新定义,只改变方法体不改变返回类型和参数
    //方法的可见性只能升高不能降低  方法的重写 覆盖
    @Override
     void eat() {
        System.out.println("喝奶");
    }

    public static void main(String[] args) {
        Baby b = new Baby("A",1,true);

    }
}
