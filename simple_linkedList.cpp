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

struct Node
{
	int data;
	Node* next;
};
Node* head = NULL;
void insert(int value) {
	Node* new_node, *last;
	new_node = new Node;
	new_node->data = value;
	if (head == NULL) {
		head = new_node;
		new_node->next = NULL;
	}
	else {
		last = head;
		while (last->next != NULL)
		{
			last = last->next;
		}
		last->next = new_node;
		new_node->next = NULL;
	}
}
void insert_beg(int value) {
	Node* new_node = new Node;
	new_node->data = value;
	new_node->next = head;
	head = new_node;
}
void print(void) {
	Node* current;
	if (head == NULL) cout << "Linked List Is Empty." << endl;
	else {
		current = head;
		cout << "[";
		while (current != NULL)
		{
			cout << current->data << "\t";
			current = current->next;
		}
		cout << "]";
	}
}
void deleteNode(int val) {
	Node* current, * previous;
	current = head;
	previous = head;
	if (current->data == val) {
		head = current->next;
		free(current);
		return;
	}
	while (current->data != val) {
		previous = current;
		current = current->next;
	}
	previous->next = current->next;
	free(current);
}
void delete_beg() {
	if (head == NULL) cout << "The Linked List Is Empty..\n";
	else {
		Node* first = head;
		head = first->next;
		delete first;
	}
}
void delete_end() {
	if (head == NULL) cout << "The Linked List Is Empty..\n";
	else if (head->next == NULL) {
		delete head;
		head = NULL;
	}
	else {
		Node* last = head;
		while (last->next->next != NULL) {
			last = last->next;
		}
		delete last->next;
		last->next = NULL;
	}
}
int main(int argc, char* argv[]) {
	insert(5);
	insert(10);
	insert(15);
	insert_beg(1);
	delete_end();
	print();
	return 0;
}