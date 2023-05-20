#include <iostream>
#include <math.h>
using namespace std;
class Circle
{
public:
    double radius;
    double getArea();
};
double Circle::getArea()
{
    return 3.14159 * pow(radius, 2);
}
int  main(){  
      Circle  c;
      c.radius  =  2;
      cout  <<  "Area="  <<  c.getArea()  <<  endl;
      return  0;
}
