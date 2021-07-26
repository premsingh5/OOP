#include<iostream>
#include<vector>
using namespace std;
template <class T, class Container = vector<T>, class Compare = less<typename Container::value_type>>
class PriorityQueue {
private:
	Container container;
	Compare compare;
	//unordered_map<T,int> positions;
	int len;
public:
	PriorityQueue(const Container& cont = Container(), const Compare& comp = Compare()) {
		container = cont;
		compare = comp;
		//positions = Map();
		len = container.size();
	};
	void swap(int a, int b) {
		T temp = container[a];
		container[a] = container[b];
		container[b] = temp;
		//positions[container[b]].second = a;
		//positions[container[a]].second = b;

	}
	void heapify(int pos) {
			int largest = pos;
			int leftchild = 2 * pos, rightchild = 2 * pos + 1;
			if (leftchild <= len && compare(container[leftchild - 1], container[pos - 1]))largest = leftchild;
			if (rightchild <= len && compare(container[rightchild - 1], container[largest - 1]))largest = rightchild;
			if (largest != pos) {
				swap(largest - 1, pos - 1);
				heapify(largest);
			}
	}
	void heapifyup(int pos) {
		//cout << pos << "heapifup" << endl;
		if (pos > 1 && pos<= container.size()) {
			int parent = (int)(pos / 2);
			//cout << parent << "		" << "parent:" << pos << endl;
			if (compare(container[pos - 1], container[parent-1])) {
				swap(parent-1, pos-1);
				heapifyup(parent);
			}
		}
	}
	void buildMaxHeap() {
		for (int i = (int)(len / 2); i >= 1; i--) {
			heapify(i);
		}
	}
	template<class inputIterator>
	PriorityQueue(inputIterator first, inputIterator last, const Container& cont = Container(), const Compare& comp = Compare()) {
		container = cont;
		compare = comp;
		inputIterator it = first;
		int i = 0;
		while (it != last) {
			container.push_back(*it);
			//positions.insert(make_pair((*it),i));
			i = i + 1;
			++it;
		}
		len = container.size();
		buildMaxHeap();
	}
	void insert(T node) {
		container.push_back(node);
		len = container.size();
		heapifyup(len);
	}
	T extractMaxPriority() {
		swap(0, len - 1);
		T res = container[len - 1];
		container.pop_back();
		len = container.size();
		heapify(1);
		return res;
	}
	void Delete(int pos) {
		if (pos <= container.size()) {
			bool flag;
			if (compare(container[len - 1], container[pos - 1]))flag = true;
			swap(pos - 1, len - 1);
			container.pop_back();
			len = container.size();
			if (flag)heapifyup(pos);
			else heapify(pos);
		}
	}
	void decreaseKey(T val,int pos) {
		cout << "starting decreaseKey" << endl;
		if (pos <= container.size()) {
			container[pos - 1] = val;
			cout << "value updated" << endl;
			heapifyup(pos);
		}
	}
	const int size() const{
		return len;
	}
	const bool empty() const {
		return (len == 0);
	}
	int fun() {
		return 5;
	}
};
