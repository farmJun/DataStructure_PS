#include<iostream>
#include<string>
using namespace std;

class Node {
	Node* next;
	int value;	

	friend class Stack;
};

class Stack {
public:
	Node* top;
	int size;

	Stack() {
		top = nullptr;
		size = 0;
	}

	void Size() {
		cout << size << endl;
	}

	void empty() {
		if (size == 0) {
			cout << 1;
		}
		else {
			cout << 0;
		}
		cout << endl;
	}

	void push(int x) {
		Node* newNode = new Node();
		newNode->value = x;
		newNode->next = top;//head를 top으로 하는 스택 -> 삽입 삭제 둘다 빠름
		top = newNode;
		size++ ;
	}

	void pop() {
		if (size == 0) {
			cout << -1 << endl;
		}
		else {
			Node* newNode = top;
			top = top->next;
			cout << newNode->value << endl;
			delete newNode;
			size--;
		}

	}
	
	void Top() {
		if (size == 0) {
			cout << -1 << endl;
		}
		else {
			cout << top -> value << endl;
		}

	}


};

int main() {
	int n;
	cin  >> n;

	Stack* st = new Stack();

	for (int i = 0; i < n; i++) {
		string order;
		cin >> order;

		if (order == "size") {
			st->Size();
		}
		else if (order == "empty") {
			st->empty();
		}
		else if (order == "top") {
			st->Top();
		}
		else if (order == "push") {
			int a;
			cin >> a;

			st->push(a);

		}
		else if (order == "pop") {
			st->pop();
		}
	}
}