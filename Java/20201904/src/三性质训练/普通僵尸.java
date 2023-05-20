package 三性质训练;

import java.awt.Graphics;
import java.awt.Image;
import java.awt.Rectangle;
import javax.swing.ImageIcon;


public class 普通僵尸
{
	//f
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
	int[] rect = new int[]{ 62,20,84,122 };

	//c
	public 普通僵尸()
	{
		x = (int) (Math.random()*700);
		y = (int) (Math.random()*500+60);
		tuLuJing = "images/僵尸/普通僵尸/前进3/Frame";
		zongTuShu = 17;
	}
	//m
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
			x-=2;
		}

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

	Rectangle getRect()
	{
		return new Rectangle(x+rect[0], y+rect[1], rect[2], rect[3]);
	}
}
