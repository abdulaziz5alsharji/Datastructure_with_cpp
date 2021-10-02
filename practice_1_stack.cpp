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
#include <stack>
using namespace std;

bool ArePair(char open, char close) {
	if (open == '(' && close == ')') return true;
	else if (open == '{' && close == '}') return true;
	else if (open == '[' && close == ']') return true;
	return false;
}
bool AreBalanced(string exp) {
	stack<char> s;
	for (int i = 0; i < exp.length(); i++) {
		if (exp[i] == '(' || exp[i] == '[' || exp[i] == '{') s.push(exp[i]);
		else if (exp[i] == ')' || exp[i] == ']' || exp[i] == '}') {
			if (s.empty() || !ArePair(s.top(), exp[i])) return false;
			else s.pop();
		}
	}
	return s.empty();
}

int main(int argc, char argv[]) {
	string expression = "(5 + 7)";
	if (AreBalanced(expression)) cout << "Balanced !!\n";
	else cout << "Not Balanced\n";
	return 0;
}