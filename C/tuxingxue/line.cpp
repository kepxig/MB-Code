#include <graphics.h>
#include <cstdio>
#include <cmath>
using namespace std;
class Point
{
protected:
    int x;
    int y;
    int r;
    int x1;
    int y1;

public:
    Point()
    {
        x = 0;
        y = 0;
        r = 0;
        x1 = 0;
        y1 = 0;
    }
    virtual void set(int a, int b) = 0;
    virtual void setstart(int a, int b) = 0;
    virtual void draw() = 0;
    virtual void drawf() = 0;
    int getx() const
    {
        return x;
    }

    int gety() const
    {
        return y;
    }
};
class MyCircle : public Point //圆类
{
    virtual void set(int a, int b)
    {
        int dx = getx() - a;
        int dy = gety() - b;
        r = (int)sqrt(dx * dx + dy * dy);
        x1 = a;
        y1 = b;
    }

    virtual void setstart(int a, int b) //定初始点
    {
        x = a;
        y = b;
        r = 0;
        x1 = a;
        y1 = b;
    }

    virtual void draw() //画空心
    {
        circle(x, y, r);
    }

    virtual void drawf() //画实心
    {
        setfillstyle(SOLID_FILL, getcolor());
        pieslicef(x, y, 0, 360, r);
    }
};
class rcircle : public Point //椭圆类
{
public:
    virtual void set(int a, int b)
    {
        x1 = getx() - a;
        y1 = gety() - b;
    }

    virtual void setstart(int a, int b) //椭圆定初始点
    {
        x = a;
        y = b;
        r = 0;
        x1 = 0;
        y1 = 0;
    }

    virtual void draw()
    {
        ellipsef(x, y, 0, 360, x1, y1);
    }

    virtual void drawf()
    {
        setfillstyle(SOLID_FILL, getcolor());
        fillellipse(x, y, x1, y1);
    }
};
class Myline : public MyCircle //线类
{
public:
    virtual void draw()
    {
        line(x, y, x1, y1);
    }

    virtual void drawf()
    {
        line(x, y, x1, y1);
    }
};
class Ju : public MyCircle //矩形类
{
public:
    virtual void draw()
    {
        rectangle(x, y, x1, y1);
    }

    virtual void drawf()
    {
        setfillstyle(SOLID_FILL, getcolor());
        int poly[8] = {x, y, x1, y, x1, y1, x, y1};
        fillpoly(4, poly);
    }
};
int main()
{
    MUSIC mus1;                    // 定义一个音乐对象
    mus1.OpenFile("yinxiao1.mp3"); // 打开文件
    MUSIC mus2;
    mus2.OpenFile("yinxiao2.mp3");
    int b = 0;
    MyCircle r;
    rcircle nr;
    Myline l;
    Ju ju;
    Point *p = &r;      //定义一个指向基类对象的指针变量
    bool bDraw = false; // 绘图标志，按下鼠标左键设置为true，抬起鼠标左键或在绘图过程中按鼠标右键设置为false
    initgraph(800, 600, INIT_RENDERMANUAL);

    /*画一个按钮*/
    setfillstyle(SOLID_FILL, BLUE); //颜色按钮
    bar(10, 20, 40, 50);
    setfillstyle(SOLID_FILL, YELLOW);
    bar(40, 20, 70, 50);
    setfillstyle(SOLID_FILL, RED);
    bar(70, 20, 100, 50);
    setfillstyle(SOLID_FILL, GREEN);
    bar(100, 20, 130, 50);
    setfillstyle(SOLID_FILL, WHITE);
    bar(130, 20, 160, 50);
    setfillstyle(SOLID_FILL, 0xFF6100);
    bar(160, 20, 190, 50);
    setfillstyle(SOLID_FILL, 0xA020E0);
    bar(190, 20, 220, 50);

    setfillstyle(SOLID_FILL, WHITE); //图形按钮
    bar(10, 51, 40, 81);
    setfillstyle(SOLID_FILL, BLACK);
    line(15, 66, 35, 66);
    setfillstyle(SOLID_FILL, WHITE);
    bar(10, 82, 40, 112);
    setfillstyle(SOLID_FILL, BLACK);
    circle(25, 97, 10);
    setfillstyle(SOLID_FILL, WHITE);
    bar(10, 113, 40, 143);
    setfillstyle(SOLID_FILL, BLACK);
    rectangle(15, 120, 35, 136);
    setfillstyle(SOLID_FILL, WHITE);
    bar(10, 144, 40, 174);
    setfillstyle(SOLID_FILL, BLACK);
    ellipsef(25, 159, 0, 360, 10, 6);

    setfillstyle(SOLID_FILL, WHITE); // 空心实心按钮
    bar(10, 175, 40, 205);
    outtextxy(15, 180, "fill");
    setfillstyle(SOLID_FILL, WHITE);
    bar(10, 206, 40, 236);
    outtextxy(10, 210, "unfill");

    outtextxy(335, 35, "line width"); //线宽按钮
    setfillstyle(SOLID_FILL, WHITE);
    bar(400, 20, 430, 50);
    setfillstyle(SOLID_FILL, BLACK);
    bar(405, 35, 425, 36);
    setfillstyle(SOLID_FILL, WHITE);
    bar(435, 20, 465, 50);
    setfillstyle(SOLID_FILL, BLACK);
    bar(440, 35, 460, 38);
    setfillstyle(SOLID_FILL, WHITE);
    bar(470, 20, 500, 50);
    setfillstyle(SOLID_FILL, BLACK);
    bar(475, 35, 495, 40);

    outtextxy(565, 35, "line style"); // 线型按钮
    setfillstyle(SOLID_FILL, WHITE);
    bar(630, 20, 660, 50);
    setcolor(BLACK);
    setlinestyle(PS_SOLID, 0, 1, NULL);
    line(632, 35, 657, 35);
    setfillstyle(SOLID_FILL, WHITE);
    bar(665, 20, 695, 50);
    setcolor(WHITE);
    setlinestyle(PS_DOT, 0, 1, NULL);
    line(667, 35, 690, 35);

    setlinewidth(3); //边框
    setcolor(WHITE);
    line(45, 55, 45, 595);
    line(45, 55, 795, 55);
    line(45, 595, 795, 595);
    line(795, 55, 795, 595);
    setlinewidth(1);

    setfillstyle(SOLID_FILL, WHITE); // clear按钮
    bar(10, 300, 40, 330);
    outtextxy(10, 305, "clear");

    setfont(16, 0, "宋体");
    setcolor(0x00F000F0);
    setbkcolor(BLACK);
    setlinestyle(PS_SOLID);
    mouse_msg msg = {0};

    for (; is_run(); delay_fps(60)) // 消息循环
    {
        //获取鼠标消息，这个函数会等待，等待到有消息为止
        //类似地，有和kbhit功能相近的函数MouseHit，用于检测有没有鼠标消息
        while (mousemsg())
        {
            msg = getmouse(); //得到鼠标位置
        }

        if (msg.is_down()) // 有鼠标键按下
        {
            if (msg.is_left()) // 是鼠标左键
            {
                mus1.Play(0);
                if (msg.x > 9 & msg.x<41 & msg.y> 19 & msg.y < 51) //按下按钮转化颜色
                {
                    setcolor(0x0000FF);
                }
                else if (msg.x > 39 & msg.x<71 & msg.y> 19 & msg.y < 51)
                {
                    setcolor(0xFFFF00);
                }
                else if (msg.x > 69 & msg.x<101 & msg.y> 19 & msg.y < 51)
                {
                    setcolor(0xFF0000);
                }
                else if (msg.x > 99 & msg.x<131 & msg.y> 19 & msg.y < 51)
                {
                    setcolor(0x00FF00);
                }
                else if (msg.x > 129 & msg.x<161 & msg.y> 19 & msg.y < 51)
                {
                    setcolor(0xFFFFFF);
                }
                else if (msg.x > 159 & msg.x<191 & msg.y> 19 & msg.y < 51)
                {
                    setcolor(0xFF6100);
                }
                else if (msg.x > 189 & msg.x<211 & msg.y> 19 & msg.y < 51)
                {
                    setcolor(0xA020E0);
                }
                else if (msg.x > 399 & msg.x<431 & msg.y> 19 & msg.y < 51) //按下按钮转化线宽
                {
                    setlinewidth(1);
                    setcolor(getcolor());
                }
                else if (msg.x > 434 & msg.x<466 & msg.y> 19 & msg.y < 51)
                {
                    setlinewidth(3);
                    setcolor(getcolor());
                }
                else if (msg.x > 469 & msg.x<501 & msg.y> 19 & msg.y < 51)
                {
                    setlinewidth(9);
                    setcolor(getcolor());
                }
                else if (msg.x > 9 & msg.x<41 & msg.y> 299 & msg.y < 331) //按下按钮清除裁剪区
                {
                    setfillstyle(SOLID_FILL, BLACK);
                    bar(48, 58, 792, 592);
                }

                else if (msg.x > 630 & msg.x<650 & msg.y> 20 & msg.y < 50) //按下按钮改变边线样式
                {
                    setlinestyle(PS_SOLID, 0, 1, NULL);
                    setcolor(getcolor());
                }

                else if (msg.x > 665 & msg.x<695 & msg.y> 20 & msg.y < 50)
                {
                    setlinestyle(PS_DOT, 0, 1, NULL);
                    setcolor(getcolor());
                }

                else if (msg.x > 9 & msg.x<41 & msg.y> 50 & msg.y < 82) //设置一个确认图形的开关
                {
                    p = &l;
                }
                else if (msg.x > 9 & msg.x<41 & msg.y> 81 & msg.y < 113)
                {
                    p = &r;
                }
                else if (msg.x > 9 & msg.x<41 & msg.y> 112 & msg.y < 144)
                {
                    p = &ju;
                }
                else if (msg.x > 9 & msg.x<41 & msg.y> 143 & msg.y < 175)
                {
                    p = &nr;
                }
                else if (msg.x > 9 & msg.x<41 & msg.y> 174 & msg.y < 206) //设置一个选择实心空心的开关
                {
                    b = 1;
                }
                else if (msg.x > 9 & msg.x<41 & msg.y> 205 & msg.y < 237)
                {
                    b = 0;
                }
                else
                {
                    p->setstart(msg.x, msg.y);
                    setwritemode(R2_XORPEN); // 设置XOR模式
                    bDraw = true;            // 开始跟踪鼠标画图
                }
            }
        }
        if (msg.is_right()) // 是鼠标右键
        {
            if (bDraw)
            {
                mus2.Play(0);
                if (b == 0)
                {
                    p->draw();
                }
                else
                    p->drawf();           // 清除图形
                setwritemode(R2_COPYPEN); // 设置copy模式
                bDraw = false;
            }
        }
        else if (msg.is_move()) // 移动鼠标
        {
            if (bDraw)
            {
                if (b == 0)
                {
                    p->draw();
                }
                else
                    p->drawf(); // 清除之前绘制的图形
                p->set(msg.x, msg.y);
                if (b == 0)
                {
                    p->draw();
                } // 修改坐标后绘制新图形
                else
                    p->drawf();
            }
        }
        else if (msg.is_up()) // 抬起鼠标按键
        {
            if (bDraw)
            {
                setwritemode(R2_COPYPEN); // 用copy模式重新绘制图形
                p->set(msg.x, msg.y);
                if (b == 0)
                {
                    p->draw();
                } // 修改坐标后绘制新图形
                else
                    p->drawf();
                bDraw = false;
            }
        }
        xyprintf(0, 0, "x=%4d y=%4d", msg.x, msg.y); // 实时显示鼠标坐标
    }
    closegraph();
    return 0;
}
