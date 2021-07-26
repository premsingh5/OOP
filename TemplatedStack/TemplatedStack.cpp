// TemplatedStack.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Header.h"
template<typename T>
bool Stack<T>::empty() {
	if (data.size()==0)return true;
	else return false;
}
template<class T>
void Stack<T>::push(const T& item) {
	data.push_back(item);
}
template<class T>
T& Stack<T>::top() {
	if (data.size() != 0)return data.back();
}
template<class T>
void Stack<T>::pop() {
	if(data.size()!=0)data.pop_back();
}

int main()
{
	Stack<int> s;
	s.push(1);
	s.push(2);
	s.push(3);
	Stack<int> b;
	b.push(4);
	b.push(5);
	b.push(6);
	Stack<int> c = s + b;
	cout << c.top();

}
