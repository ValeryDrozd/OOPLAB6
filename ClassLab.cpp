#include <iostream>
using namespace std;

class figure {
public:
	virtual double surfaceArea();
	virtual double volume();
};

class parallelepiped :public figure {
	int a, b, c;
public:
	parallelepiped() {

	}
	parallelepiped(int a,int b,int c) {
		this->a = a;
		this->b = b;
		this->c = c;
	}
	double surfaceArea() override {
		return 2 * (a * c + b * a + b * c);
	}
	double volume() override{
		return a * b * c;
	}
	int getHeight() {
		return this->a;
	}
	int getWight() {
		return this->b;
	}
	int getLenght() {
		return this->c;
	}
};

class cube : public figure{
	int a;
public:
	cube() {

	}
	cube(int a) {
		this->a = a;
	}
	double surfaceArea() override {
		return 6 * a * a;
	}
	double volume() override {
		return a * a * a;
	}
	int side() {
		return a;
	}
};

class tetraedr : public figure {
	int a;
public:
	tetraedr() {

	}
	tetraedr(int a) {
		this->a = a;
	}
	double surfaceArea() {
		return 1.0 * a * a * sqrt(3);
	}
	double volume() {
		return 1.0 * a * a * a * sqrt(2) / 12;
	}
	int side() {
		return a;
	}
};

int main() {
	cube c(3);
	cout << "Side of the cube: " << c.side() << endl;
	cout << "Volume of the cube: " << c.volume() << endl;
	cout << "Area of surfaces: " << c.surfaceArea() << endl;
	parallelepiped a(1, 2, 3);
	cout << "Sides of parallelepiped: " << a.getHeight() << ',' << a.getLenght() << ',' << a.getWight() << endl;
	cout << "Volume of the parallelepiped: " << a.volume() << endl;
	cout << "Area of surfaces: " << a.surfaceArea() << endl;
	tetraedr t(3);
	cout << "Side of the tetraedr: " << t.side() << endl;
	cout << "Volume of the tetraedr: " << t.volume() << endl;
	cout << "Area of surfaces: " << t.surfaceArea() << endl;
}