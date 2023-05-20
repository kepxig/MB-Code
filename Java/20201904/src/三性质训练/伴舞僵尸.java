package 三性质训练;

public class 伴舞僵尸 extends 普通僵尸{
    伴舞僵尸(){
        x = (int) (Math.random()*700);
        y = (int) (Math.random()*500+60);
        tuLuJing = "images/僵尸/伴舞僵尸/前进/Frame";
        zongTuShu = 27;
    }
}
