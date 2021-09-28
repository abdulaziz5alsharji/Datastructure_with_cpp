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


template <class T>
class LindedList {
	struct Node {
		T data;
		Node* next;
	};
	Node* head;
public:
	LindedList() {
		head = NULL;
	}
	bool isEmpty() { 
		return head == NULL;
	}
	void addNode(T value) {
		Node* newNode = new Node;
		newNode->data = value;
		if (head == NULL) {
			head = newNode;
			newNode->next = NULL;
		}
		else {
			Node* first = head;
			while (first->next != NULL)
			{
				first = first->next;
			}
			first->next = newNode;
			newNode->next = NULL;
		}
	}
	void deleteNode(T value) {
		if (isEmpty()) cout << "The LinkedList Is Empty" << endl;
		else {
			Node* current, * previous;
			current = head;
			previous = head;
			if (current->data == value) {
				head = current->next;
				delete(current);
				return;
			}
			else {
				while (current->data != value) {
					previous = current;
					current = current->next;
					}
				previous->next = current->next;
				delete(current);
			}
		}
	}
	void insert_beg(T value) {
		Node* new_node = new Node;
		new_node->data = value;
		new_node->next = head;
		head = new_node;
	}
	void delete_beg() {
		if (isEmpty()) cout << "The Linked List Is Empty" << endl;
		else {
			Node* first = head;
			head = first->next;
			delete(first);
		}
	}
	void delete_end() {
		if (isEmpty()) cout << "The Linked List Is Empty" << endl;
		else if (head->next == NULL) {
			delete(head);
			head = NULL;
		}
		else {
			Node* current = head;
			while (current->next->next != NULL)
			{
				current = current->next;
			}
			delete(current->next);
			current->next = NULL;
		}
	}
	void display() {
		Node* first = head;
		cout << "[\t";
		while (first != NULL)
		{
			cout << first->data << "\t";
			first = first->next;
		}
		cout << "]" << endl;
	}

};
int main(int argc, char* argv[]) {
	LindedList<int> list;
	list.addNode(1);
	list.addNode(2);
	list.addNode(3);
	list.addNode(4);
	list.deleteNode(4);
	list.insert_beg(10);
	list.delete_beg();
	list.delete_end();
	list.display();
	return 0;
}