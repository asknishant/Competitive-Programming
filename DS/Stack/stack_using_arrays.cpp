#include <iostream>
#define MAX 100005
using namespace std;

class Stack{

	int top;
	int stack[MAX];
	
	public:

	Stack() {top = -1;}
	void push(int x) {
		
		if(top >= (MAX-1)) {
			cout << "Stack OVerflow";
		} else {
			stack[++top] = x;
		}
	}
	int pop() {
		if(top < 0) {
			cout << "Stack underflow";
			return 0;
		}
		else {
			int x = stack[top--];
			return x;
		}
	}
	int peek() {
		if(top < 0) {
			cout << "Stack is Empty";
		} else {
			return stack[top];
		}
	}

	bool isEmpty() {
		return top < 0;
	}
};

int main() {

	Stack s;
	s.push(10);
	s.push(20);
	s.push(30);

	cout << s.pop();
	cout << s.pop();
	return 0;
}
