#ifndef __COMPLEX__
#define __COMPLEX__ //防卫式声明
//1.forward declarations 前置声明
class complex;
complex &
__doapl(complex *ths, const complex &r);
//2.class declarations 类-声明
class complex
{
public:
    complex(double r = 0, double i = 0) //defalut argument 默认实参
        : re(r), im(i)                  //initialization list 初始列
    {
    }
    complex &operator+=(const complex &); //设置为member function 成员函数
    double real() const { return re; }    //通过函数访问data
    double imag() const { return im; }    //data不改变,const

private:
    double re, im;
    friend complex &__doapl(complex *, const complex &);
    //友元写法to 58  //friend complex operator+(const complex &, const complex &);
};

//3.class definition 类-定义
inline complex &
__doapl(complex *ths, const complex &r) //加后存到this，不能const
{
    ths->re += r.re;
    ths->im += r.im;
    return *ths;
}
inline complex &                      //returntype：复数,不存在local object--可以返回reference
                                      //在本体之外---inline
complex::operator+=(const complex &r) //左边是隐藏参数
{
    return __doapl(this, r); //交给__doapl做
}

//real and imag function declaration.

inline double
real(const complex &x)
{
    return x.real();
}
inline double
imag(const complex &x)
{
    return x.imag();
}

//加法运算
inline complex                                //存在local object---return by value.
operator+(const complex &x, const complex &y) //复数+复数
{
    return complex(real(x) + real(y), imag(x) + imag(y));//x.real
    //友元写法  return complex(x.re + y.re, x.im + y.im); //temp object-临时对象
}

inline complex
operator+(const complex &x, const double y)
{
    return complex(real(x) + y, imag(x));
}

inline complex
operator+(const double x, const complex &y)
{
    return complex(x + real(y), imag(y));
}

#endif