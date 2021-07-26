#include<iostream>
using namespace std;
class Point {
	int x, y;
public:
	Point() {
		x = 0;
		y = 0;
	}
	Point(int xx, int yy) {
		x = xx;
		y = yy;
	}
	int getX() const { return x; }
	int getY() const { return y; }
	void setX(const int new_x) {
		x = new_x;
	}
	void setY(const int new_y) {
		y = new_y;
	}
};
class ListofPoints {
	Point* pts;
	int len;
public:
	ListofPoints() {
		pts = new Point[0];
		len = 0;
	}
	ListofPoints(const Point points[], const int len);
	ListofPoints(const ListofPoints& p);
	~ListofPoints();
	void resize(int newSize);
	void push_back(const Point& pt);
	void insert(const int pos, const Point& p);
	void print();
	void remove(const int pos);
	const int  &getSize() const;
	void clear();
	Point* pointer(const int pos);
	const Point* pointer(const int pos) const;
	const int  size() const {
		return len;
	}

};
class Polygon {
protected:
	ListofPoints listofpoints;
	static int npolygons;
public:
	Polygon() {
		ListofPoints a;
		listofpoints = a;
		++npolygons;
	}
	Polygon(const Point pt[], const int len);
	Polygon(const ListofPoints& listofpoints);
	virtual double area() const = 0;
	static const int getNumofPolygons();
	const int getNumsides()const;
	const ListofPoints* getPoints() const;
};
class Rectangle : public Polygon {
public:
	Rectangle(Point& p1, Point& p2);
	Rectangle(int a, int b, int c, int d);
	virtual double area()const;
};
class Triangle : public Polygon {
public:
	Triangle(Point& p1, Point& p2, Point& p3);
	virtual double area()const;
};