#include<iostream>
#include<string>

using namespace std;

class Rectangle {
public:
	Rectangle() {
		cout << "Rectangle\n";
	}
	int area(int w, int h) {
		return w * h;
	}
	~Rectangle() {
		cout << "~Rectangle" << endl;
	}
};
template <class T>
class SmartPtr {
private:
	T* ptr;
public:
	SmartPtr(T* p = NULL) {
		ptr = p;
	}
	~SmartPtr() {
		delete ptr;
	}
	T& operator*() { return *ptr; }
	T* operator->() { return ptr; }
};

int main(int argc, char** argv) {
	//Rectangle rect;
	//cout << rect.area(4, 4) << endl;
	//Rectangle* rect = new Rectangle;
	//cout << rect->area(4, 4) << endl;
	//delete rect;
	//shared_ptr<Rectangle> rect(new Rectangle);
	//cout << rect->area(4, 4) << endl;

	SmartPtr<Rectangle> rect(new Rectangle);
	cout << rect->area(4, 4) << endl;
	return 0;
}