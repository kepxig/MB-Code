package 三性质训练;

public class 跳舞僵尸 extends 普通僵尸{
    int state;//0跳舞1前进
    跳舞僵尸(){
        x = (int) (Math.random()*700);
        y = (int) (Math.random()*500+60);
        tuLuJing = "images/僵尸/领舞僵尸/跳舞/Frame";
        zongTuShu = 21;
        state=0;
    }
    void run(){
        state=1;
        tuHao=0;
        tuLuJing="images/僵尸/领舞僵尸/前进/Frame";
        zongTuShu=26;
    }


    @Override
    void qianJin() {
        if (siLe)
        {
            if (tuHao==zongTuShu) //图片切换完一轮
            {
                tuLuJing="";//让图片消失
                return;
            }
            else
            {
                dong();
            }
        }
        else
        {
            dong();
            if(state==1){
                x-=2;
            }

        }
    }
}
