#include<iostream>
#include<string>
#include <numbers>
#include <stdio.h>
#include <cmath>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <tuple>
#include <map>
#include <vector>
using namespace std;


template<class T>
class LinkedList {
private:
	struct Node
	{
		T item;
		Node* next;
	};
	Node* first;
	Node* last;
	int lenght;
public:
	LinkedList() {
		first = last = NULL;
		lenght = 0;
	}
	bool isEmpty() {
		return lenght == 0;
	}
	void insertFirst(T element) {
		Node* newNode = new Node;
		newNode->item = element;
		if (isEmpty()) {
			first = last = newNode;
			newNode->next = NULL;
		}
		else {
			newNode->next = first;
			first = newNode;
		}
		lenght++;
	}
	void insertLast(T element) {
		Node* newNode = new Node;
		newNode->item = element;
		if (isEmpty()) {
			first = last = newNode;
			newNode->next = NULL;
		}
		else {
			last->next = newNode;
			newNode->next = NULL;
			last = newNode;
		}
		lenght++;
	}
	void insertAtPos(int pos, T element) {
		if (pos < 0 || pos > lenght) cout << "Out Of The Range!!\n";
		else {
			if (pos == 0) {
				insertFirst(element);
			}
			else if (pos == lenght) {
				insertLast(element);
			}
			else {
				Node* newNode = new Node;
				newNode->item = element;
				Node* current = first;
				for (int i = 1; i < pos; i++) {
					current = current->next;
				}
				newNode->next = current->next;
				current->next = newNode;
				lenght++;
			}
		}

	}

	void removeFirst() {
		if (lenght == 0) {
			cout << "Empty List Cannot Remove" << endl;
		}
		else if (lenght == 1) {
			delete first;
			last = first = NULL;
			lenght--;
		}
		else {
			Node* current = first;
			first = first->next;
			delete current;
			lenght--;
		}
	}
	void removeLast() {
		if (lenght == 0) {
			cout << "Empty List Cannot Remove" << endl;
		}
		else if (lenght == 1) {
			delete last;
			last = first = NULL;
			lenght--;
		}
		else {
			Node* current = first;
			while (current->next != last) {
				current = current->next;
			}
			delete last;
			last = current;
			last->next = NULL;
			lenght--;
		}
	}
	void remove(T element) {
		if (isEmpty()) {
			cout << "Empty List Cannot Remove" << endl;
		}
		else if (first->item == element) {
			removeFirst();
		}
		else if (last->item == element) {
			removeLast();
		}
		else {
			Node* current = first->next, * previous = first;
			while (current->item != element) {
				previous = current;
				current = current->next;
				if (current == NULL) {
					break;
				}
			}
			if (current == NULL) {
				cout << "The Element Is Not Found\n";
			}
			else {
				previous->next = current->next;
				delete current;
				lenght--;
			}
		}
	}
	void reverse() {
		Node* prev, * next, * curr;
		prev = NULL;
		curr = first;
		next = curr->next;
		while (next != NULL) {
			next = curr->next;
			curr->next = prev;
			prev = curr;
			curr = next;
		}
		first = prev;
	}
	int search(T elemnt) {
		if (first->item == elemnt) {
			return 0;
		}
		else if (last->item == elemnt) {
			return lenght - 1;
		}
		else {
			int index = 0;
			Node* current = first;
			while (current->item != elemnt) {
				current = current->next;
				index++;
				if (current == NULL) {
					return -1;
				}
			}
			return index;
		}
	}
	void print() {
		Node* current = first;
		cout << "[";
		while (current != NULL)
		{
			cout << current->item << " ";
			current = current->next;
		}
		cout << "]";
	}
};


int main(int argc, char** argv) {
	LinkedList<int> lst;
	lst.insertLast(1);
	lst.insertLast(2);
	lst.insertFirst(0);
	lst.insertLast(3);
	lst.insertAtPos(0, -1);
	cout << lst.search(2) << endl;
	lst.print();
	return 0;
}