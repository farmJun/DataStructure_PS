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

	void erase(Iterator& p) {
		if (size == 0) {
			cout << "Empty" << endl;
		}
		else {
			Node* newNode = p.node;
			newNode->prev->next = newNode->next;
			newNode->next->prev = newNode->prev;


			p.node = begin();
			size--;
			delete newNode;

		}

	}

	void reversePrint() {
		if (size == 0) {
			cout << "Empty" << endl;
		}
		else {
			Node* newNode = tail->prev;

			while (newNode != head) {
				cout << newNode->elem << " ";
				newNode = newNode->prev;
			}
			cout << endl;

		}
	}

	void find(int x) {
		if (size == 0) {
			cout << "Empty" << endl;
		}
		else {
			Node* newNode = head->next;

			int index = 0;

			while (newNode != tail) {
				if (newNode->elem == x) {
					cout << index << endl;
					return;
				}
				else {
					newNode = newNode->next;
					index++;
				}

			}
			cout << "-1" << endl;
		}
	}

};


int main() {
	int order_num;
	string order;
	cin >> order_num;

	Sequence seq = Sequence();
	Iterator p = Iterator(seq.begin());

	for (int i = 0; i < order_num; i++) {
		cin >> order;

		if (order == "begin") {
			p = seq.begin();
		}
		else if (order == "end") {
			p = seq.end();
		}
		else if (order == "insert") {
			int a;
			cin >> a;
			seq.insert(p, a);
		}
		else if (order == "erase") {
			seq.erase(p);
		}
		else if (order == "++") {
			++p;
		}
		else if (order == "--") {
			--p;
		}
		else if (order == "reversePrint") {
			seq.reversePrint();
		}
		else if (order == "find") {
			int a;
			cin >> a;
			seq.find(a);
		}

	}
}