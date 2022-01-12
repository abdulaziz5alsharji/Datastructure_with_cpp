#include<iostream>
#include<string>

using namespace std;

template <class T>
class arrayList {
	T* arr;
	int max_size;
	int lenght;
public:
	arrayList(int s = 10) {
		if (s < 0)
			max_size = 10;
		else
			max_size = s;
		lenght = 0;
		arr = new T[max_size];
	}
	bool isEmpty(void) {
		return lenght == 0;
	}
	bool isFull() {
		return lenght == max_size;
	}
	int getSize() {
		return lenght;
	}
	void print() { 
		cout << "[ ";
		for (int i = 0; i < lenght; i++) {
			cout << arr[i] << " ";
		}
		cout << "]\n";
	}
	void insertAtpos(int pos, T element) {
		if (isFull())
			cout << "List Full....!" << endl;
		else if (pos < 0 || pos > lenght)
			cout << "Out Of Range...!" << endl;
		else {
			for (int i = lenght; i > pos; i--)
				arr[i] = arr[i - 1];

			arr[pos] = element;
			lenght++;
		}
	}
	void insertAtEnd(T element) {
		if (isFull())
			cout << "List Full....!" << endl;
		else
			arr[lenght] = element;
		lenght++;
	}
	int search(T element) {
		for (int i = 0; i < lenght; i++) {
			if (arr[i] == element)
				return i;
			return -1;
		}
	}
	void insertNoDuplicate(T element) {
		if (search(element) == -1)
			insertAtEnd(element);
		else
			cout << "The Element Is There...!\n";
	}
	void updateAt(int pos, T element) {
		if (pos < 0 || pos >= lenght)
			cout << "Out Of Range...!\n";
		else
			arr[pos] = element;
	}
	T getElement(int pos) {
		if (pos < 0 || pos >= lenght)
			cout << "Out Of Range...!\n";
		else
			return arr[pos];
	}
	~arrayList() {
		delete[] arr;
	}
	void removeAtPos(int pos) {
		if (isEmpty())
			cout << "List Is Empyt...!\n";
		else if (pos < 0 || pos > lenght)
			cout << "Out Of Range...!\n";
		else {
			for (int i = pos; i < lenght; i++) {
				arr[i] = arr[i + 1];
			}
		}
		lenght--;
	}
};
int main(int argc, char** argv) {
	arrayList<int> list(10);
	list.insertAtEnd(1);
	list.insertAtEnd(2);
	list.insertAtEnd(3);
	list.insertAtEnd(4);
	list.insertAtEnd(5);
	list.insertAtpos(0, 0);
	list.removeAtPos(1);
	list.print();
	return 0;
}