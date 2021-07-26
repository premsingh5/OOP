// UnionFind.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<chrono>
#include<ctime>
#include "Header.h";
using namespace std;
int main()
{
	using namespace std::chrono;
	high_resolution_clock::time_point t1 = high_resolution_clock::now();
	UnionFind uf(10);
	cout << uf.getSize()<<endl;
	uf.Union(3, 4);
	uf.Union(4, 9);
	uf.Union(8, 0);
	uf.Union(2, 3);
	uf.Union(5, 6);
	uf.Union(5, 9);
	uf.Union(7, 3);

	//cout << uf.find(8, 3) << endl;
	cout << uf.subtreeSize(8)<<" "<<uf.subtreeSize(3) << endl;





	high_resolution_clock::time_point t2 = high_resolution_clock::now();
	duration<double> time_span = duration_cast<duration<double>>(t2 - t1);
	cout << "time took:" << time_span.count() << endl;

}
