#include <iostream>
#include <string>
#include <cassert>
using namespace std;
class Point
{
public:
	int x = 0, y = 0;
	void move(int x, int y)
	{
		x = x;
		y = y;
	}
};

class ArrayOfPoints
{
private:
	Point *points;
	int size;

public:
	ArrayOfPoints(int size) : size(size)
	{
		points = new Point[size];
	}
	~ArrayOfPoints()
	{
		cout << "Deleting..." << endl;
		delete points;
	}
	Point &element(int index)
	{
		assert(index >= 0 && index < size);
		return points[index];
	}
};
int main()
{
	int count;
	cout << "Please enter the count of points:";
	cin >> count;
	ArrayOfPoints points(count);
	points.element(0).move(5, 0);
	points.element(1).move(15, 20);
	return 0;
}