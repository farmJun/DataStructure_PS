#include<iostream>
#include<math.h>
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


	int findMin() {

		int min = 1001;

		Node* newNode = head->next;

		for (int i = 0; i < size; i++) {
			if (newNode->elem < min) {
				min = newNode->elem;
				newNode = newNode->next;
			}
			else {
				newNode = newNode->next;
			}
		}
		return min;

	}

	int average() {
		begin();
		int sum = 0;
		Node* newNode = head->next;

		for (int i = 0; i < size; i++) {
			sum += newNode->elem;
			newNode = newNode->next;
		}

		return floor(sum / size);
	}

};

int main() {
	int order_num;
	int list_num;
	cin >> order_num;


	for (int i = 0; i < order_num; i++) {
		Sequence seq = Sequence();
		Iterator p = Iterator(seq.begin());
		cin >> list_num;

		for (int j = 0; j < list_num; j++) {
			int num;
			cin >> num;
			seq.insert(p, num);
		}

		cout << seq.average() << " " << seq.findMin() << endl;

	}
}