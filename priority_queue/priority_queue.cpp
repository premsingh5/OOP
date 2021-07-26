// priority_queue.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Header.h"
using namespace std;
template<class T1>
class compare {
    bool reverse;
public:
    compare() {
        reverse = false;
    }
    compare(const bool& revparam) {
        reverse = revparam;
    }
    bool operator()(const T1& a, const T1& b)const {
        if (reverse)return(a > b);
        else return (a < b);
    }
};



int main()
{
    //typedef PriorityQueue<int,vector<int>,compare<int>> prpq;
    //prpq p(vector<int>(),compare<int>(true));
    //int k1 = p.size();
    long long int myints[] = { LLONG_MAX,LLONG_MAX,LLONG_MAX,LLONG_MAX};
    vector<long long int> v(myints, myints + 4);
    //PriorityQueue<long long int,vector<long long int>,compare<long long int>> p(v.begin(),v.end(),vector<long long int>(),compare<long long int>(true));
    PriorityQueue<long long int, vector<long long int>> p(v.begin(), v.end(), vector<long long int>());
    //int l = p.extractMaxPriority();
    // 
   // cout << k1;
    //vector<int> k;
    //const vector<int>& b = vector<int>();
    //vector<int> c = b;
    cout << p.size() << endl;
    cout << p.extractMaxPriority()<<endl;
    cout << p.size()<<endl;
    p.insert(15);
    p.insert(9);
    cout << p.size() << endl;
    cout << p.extractMaxPriority() << endl;
    cout << p.size() << endl;
    cout << p.extractMaxPriority() << endl;
    p.Delete(1);
    cout << p.extractMaxPriority() << endl;
    p.insert(100);
    p.insert(150);
    p.insert(120);
    cout << p.size()<<endl;
    p.decreaseKey(50, 4);
    cout << p.extractMaxPriority();
    cout << p.empty();

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
