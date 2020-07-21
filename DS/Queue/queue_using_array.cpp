#include <iostream>
using namespace std;

class Queue {
	public:
	int currSize,maxSize;
	int frontt,rear;
	int* arr;

public: 
	Queue(int defaultSize = 5) {
		arr = new int[defaultSize];
		currSize = 0;
		maxSize = defaultSize;
		frontt = 0;
		rear = maxSize - 1;
	}

	bool full() {
		return currSize == maxSize;
	}	
	bool empty() {
		return currSize == 0;
	}

	//pushing element means adding element ar end i.e rear
 	void push(int data) {
		if(!full()) {
			rear = (rear+1)%maxSize;
			arr[rear] = data;
			currSize++;
		}
	}
	int front() {
		return arr[frontt];
	}
	
	//poping element means incrementing frontt by 1.
	void pop() {
		if(!empty()) {
			frontt = (frontt+1)%maxSize;
			currSize--;
		}
	}
	
	~Queue() {
		if(arr!=NULL) {
			delete [] arr;
			arr = NULL;
		}
	}
};

int main() {

	Queue q;

	for(int i=1;i<=5;i++) {
		q.push(i);
	}


	//printing happens from  front to rear.
	while(!q.empty()) {
		cout << q.front() << " ";
		q.pop();
	}
	return 0;

}
