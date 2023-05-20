package 三性质训练;

import java.awt.*;

public class 辣椒 extends 植物{
    //state=0种好1爆炸
    辣椒(int hang, int lie) {
        super(hang, lie);
        tuHao=0;
        tuLuJing="images/植物/辣椒/Jalapeno/Frame";
        zongTuShu=7;
        state=0;
    }
    void baoZha(){
        state=1;
        tuHao=0;
        tuLuJing="images/植物/辣椒/JalapenoAttack/Frame";
        zongTuShu=7;
    }

    @Override
    void dong() {
        super.dong();
        if(state==1&&tuHao==zongTuShu){
            tuLuJing="";
            siLe=true;
        }
    }
    int[] rect = new int[]{ 0,70,755,50 };
    Rectangle getRect()
    {
        return new Rectangle(x+rect[0], y+rect[1], rect[2], rect[3]);
    }

}
