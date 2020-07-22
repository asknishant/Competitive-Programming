#include <iostream>
#include <list>

using namespace std;

class Queue {

	list<int> *l;
	int currSize;
	public:
	Queue() {
		l = new list<int>;
		currSize = 0;
	}
	bool isEmpty() {
		return currSize == 0;
	}
	void push(int data) {
		l->push_back(data);
		currSize++;
	}
	void pop() {
		l->pop_back();
		currSize--;
	}
	int front() {
		return l->front();
	}
	void print() {
		for(auto x:*l) {
			cout << x <<"->";
		}
	}
};
int main() {

	Queue q;
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);

	q.print();

	return 0;
}
