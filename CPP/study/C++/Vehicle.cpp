#include <iostream>
using namespace std;

class Vehicle
{
public:
	int MaxSpeed;
	int Weight;

	virtual void Run() { cout << "vehicle  run!" << endl; }

	virtual void Stop() { cout << "vehicle  stop!" << endl; }
};
class Bicycle : virtual public Vehicle
{
public:
	int Height;
	//补充Run函数输出"bicycle  run!"

	void Run() { cout << "bicycle run" << endl; }

	//补充Stop函数输出"bicycle  stop!"

	void Stop() { cout << "bicycle stop" << endl; }
};
class Motorcar : virtual public Vehicle
{
public:
	int SeatNum;

	//补充Run函数输出"motocar  run!"

	void Run() { cout << "motocar run" << endl; }

	//补充Stop函数  "motocar  stop!"

	void Stop() { cout << "motocar stop" << endl; }
};
class Motorcycle : public Bicycle, public Motorcar
{
public:
	int SeatNum;
	//补充Run函数输出  "motocycle  run!"

	void Run() { cout << "motocycle run" << endl; }

	//补充Stop函数  "motocycle  stop!"

	void Stop() { cout << "motocycle stop" << endl; }
};
int main()
{
	Vehicle v;
	v.Run();  //输出vehicle  run!
	v.Stop(); //输出vehicle  stop!
	Bicycle b;
	b.Run();  //输出bicycle  run!
	b.Stop(); //输出bicycle  stop!
	Motorcar m;
	m.Run();  //输出motocar  run!
	m.Stop(); //输出motocar  stop!
	Motorcycle mc;
	mc.Run();  //输出motocycle  run!
	mc.Stop(); //输出motocycle  stop!
	Vehicle *vp = &v;
	vp->Run();	//输出vehicle  run!
	vp->Stop(); //输出vehicle  stop!
	vp = &b;
	vp->Run();	//输出bicycle  run!
	vp->Stop(); //输出bicycle  stop!
	vp = &m;
	vp->Run();	//输出motocar  run!
	vp->Stop(); //输出motocar  stop!
	vp = &mc;
	vp->Run();	//输出motocycle  run!
	vp->Stop(); //输出motocycle  stop!
	return 0;
}