package 三性质训练;

import java.awt.*;

public class 伴舞僵尸 extends 普通僵尸{
    伴舞僵尸(){
        x = (int) (Math.random()*700);
        y = (int) (Math.random()*500+60);
        tuLuJing = "images/僵尸/伴舞僵尸/前进/Frame";
        zongTuShu = 27;
    }//41 0 80 150
    int[] rect = new int[]{ 41,0,80,150 };
    Rectangle getRect()
    {
        return new Rectangle(x+rect[0], y+rect[1], rect[2], rect[3]);
    }


}
