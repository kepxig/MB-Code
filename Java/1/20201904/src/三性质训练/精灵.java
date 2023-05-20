package 三性质训练;

import javax.swing.*;
import java.awt.*;

public class 精灵 {
    int state;
    int hp;
    /**
     * 显示的x坐标
     */
    int x;
    /**
     * 显示的y坐标
     */
    int y;
    /**
     * 图片号
     */
    int tuHao;
    /**
     * 图路径
     */
    String tuLuJing;
    /**
     * 总图数
     */
    int zongTuShu;
    /**
     * 死掉了吗
     */
    boolean siLe = false;
    /**
     * 有效矩形区域
     */
    int[] rect = new int[]{ 62,20,84,122 };//真实图片的左上角点坐标 真实图像的宽高

    public 精灵() {

    }

    /**
     * 显示
     * @param g
     */
    void xianShi(Graphics g)
    {
        Image  tu=(new ImageIcon( tuLuJing+tuHao+".png")).getImage();
        g.drawImage(tu,x,y,null);
    }

    /**
     * 动<br>
     * 图片切换
     */
    void dong()
    {
        if (tuHao==zongTuShu)
        {
            tuHao = 0;
        }
        else
        {
            tuHao++;
        }
    }

    Rectangle getRect()
    {
        return new Rectangle(x+rect[0], y+rect[1], rect[2], rect[3]);
    }
}
