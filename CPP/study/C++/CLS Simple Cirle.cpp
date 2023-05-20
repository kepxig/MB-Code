#include <iostream>
using namespace std;
class SimpleCircle

{

public:
    SimpleCircle();

    SimpleCircle(int);

    SimpleCircle(const SimpleCircle &);

    ~SimpleCircle() {}

    void SetRadius(int);

    int GetRadius() const;

private:
    int *itsRadius;
};

SimpleCircle::SimpleCircle()

{

    itsRadius = new int(5);
}

SimpleCircle::SimpleCircle(int radius)

{

    itsRadius = new int(radius);
}

SimpleCircle::SimpleCircle(const SimpleCircle &rhs)

{

    int val = rhs.GetRadius();

    itsRadius = new int(val);
}

int SimpleCircle::GetRadius() const

{

    return *itsRadius;
}

int main()

{

    SimpleCircle CircleOne, CircleTwo(9);

    cout << "CircleOne: " << CircleOne.GetRadius() << endl;

    cout << "CircleTwo: " << CircleTwo.GetRadius() << endl;

    return 0;
}
