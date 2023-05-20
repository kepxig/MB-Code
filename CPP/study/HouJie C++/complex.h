#ifndef __COMPLEX__
#define __COMPLEX__ //����ʽ����
//1.forward declarations ǰ������
class complex;
complex &
__doapl(complex *ths, const complex &r);
//2.class declarations ��-����
class complex
{
public:
    complex(double r = 0, double i = 0) //defalut argument Ĭ��ʵ��
        : re(r), im(i)                  //initialization list ��ʼ��
    {
    }
    complex &operator+=(const complex &); //����Ϊmember function ��Ա����
    double real() const { return re; }    //ͨ����������data
    double imag() const { return im; }    //data���ı�,const

private:
    double re, im;
    friend complex &__doapl(complex *, const complex &);
    //��Ԫд��to 58  //friend complex operator+(const complex &, const complex &);
};

//3.class definition ��-����
inline complex &
__doapl(complex *ths, const complex &r) //�Ӻ�浽this������const
{
    ths->re += r.re;
    ths->im += r.im;
    return *ths;
}
inline complex &                      //returntype������,������local object--���Է���reference
                                      //�ڱ���֮��---inline
complex::operator+=(const complex &r) //��������ز���
{
    return __doapl(this, r); //����__doapl��
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

//�ӷ�����
inline complex                                //����local object---return by value.
operator+(const complex &x, const complex &y) //����+����
{
    return complex(real(x) + real(y), imag(x) + imag(y));//x.real
    //��Ԫд��  return complex(x.re + y.re, x.im + y.im); //temp object-��ʱ����
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