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
	//����Run�������"bicycle  run!"

	void Run() { cout << "bicycle run" << endl; }

	//����Stop�������"bicycle  stop!"

	void Stop() { cout << "bicycle stop" << endl; }
};
class Motorcar : virtual public Vehicle
{
public:
	int SeatNum;

	//����Run�������"motocar  run!"

	void Run() { cout << "motocar run" << endl; }

	//����Stop����  "motocar  stop!"

	void Stop() { cout << "motocar stop" << endl; }
};
class Motorcycle : public Bicycle, public Motorcar
{
public:
	int SeatNum;
	//����Run�������  "motocycle  run!"

	void Run() { cout << "motocycle run" << endl; }

	//����Stop����  "motocycle  stop!"

	void Stop() { cout << "motocycle stop" << endl; }
};
int main()
{
	Vehicle v;
	v.Run();  //���vehicle  run!
	v.Stop(); //���vehicle  stop!
	Bicycle b;
	b.Run();  //���bicycle  run!
	b.Stop(); //���bicycle  stop!
	Motorcar m;
	m.Run();  //���motocar  run!
	m.Stop(); //���motocar  stop!
	Motorcycle mc;
	mc.Run();  //���motocycle  run!
	mc.Stop(); //���motocycle  stop!
	Vehicle *vp = &v;
	vp->Run();	//���vehicle  run!
	vp->Stop(); //���vehicle  stop!
	vp = &b;
	vp->Run();	//���bicycle  run!
	vp->Stop(); //���bicycle  stop!
	vp = &m;
	vp->Run();	//���motocar  run!
	vp->Stop(); //���motocar  stop!
	vp = &mc;
	vp->Run();	//���motocycle  run!
	vp->Stop(); //���motocycle  stop!
	return 0;
}