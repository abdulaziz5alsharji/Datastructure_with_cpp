#include<iostream>
#include<string>
#include <stdio.h>
#include <cmath>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <tuple>
#include <map>
#include <vector>
#include <stack>
#include <assert.h>
using namespace std;

template <class T>
class Queue {
	int rear;
	int front;
	T* arr;
	int length;
	int MAX_LENGTH;
public:
	Queue(int size) {
		if (size <= 0) MAX_LENGTH = 100;
		else MAX_LENGTH = size;
		arr = new T[size];
		front = 0;
		rear = MAX_LENGTH - 1;
		length = 0;
	}
	bool isEmpty() { return length == 0; }
	bool isFull() { return length == MAX_LENGTH; }
	void put(T value) {
		if (isFull()) {
			cout << "The Queue Is Full !!" << endl;
		}
		else {
			rear = (rear + 1) % MAX_LENGTH;
			arr[rear] = value;
			length++;

		}
	}
	void pop() {
		if (isEmpty()) {
			cout << "The Queue Is Empty !!" << endl;
		}
		else {
			front = (front + 1) % MAX_LENGTH;
			length++;
		}
	}
	int getFront() {
		assert(!isEmpty());
		return arr[front];
	}
	int getRear() {
		assert(!isEmpty());
		return arr[rear];
	}
	void print() {
		if (isEmpty()) {
			cout << "The Queue Is Empty !!" << endl;
		}
		else {
			cout << "[";
			for (size_t i = front; i != rear; i = (i + 1) % MAX_LENGTH) {
				cout << arr[i] << " ";
			}
			cout << arr[rear] <<  "]\n";
		}

	}
};
int main(int argc, char* argv[]) {
	Queue<int> q1(3);
	q1.put(1);
	q1.put(2);
	q1.put(3);
	q1.print();
	q1.pop();
	cout << q1.getFront() << endl;
	cout << q1.getRear() << endl;
	return 0;
}