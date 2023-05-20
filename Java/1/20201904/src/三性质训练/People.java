package 三性质训练;

public class People {
    String name;
    int age;
    //public protected default private
    void eat(){
        System.out.println("吃饭");
    }
    People(){}
    public People(String name, int age) {
        this.name = name;
        this.age = age;
    }
}
