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
class DoublyLinkedList {
private:
	struct Node {
		Node* prev;
		T item;
		Node* next;
	};
	Node* first, * last;
	int lenght;
public:
	DoublyLinkedList();
	bool isEmpty();
	void destroy();
	void insertLast(T vla);
	void insertFirst(T val);
	void insertAt(int pos, T val);
	void removeFirst();
	void removeLast();
	void removeAt(int pos);
	void remove(T val);
	void display();
	void reverse_display();


};
template<class T>
DoublyLinkedList<T>::DoublyLinkedList() {
	this->first = this->last = NULL;
	this->lenght = 0;
}
template<class T>
bool DoublyLinkedList<T>::isEmpty() {
	return (this->lenght == 0); // this->first == NULL
}
template<class T>
void DoublyLinkedList<T>::destroy() {
	if (isEmpty()) return;
	Node* temp;
	while (first != NULL) {
		temp = first;
		first = first->next;
		delete temp;
	}
	last = NULL;
	lenght = 0;
}

template<class T>
void DoublyLinkedList<T>::insertLast(T val) {
	Node* new_node = new Node;
	new_node->item = val;
	if (isEmpty()) {
		new_node->next = new_node->prev = NULL;
		first = last = new_node;
	}
	else {
		new_node->next = NULL;
		new_node->prev = last;
		last->next = new_node;
		last = new_node;
	}
	lenght++;
}

template<class T>
void DoublyLinkedList<T>::insertFirst(T val) {
	Node* new_node = new Node;
	new_node->item = val;
	if (isEmpty()) {
		new_node->next = new_node->prev = NULL;
		first = last = new_node;
	}
	else {
		new_node->next = first;
		new_node->prev = NULL;
		first->prev = new_node;
		first = new_node;
	}
	lenght++;
}

template<class T>
void DoublyLinkedList<T>::insertAt(int pos, T val) {
	if (pos < 0 || pos > lenght)
		cout << "Out Of Range!!\n";
	else {
		if (pos == lenght) 
			insertLast(val);
		else if (pos == 0) 
			insertFirst(val);
		else {
			Node* new_node = new Node;
			new_node->item = val;
			Node* current = first;
			for (int i = 0; i < pos; i++) {
				current = current->next;
			}
			new_node->next = current;
			new_node->prev = current->prev;
			current->prev->next = new_node;
			current->prev = new_node;
			lenght++;
		}
	}

}
template<class T>
void DoublyLinkedList<T>::display() {
	if (isEmpty()) cout << "[]" << endl;
	else {
		Node* current = first;
		cout << "[";
		while (current != NULL) {
			cout << current->item <<", ";
			current = current->next;
		}
		cout << "]" << endl;
	}
}

template<class T>
void DoublyLinkedList<T>::removeFirst() {
	if (isEmpty())
		cout << "The List Is Emtpy !!" << endl;
	else if (lenght == 1) {
		delete first;
		first = last = NULL;
		lenght--;
	}
	else {
		Node* current = first;
		first = first->next;
		first->prev = NULL;
		delete current;
		lenght--;
	}
}

template<class T>
void DoublyLinkedList<T>::removeLast() {
	if (isEmpty())
		cout << "The List Is Emtpy !!" << endl;
	else if (lenght == 1) {
		delete first;
		first = last = NULL;
		lenght--;
	}
	else {
		Node* current = last;
		last = last->prev;
		last->next = NULL;
		delete current;
		lenght--;
	}
}

template<class T>
void DoublyLinkedList<T>::removeAt(int pos) {
	if (pos < 0 || pos >= lenght)
		cout << "Out Of Range !!\n";
	else {
		if (pos == 0)
			removeFirst();
		else if (pos == (lenght - 1))
			removeLast();
		else {
			Node* current = first;
			for (int i = 0; i < pos; i++) {
				current = current->next;
			}
			current->prev->next = current->next;
			current->next->prev = current->prev;
			delete current;
		}
		lenght--;
	}
}

template<class T>
void DoublyLinkedList<T>::remove(T val) {
	if (isEmpty())
		cout << "The List Is Emtpy !!" << endl;
	else {
		if (first->item == val)
			removeFirst();
		else if (last->item == val) 
			removeLast();
		else {
			Node* current = first->next;
			while (current != NULL) {
				if (current->item == val) {
					break;
				}
				current = current->next;
			}
			if (current == NULL)
				cout << "This Item Is Not Exist in List !!\n";
			else {
				current->prev->next = current->next;
				current->next->prev = current->prev;
				delete current;
				lenght--;
			}
		}
	}
}
template<class T>
void DoublyLinkedList<T>::reverse_display() {
	if (isEmpty()) cout << "[]" << endl;
	else {
		Node* current = last;
		cout << "[";
		while (current != NULL) {
			cout << current->item << ", ";
			current = current->prev;
		}
		cout << "]" << endl;
	}
}
int main(int argc, char** argv) {
	DoublyLinkedList<string> names;
	//cout << names.isEmpty() << endl;
	names.insertLast("Ali");
	names.insertLast("Faisal");
	names.insertLast("Abdulaziz");
	names.insertAt(2, "Osama");
	names.removeFirst();
	names.removeLast();
	//names.removeAt(1);
	names.remove("Faisal");
	names.display();
	//names.destroy();
	//names.reverse_display();
	return 0;
}