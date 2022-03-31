#include<iostream>
using namespace std;


class Node {
private:
	Node* next;
	Node* prev;
	int elem;
public:
	Node() {
		next = NULL;
		prev = NULL;
		elem = 0;
	}

	friend class Iterator;
	friend class Sequence;

};

class Iterator {
private:
	Node* node;
public:
	Iterator(Node* n) {
		node = n;
	}

	Iterator* operator++() {
		node = node->next;
		return this;
	}

	Iterator* operator--() {
		node = node->prev;
		return this;
	}

	friend class Sequence;

};

class Sequence {
private:
	Node* head;
	Node* tail;
	int size;
public:
	Sequence() {
		head = new Node;
		tail = new Node;

		head->next = tail;
		tail->prev = head;
		size = 0;
	}

	Node* begin() {
		return head->next;
	}


	Node* end() {
		return tail;
	}

	void insert(Iterator& p, int e) {
		Node* newNode = new Node;
		newNode->elem = e;

		p.node->prev->next = newNode;
		newNode->prev = p.node->prev;

		newNode->next = p.node;
		p.node->prev = newNode;

		size++;

	}


	void findMax(Iterator &p) {
		int num1 = p.node->prev->elem;
		int num2 = p.node->elem;
		int num3 = p.node->next->elem;


		if (num1 > num2 && num1 > num3) {
			cout << num1 << " ";
		}
		else if (num2 > num1 && num2 > num3) {
			cout << num2 << " ";
		}
		else if (num3 > num1 && num3 > num2) {
			cout << num3 << " ";
		}


	}

};

int main() {
	int order_num;
	int list_num;
	cin >> order_num;

	Sequence seq = Sequence();
	Iterator p = Iterator(seq.begin());

	for (int i = 0; i < order_num; i++) {
		cin >> list_num;

		for (int j = 0; j < list_num; j++) {
			int num;
			cin >> num;
			seq.insert(p, num);
		}


		p = seq.begin();

		for (int j = 0; j < list_num; j++) {
			seq.findMax(p);
			++p;
		}
		cout << endl;

	}
}