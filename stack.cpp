#include<iostream>
#include<string>
#include <numbers>
#include <stdio.h>
#include <cmath>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int MAX_SIZE = 100;
template <class t>
class stack {
	int top;
	t item[MAX_SIZE];
public:
	stack(): top(-1){}
	bool isEmpty() {
		return top < 0;
	}
	void push(t val) {
		if (top >= MAX_SIZE - 1) cout << "STACK FULL ON PUSH" << endl;
		else {
			top++;
			item[top] = val;
		}
	}
	void pop(t& Element) {
		if (isEmpty()) cout << "STACK EMPTY ON POP" << endl;
		else {
			Element = item[top];
			top--;
		}
	}

	void pop() {
		if (isEmpty()) cout << "STACK EMPTY ON POP" << endl;
		else {
			top--;
		}
	}

	void getTop(t& stack_top) {
		if (isEmpty()) cout << "STACK EMPTY ON GET TOP" << endl;
		else {
			stack_top = item[top];
			cout << stack_top << endl;
		}
	}
	void print() {
		cout << "[";
		for (int i = top; i >= 0; i--) {
			cout << item[i] << ",";
		}
		cout << "]" << endl;
	}
};



int main(int argc, char* argv[]) {
	stack<int> numbers;
	int top;
	cout << numbers.isEmpty() << endl;
	numbers.push(5);
	numbers.push(4);
	numbers.push(3);
	numbers.push(2);
	//numbers.pop();
	numbers.push(1);
	numbers.getTop(top);
	cout << numbers.isEmpty() << endl;
	numbers.print();
	return 0;
}