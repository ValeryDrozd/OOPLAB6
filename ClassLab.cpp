#include <iostream>
using namespace std;

class figure {
protected:
	int a[3];
public:
	virtual double surfaceArea() { return 0; }
	virtual double volume() { return 0; }
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
	double surfaceArea() override {
		return 2 * (a[0] * a[2] + a[1] * a[0] + a[1] * a[2]);
	}
	double volume() override{
		return a[0] * a[1] * a[2];
	}
	int getHeight() {
		return this->a[0];
	}
	int getWight() {
		return this->a[1];
	}
	int getLenght() {
		return this->a[2];
	}
};

class cube : public figure{
public:
	cube() {

	}
	cube(int a) {
		this->a[0] = a;
	}
	double surfaceArea() override {
		return 6 * a[0] * a[0];
	}
	double volume() override {
		return pow(a[0], 3);
	}
	int side() {
		return a[0];
	}
};

class tetraedr : public figure {
public:
	tetraedr() {

	}
	tetraedr(int a) {
		this->a[0] = a;
	}
	double surfaceArea() {
		return 1.0 * a[0] * a[0] * sqrt(3);
	}
	double volume() {
		return 1.0 * pow(a[0],3) * sqrt(2) / 12;
	}
	int side() {
		return a[0];
	}
};

int main() {
	int cmd;
	bool run = true;
	int a;
	cout << "Enter side of cube\n";
	cin >> a;
	cube cu(a);
	cout << "Side of the cube: " << cu.side() << endl;
	cout << "Volume of the cube: " << cu.volume() << endl;
	cout << "Area of surfaces: " << cu.surfaceArea() << endl;
	int b, c;
	cout << "Enter sides of paralelepiped\n";
	cin >> a >> b >> c;
	parallelepiped p(a,b,c);
	cout << "Sides of parallelepiped: " << p.getHeight() << ',' << p.getLenght() << ',' << p.getWight() << endl;
	cout << "Volume of the parallelepiped: " << p.volume() << endl;
	cout << "Area of surfaces: " << p.surfaceArea() << endl;
	cout << "Enter side of tetraedr\n";
	cin >> a;
	tetraedr t(a);
	cout << "Side of the tetraedr: " << t.side() << endl;
	cout << "Volume of the tetraedr: " << t.volume() << endl;
	cout << "Area of surfaces: " << t.surfaceArea() << endl;
}