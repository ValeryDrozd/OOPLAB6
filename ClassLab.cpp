#include <iostream>
using namespace std;

class figure {
protected:
	int a[3];
public:
	virtual double surfaceArea() { return 0; }
	virtual double volume() { return 0; }
	virtual void getSides(){}
};

class parallelepiped :public figure {
	
public:
	parallelepiped() {

	}
	parallelepiped(int a,int b,int c) {
		this->a[0] = a;
		this->a[1] = b;
		this->a[2] = c;
	}
	parallelepiped(istream& in) {
		cout << "Enter sides of paralelepiped\n";
		in >> this->a[0] >> this->a[1] >> this->a[2];
	}
	double surfaceArea() override {
		return 2 * (a[0] * a[2] + a[1] * a[0] + a[1] * a[2]);
	}
	double volume() override{
		return a[0] * a[1] * a[2];
	}
	void getSides() override{
		cout << "Sides of paralelepiped" << endl;
		cout << "Height: " << this->a[0] << endl;
		cout << "Wight: " << this->a[1] << endl;
		cout << "Lenght: " << this->a[2] << endl;
	}
};

class cube : public figure{
public:
	cube() {

	}
	cube(int a) {
		this->a[0] = a;
	}
	cube(istream& in){
		cout << "Enter side of cube\n";
		in >> this->a[0];
	}
	double surfaceArea() override {
		double v = 6 * a[0] * a[0];
		return v;
	}
	double volume() override {
		return pow(a[0], 3);
	}
	void getSides() override {
		cout << "Side of cube " <<a[0]<< endl;
	}
};

class tetraedr : public figure {
public:
	tetraedr() {

	}
	tetraedr(int a) {
		this->a[0] = a;
	}

	tetraedr(istream& in) {
		cout << "Enter side of tetraedr\n";
		in >> a[0];
	}
	double surfaceArea() override{
		return 1.0 * a[0] * a[0] * sqrt(3);
	}
	double volume() override {
		return 1.0 * pow(a[0],3) * sqrt(2) / 12;
	}
	void getSides() override {
		cout << "Side of tetraedr " << a[0] << endl;
	}
};

int main() {
	int cmd;
	bool run = true;
	figure* f;


	f = new cube(cin);
	f->getSides();
	cout << "Volume of the cube: " << f->volume() << endl;
	cout << "Area of surfaces: " << f->surfaceArea() << endl;

	f = new  parallelepiped(cin);
	f->getSides();
	cout << "Volume of the parallelepiped: " << f->volume() << endl;
	cout << "Area of surfaces: " << f->surfaceArea() << endl;
	
	f = new tetraedr(cin);
	f->getSides();
	cout << "Volume of the tetraedr: " << f->volume() << endl;
	cout << "Area of surfaces: " << f->surfaceArea() << endl;
}