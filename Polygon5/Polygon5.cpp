// Polygon5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include<iostream>
#include<cmath>
#include "Header.h"
using namespace std;
//ListofPoints member functions


ListofPoints::ListofPoints(const Point arr[], const int lenofarr) {
	Point* temp = pts;
	pts = new Point[lenofarr];
	delete[] temp;
	len = lenofarr;
	for (int i = 0; i < lenofarr; i++) {
		pts[i] = arr[i];
	}
}
ListofPoints::~ListofPoints() {
	delete[] pts;
}
void ListofPoints::print() {
	for (int i = 0; i < len; i++) {
		cout << pts[i].getX() << ' ';
	}
	cout << endl;
}
ListofPoints::ListofPoints(const ListofPoints& p) {
	len  = p.len;
	Point* temp = pts;
	pts = new Point[len];
	delete[] temp;
	for (int i = 0; i < p.len; i++) {
		pts[i] = p.pts[i];
	}
}
void ListofPoints::resize(int newSize) {
	Point* nwpts = new Point[newSize];
	int minSize = (newSize > len ? len : newSize);
	for (int i = 0; i < minSize; i++)
		nwpts[i] = pts[i];
	Point* temp = pts;
	len = newSize;
	pts = nwpts;
	delete[] temp;
}
void ListofPoints::push_back(const Point& pt) {
	resize(len + 1);
	pts[len - 1] = pt;
}
void ListofPoints::insert( int pos, const Point& pt){
	len = len + 1;
	Point* arr1 = new Point[len];
	for (int i = 0; i < pos; i++)arr1[i] = pts[i];
	int i = pos;
	arr1[i] = pt;
	i = pos + 1;
	for (; i < len; i++) {
		arr1[i] = pts[i - 1];
	}
	Point* temp = pts;
	pts = arr1;
	delete[] temp;
}
void ListofPoints::remove(const int pos) {
	if (pos < len) {
		len = len - 1;
		Point* arr = new Point[len];
		int i = 0;
		for (; i < pos; i++) {
			arr[i] = pts[i];
		}
		i = pos;
		for (; i < len; i++)arr[i] = pts[i + 1];
		Point* temp = pts;
		pts = arr;
		delete[] temp;
	}
}
const int &ListofPoints::getSize() const {
	return len;
}
void ListofPoints::clear() {
	Point* temp = pts;
	len = 0;
	pts = new Point[0];
	delete[] temp;
}
Point* ListofPoints::pointer(const int pos) {
	if (pos >= len)return NULL;
	return pts + pos;
}
const Point* ListofPoints::pointer(const int pos) const {
	if (pos >= len)return NULL;
	return pts + pos;
}
//polygon object member function

int Polygon::npolygons = 0;
Polygon::Polygon(const Point pa[], const int Len):listofpoints(pa,Len) {
	++npolygons;
}
Polygon::Polygon(const ListofPoints& existListpoints) : listofpoints(existListpoints) {
	++npolygons;
}
const int Polygon::getNumofPolygons() {
	return npolygons;
}
const int Polygon::getNumsides() const {
	return listofpoints.size();
}
const ListofPoints* Polygon::getPoints()const {
	return &listofpoints;
}
/*Rectangle::Rectangle(Point& c, Point& b){
	Point a(c.getX(), b.getY());
	Point d(b.getX(), c.getY());
	listofpoints.insert(0, a);
	listofpoints.insert(1, b);
	listofpoints.insert(2, d);
	listofpoints.insert(3, c);
}*/
Point ConstructorPoints[4];
Point* updateConstructorPoints(const Point& p1, const Point& p2, const Point& p3, const Point &p4 = Point(0,0)) {
	ConstructorPoints[0] = p1;
	ConstructorPoints[1] = p2;
	ConstructorPoints[2] = p3;
	ConstructorPoints[3] = p4;
	return ConstructorPoints;
}
Rectangle::Rectangle(Point& ll, Point& ur) :Polygon(updateConstructorPoints(ll, Point(ll.getX(), ur.getY()), ur, Point(ur.getX(), ll.getY())), 4)
{}
Rectangle::Rectangle(int llx, int lly, int urx, int ury):Polygon(updateConstructorPoints(Point(llx,lly), Point(llx,ury), Point(urx,ury), Point(urx, lly)), 4)
{}
double Rectangle::area () const {
	double l = listofpoints.pointer(1)->getY()-listofpoints.pointer(0)->getY();
	double b = listofpoints.pointer(2)->getX() - listofpoints.pointer(1)->getX();
	return abs(l * b);
}
Point TrianglePoints[3];
Point* TrianglePointsConstructor(Point& p1, Point& p2, Point& p3) {
	TrianglePoints[0] = p1;
	TrianglePoints[1] = p2;
	TrianglePoints[2] = p3;
	return TrianglePoints;
}
Triangle::Triangle(Point& p1,Point& p2,Point&p3):Polygon(TrianglePointsConstructor(p1,p2,p3),3){}
double Triangle::area()const {
	double a = sqrt(pow((listofpoints.pointer(1)->getX() - listofpoints.pointer(0)->getX()),2)+ pow((listofpoints.pointer(1)->getY() - listofpoints.pointer(0)->getY()),2));
	double b = sqrt(pow((listofpoints.pointer(2)->getX() - listofpoints.pointer(1)->getX()), 2) + pow((listofpoints.pointer(2)->getY() - listofpoints.pointer(1)->getY()), 2));
	double c = sqrt(pow((listofpoints.pointer(0)->getX() - listofpoints.pointer(2)->getX()), 2) + pow((listofpoints.pointer(0)->getY() - listofpoints.pointer(2)->getY()), 2));
	double s = (a + b + c) / 2;
	return sqrt(s * (s - a) * (s - b) * (s - c));
}





int main() {
	/*Point arr[5] = { Point(1,2),Point(2,3),Point(3,4),Point(4,5),Point(5,6) };
	ListofPoints list(arr, 5);
	ListofPoints list1 = list;
	list1.print();
	list1.resize(3);
	list1.print();
	Point p(10, 10);
	list1.push_back(p);
	list1.print();
	list1.insert(2, p);
	list1.print();
	list1.remove(4);
	list1.print();
	//int k = list1.getSize();*/
	//Polygon polygon(arr,5);
	Point p1(1, 2),p2(5,4);
	Rectangle rect(p1, p2);
	cout << rect.area();

}
