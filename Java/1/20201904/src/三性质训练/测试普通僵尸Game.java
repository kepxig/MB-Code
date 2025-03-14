package 三性质训练;

import java.awt.*;
import java.awt.event.*;

import javax.swing.*;

public class 测试普通僵尸Game
{
	//TODO:变量“声明”在此
	普通僵尸 p1 = new 普通僵尸();
	跳高僵尸 t1 = new 跳高僵尸();
	伴舞僵尸 b1 = new 伴舞僵尸();
	普通僵尸[] jss = new 普通僵尸[30];
	高个坚果 g1 = new 高个坚果(0,0);
	吃人植物 c1 = new 吃人植物(1,0);
	冰冻豆瓣 d1= new 冰冻豆瓣(3,1);
	辣椒 l1 = new 辣椒(2,0);
	窗口	ck	= null;
	定时器	ds1	= null;

	测试普通僵尸Game()
	{
		//TODO:程序初始化在此
		for(int i=0;i<jss.length;i++){
			int sjs = (int)(Math.random()*3);
			switch (sjs){
				case 0:
					jss[i] = new 跳舞僵尸();
					break;
				case 1:
					jss[i] = new 跳高僵尸();
					break;
				case 2:
					jss[i] = new 伴舞僵尸();
					break;
			}
		}

		ck = new 窗口();
		//窗口 宽+2*立体边, 高+2*立体边+标题栏
		ck.setSize(5 * 2 + 1200, 800 + 2 * 5 + 25);
		//设定窗口可见性setVisible  true/false
		ck.setVisible(true);
		//延时的毫秒
		ds1 = new 定时器(100);
	}

	class 窗口 extends JFrame
	{
		菜单		cd		= null;
		面板		mb		= null;
		窗口监听器	exit	= null;
		键盘监听器	jp		= null;

		窗口()
		{
			jp = new 键盘监听器();
			this.addKeyListener(jp);

			cd = new 菜单();
			this.setJMenuBar(cd);

			mb = new 面板();
			this.add(mb);

			exit = new 窗口监听器();
			this.addWindowListener(exit);

			this.repaint();
		}

		class 菜单 extends JMenuBar
		{
			JMenu		dan;	//菜单
			JMenuItem	xiang1; //菜单项

			菜单监听器		cdjtq;

			菜单()
			{
				dan = new JMenu("游戏"); //菜单
				xiang1 = new JMenuItem("开局"); //菜单项

				this.add(dan);
				dan.add(xiang1);

				cdjtq = new 菜单监听器();
				xiang1.addActionListener(cdjtq);
			}

			class 菜单监听器 implements ActionListener
			{
				public void actionPerformed(ActionEvent e)
				{
					//TODO:菜单事件处理
					if (e.getSource() == xiang1)
					{

					}
				}
			}
		}

		class 窗口监听器 extends WindowAdapter
		{
			public void windowClosing(WindowEvent e)
			{
				ds1.xc.stop();
				System.exit(0);
			}
		}

		class 键盘监听器 implements KeyListener
		{
			//TODO:键盘处理，可加入KeyEvent.VK_XXX
			public void keyPressed(KeyEvent e)
			{
				switch (e.getKeyCode())
				{
					case KeyEvent.VK_LEFT://左

						break;
					case KeyEvent.VK_RIGHT://右

						break;
					case KeyEvent.VK_UP://上
						p1.zhaSi();
						t1.qiTiao();
						for(int i=0;i<jss.length;i++){
							if(jss[i] instanceof 跳舞僵尸){
								跳舞僵尸 tw = (跳舞僵尸) jss[i];
								tw.run();
							}else {
								jss[i].zhaSi();
							}
						}
						break;
					case KeyEvent.VK_W://下
						break;

				}
				repaint();
			}

			public void keyReleased(KeyEvent e)
			{
			}

			public void keyTyped(KeyEvent e)
			{
			}
		}

		class 面板 extends JPanel
		{
			鼠标监听器	sb	= null;

			面板()
			{
				sb = new 鼠标监听器();
				this.addMouseListener(sb);
				this.addMouseMotionListener(sb);
			}

			class 鼠标监听器 extends MouseAdapter implements MouseMotionListener
			{
				public void mousePressed(MouseEvent e)
				{
				}

				public void mouseDragged(MouseEvent e)
				{
				}

				public void mouseMoved(MouseEvent e)
				{
				}

				public void mouseReleased(MouseEvent e)
				{
				}

				public void mouseClicked(MouseEvent e)//鼠标单击
				{
					//mx my鼠标的位置
					int mx = e.getX();
					int my = e.getY();
					//鼠标左键	BUTTON1、右键BUTTON3
					if (e.getButton() == MouseEvent.BUTTON1)
					{
						//TODO:鼠标左键单击

					}

					repaint();
				}
			}

			public void paint(Graphics g)
			{
				//g.setColor(Color.BLUE);	//设定颜色：RED GREEN  BLUE  ORANGE  WHITE  GRAY BLACK PINK
				//g.drawRect(左,上,宽,高);	//矩形
				//g.fillRect(左,上,宽,高);	//实心矩形
				//g.drawOval(左,上,宽,高);	//椭圆
				//g.fillOval(左,上,宽,高);		//实心椭圆

				//Image  tu=(new ImageIcon( 路径 )).getImage();	//路径：图片-右键-属性-路径src/
				//g.drawImage(tu,x,y,null);

				//TODO:绘图在此
				Image  tu=(new ImageIcon("images/背景/background1.jpg")).getImage();
				g.drawImage(tu,0, 0,null);

				p1.xianShi(g);
				t1.xianShi(g);
				b1.xianShi(g);
				g1.xianShi(g);
				c1.xianShi(g);

				for(int i=0;i<jss.length;i++){
					jss[i].xianShi(g);
				}
				l1.xianShi(g);
			}
		}
	}

	class 定时器 implements Runnable//实现Runnable接口
	{
		Thread	xc	= null;
		long	jianGe;

		定时器(long jianGe)
		{
			this.jianGe = jianGe;
			xc = new Thread(this);
			xc.start();
		}

		public void run()
		{
			while (true)
			{
				try
				{
					xc.sleep(jianGe);

					if (this == ds1)
					{
						//TODO:定时处理

						p1.qianJin();
						t1.qianJin();
						b1.qianJin();
						for(int i=0;i<jss.length;i++){
							jss[i].qianJin();
						}
						g1.dong();
//						if(p1.x+70<g1.x+83&&p1.state==0&&g1.siLe==false){
//							p1.gongJi(g1);
//						}
//						if(p1.x+70<c1.x+83&&c1.state==0&&p1.siLe==false){
//							c1.yao(p1);
//						}
						c1.dong();
						l1.dong();
						for(int i=0;i<jss.length;i++){
							if(l1.getRect().intersects(jss[i].getRect())&&jss[i].siLe==false){
								l1.baoZha();
								jss[i].zhaSi();
							}

						}
						ck.repaint();
					}
				}
				catch (InterruptedException e)
				{
					e.printStackTrace();
				}
			}
		}
	}

	//main主方法 ，主类的“入口方法”
	public static void main(String[] args)
	{
		new 测试普通僵尸Game();
	}
}
