#include <iostream>
#include <string>
using namespace std;
class Employee
{
private:
	char* name;
	char* address;
	char* city;
	char* code;
public:
	Employee(char* n, char* add, char* ct, char* cd) :name(n), address(add), city(ct), code(cd) {}
	void display()
	{
		cout << "name: " << name<<"\n";
		cout << "address: " << address<<"\n";
		cout << "city: " << city<<"\n";
		cout << "code: " << code<<"\n";
	}
	void change_name(char* n)
	{
		name = n;
	}
};
int main()
{
	Employee e("Wang Er", "Haidian", "Beijing", "100084");
	e.display();
	e.change_name("Li San");
	e.display();
	return 0;
}