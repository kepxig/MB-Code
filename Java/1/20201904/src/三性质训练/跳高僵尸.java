package 三性质训练;

public class 跳高僵尸 extends 普通僵尸{
    int state;//0拿杆前进1起跳2落地3无杆前进
    跳高僵尸(){
        x = (int) (Math.random()*700);
        y = (int) (Math.random()*500+60);
        tuLuJing = "images/僵尸/跳高僵尸/拿杆前进/Frame";
        zongTuShu = 9;
        state=0;
    }
    void qiTiao(){
        state=1;
        tuHao=0;
        tuLuJing="images/僵尸/跳高僵尸/起跳/Frame";
        zongTuShu=9;
    }
    void luoDi(){
        state=2;
        tuHao=0;
        tuLuJing="images/僵尸/跳高僵尸/落地/Frame";
        zongTuShu=6;
    }
    void wuGanQianJin(){
        state=3;
        tuHao=0;
        tuLuJing="images/僵尸/跳高僵尸/无杆前进/Frame";
        zongTuShu=24;
    }


    @Override
    void qianJin() {
        super.qianJin();
        if(state==1&&tuHao==zongTuShu){
            luoDi();
        }else if(state==2&&tuHao==zongTuShu){
            wuGanQianJin();
        }
    }





    
}
