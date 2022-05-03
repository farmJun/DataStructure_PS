#include<iostream>
#include<string>
using namespace std;

int qSize;

class Node {
public:
	Node* next;
	int value;

	Node() {
		next = nullptr;
		value = 0;
	}

	friend class Queue;
};

class Queue {
public:
	Node* head;
	Node* tail;
	int size;

	Queue() {
		head = nullptr;
		tail = nullptr;
		size = 0;
	}

	void Size() {
	
		cout << size << endl;
	}

	void isEmpty() {
		if (size == 0) {
			cout << "True" << endl;
		}
		else {
			cout << "False" << endl;
		}
	}

	void front() {
		if (size == 0) {
			cout << "Empty" << endl;
			return;
		}

		cout << head->value << endl;


	}

	void rear() {
		if (size == 0) {
			cout << "Empty" << endl;
			return;
		}

		cout << tail->value << endl;

	}

	void enqueue(int x) {
		Node* newNode = new Node();
		newNode->value = x;
		// >가 아니라 ==
		if (size == qSize) {
			cout << "FULL" << endl;
			return;
		}

		if (size == 0) {
			head = tail = newNode;
		}
		else {
			tail->next = newNode;
			tail = newNode;
		}
		size++;
	}

	void dequeue() {
		if (size == 0) {
			cout << "Empty" << endl;
			return;
		}

		Node* newNode = head;
		cout << newNode->value << endl;

		if (size == 1) {
			head = tail = nullptr;
		}
		else {
			//다시 이해하기!!
			head = newNode->next;

		}

		size--;
		delete newNode;
	}

};

int main() {
	int order_num;
	cin >> qSize >> order_num;

	Queue q = Queue();

	for (int i = 0; i < order_num; i++) {
		string order;
		cin >> order;

		if (order == "size") {
			q.Size();
		}
		else if (order == "isEmpty") {
			q.isEmpty();
		}
		else if (order == "front") {
			q.front();
		}
		else if (order == "rear") {
			q.rear();
		}
		else if (order == "enqueue") {
			int a;
			cin >> a;

			q.enqueue(a);
		}
		else if (order == "dequeue") {
			q.dequeue();
		}


	}
}