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
class LindedListQueue {
private:
	struct Node {
		T items;
		Node* next;
	};
	Node* front;
	Node* rear;
	int lenght;
public:
	LindedListQueue() : front(NULL), rear(NULL), lenght(0) {}
	bool isEmpty(void) { return lenght == 0; }
	
	void enqueue(T element) {
		Node* new_node = new Node;
		new_node->items = element;
		new_node->next = NULL;
		if (isEmpty()) {
			front = rear = new_node;
		}
		else {
			rear->next = new_node;
			rear = new_node;
		}
		lenght++;
	}
	void dequeue() {
		if (isEmpty()) cout << "[!!] Empty Queue, Cannot Dequeue !!\n";
		else if (lenght == 1) {
			delete front;
			rear = NULL;
			lenght = 0;
		}
		else {
			Node* temptr = front;
			front = temptr->next;
			delete temptr;
			lenght--;
		}
	}
	T getFront(void) {
		assert(!isEmpty());
		return front->items;
	}
	void clear(void) {
		Node* current;
		while (front != NULL) {
			current = front;
			front = front->next;
			delete current;
		}
		rear = NULL;
		lenght = 0;
	}
	void display(void) {
		Node* current = front;
		cout << "Itmes in the queue is: [ ";
		while (current != NULL)
		{
			cout << current->items << " ";
			current = current->next;
		}
		cout << "]\n";
	}
	int size() {
		return this->lenght;
	}
};
int main(int argc, char** argv) {
	LindedListQueue<int> qu;
	qu.enqueue(1);
	qu.enqueue(2);
	qu.enqueue(3);
	qu.enqueue(4);
	qu.enqueue(5);
	qu.dequeue();
	printf("The Front Value Is: %d\n", qu.getFront());
	qu.clear();
	cout << qu.size() << endl;
	qu.display();
	return 0;
}