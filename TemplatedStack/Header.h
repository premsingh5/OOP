#include<iostream>
#include<vector>
using namespace std;
template<typename T>
class Stack;
template<class T>
Stack<T>& operator+ (Stack<T>& a, Stack<T>& b);
template<class T>
class Stack {
	friend Stack<T>& operator+ <>(Stack<T>& a, Stack<T>& b);
	vector<T> data;
public:
	bool empty();
	void push(const T& item);
	T& top();
	void pop();
};
template<class T>
Stack<T>& operator+ (Stack<T>& a, Stack<T>& b) {

	Stack<T> c = a;
	int k = b.data.size();
	for (int i = 0; i < k; i++) {
		c.data.push_back(b.data[i]);
	}
	return c;
}
