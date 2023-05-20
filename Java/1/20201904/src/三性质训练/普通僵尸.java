package 三性质训练;

import java.awt.Graphics;
import java.awt.Image;
import java.awt.Rectangle;
import javax.swing.ImageIcon;


public class 普通僵尸 extends 精灵 {
	//fstate=0;前进1攻击
    植物 zw;

    //c
	public 普通僵尸()
	{
        x = (int) (Math.random()*700);
        y = (int) (Math.random()*500+60);
        tuLuJing = "images/僵尸/普通僵尸/前进3/Frame";
        zongTuShu = 17;
        state=0;
        hp=50;
    }

    void gongJi(植物 zw){
	    state=1;
	    tuHao=0;
	    tuLuJing="images/僵尸/普通僵尸/攻击/Frame";
	    zongTuShu=20;
	    zw.hp--;
	    this.zw=zw;
    }
	//m

    /**
	 * 前进
	 */
	void qianJin()
	{
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
			if(state==0){
                x-=2;
			}
			if(state==1){
			    zw.hp--;
                System.out.println(zw.hp);
                if(zw.hp<=0){
                    tuHao=0;
                    tuLuJing = "images/僵尸/普通僵尸/前进3/Frame";
                    zongTuShu = 17;
                    state=0;

                }
			}

		}

	}

    /**
	 * 炸死
	 */
	void  zhaSi()
	{
		tuHao = 0;
		zongTuShu = 19;
		tuLuJing="images/僵尸/炸死/Frame";
		siLe = true;
	}

}
