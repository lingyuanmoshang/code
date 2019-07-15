#include<iostream>
#include<cmath>
using namespace std;
const  double PI = 3.14159;

class Element
{
public:
	virtual void Showdata() = 0;
	virtual void Predata() = 0;
	virtual ~Element() {}
};

class Point :public Element
{
private:
	double x, y;
public:
	double Getx() { return x; }
	double Gety() { return y; }
	Point(double a = 0, double b = 0) :x(a), y(b) {}
	Point(const Point& P) :x(P.x), y(P.y) {}
	void Showdata() { cout << "(" << x << "," << y << ")" << endl; }
	void Predata() {}
	~Point() {}
};

class Circle :public Point
{
private:
	double R, S;
public:
	Circle(double a = 0, double b = 0, double r = 0) :Point(a, b), R(r), S(0) {}
	Circle(const Circle& A) :Point(A), R(A.R) {}
	Circle(const Point& A, double r) :Point(A), R(r) {}
	void Predata() { S = PI * R * R; }
	void Showdata() { cout << "Center:(" << Getx() << "," << Gety() << ") " << "Radius:" << R << " " << "Area:" << S << endl; }
	~Circle() {}
};

class Line :public Element
{
private:
	Point a, b;
	double len;
public:
	Line(double x1 = 0, double y1 = 0, double x2 = 0, double y2 = 0) :a(x1, y1), b(x2, y2),len(0) {}
	Line(const Line& L) :a(L.a), b(L.b) {}
	Line(const Point& A, const Point& B) :a(A), b(B) {}
	void Predata() { len = sqrt((a.Getx() - b.Getx()) * (a.Getx() - b.Getx()) + (a.Gety() * b.Gety()) * (a.Gety() * b.Gety())); }
	void Showdata() {
		cout << "Point1:(" << a.Getx() << "," << a.Gety() << ") " << "Point2:(" << b.Getx() << "," << b.Gety() << ") " << "Length:" << len << endl;
	}
	~Line() {}
};

int main()
{
	Element* p;
	Point a(22.0, 33.0);
	Line b(1.2, 2.3, 3.4, 4.5);
	Circle c(0.0, 0.0, 5.0);

	p = &a;
	p->Predata();
	p->Showdata();
	cout << endl;

	p = &b;
	p->Predata();
	p->Showdata();
	cout << endl;

	p = &c;
	p->Predata();
	p->Showdata();

	return 0;
}
