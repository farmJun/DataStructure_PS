#include <iostream>
using namespace std;

struct node {
	int data;
	node* next;
	node* prev;
};

class DoublyLinkedList {
public:
	DoublyLinkedList() {
		head = NULL;
		tail = NULL;
		listSize = 0;
	};

	bool empty() {
		if (listSize == 0) return true;
		else return false;
	};

	void append(int data) {
		node* newNode = new node;
		newNode->data = data;
		newNode->next = NULL;
		newNode->prev = NULL;

		if (empty()) {
			head = tail = newNode;
		}
		else {
			node* old = tail;
			tail->next = newNode;
			tail = newNode;
			tail->prev = old;
		}
		listSize++;
		print();
	};

	void deletion(int idx) {
		if (empty() || idx < 0 || idx >= listSize) {
			cout << -1 << endl;
			return;
		}

		node* curNode = head; // 삭제할 노드
		if (idx == 0) {
			if (listSize == 1) {
				head = tail = NULL;
			}
			else {
				head = head->next;
				head->prev = NULL;
			}
		}
		else {
			node* preNode = head; // 삭제할 노드의 바로 앞 노드
			for (int i = 0; i < idx; i++) {
				preNode = curNode;
				curNode = curNode->next;
			}
			preNode->next = curNode->next;
			if (curNode == tail) {
				tail = preNode;
			}
			else {
				node* nextNode = curNode->next;
				nextNode->prev = curNode->prev;

			}
		}
		cout << curNode->data << endl;
		delete curNode;
		listSize--;
	};

	void print() {
		if (empty()) {
			cout << "empty" << endl;
			return;
		}

		node* curNode = head;
		while (curNode != NULL) {
			cout << curNode->data << " ";
			curNode = curNode->next;
		}
		cout << endl;
	};

	void print_reverse() {
		if (empty()) {
			cout << "empty" << endl;
			return;
		}

		node* curNode = tail;
		while (curNode != NULL) {
			cout << curNode->data << " ";
			curNode = curNode->prev;
		}
		cout << endl;
	};

	void update(int x, int y) {
		if (empty()) {
			cout << "empty" << endl;
			return;
		}

		node* curNode = head;
		bool isUpdated = false;
		while (curNode != NULL) {
			int target = curNode->data;
			if (target == x) {
				curNode->data = y;
				isUpdated = true;
			}
			curNode = curNode->next;
		}

		if (isUpdated) {
			print();
		}
		else {
			cout << "Not found" << endl;
		}
	};

private:
	node* head;
	node* tail;
	int listSize;
};

int main() {
	int num;
	cin >> num;

	DoublyLinkedList dl;

	for (int i = 0; i < num; i++) {
		string order;
		int n1, n2;
		cin >> order;

		if (order == "Append") {
			cin >> n1;
			dl.append(n1);
		}
		else if (order == "Delete") {
			cin >> n1;
			dl.deletion(n1);
		}
		else if (order == "Print") {
			dl.print();
		}
		else if (order == "Print_reverse") {
			dl.print_reverse();
		}
		else if (order == "Update") {
			cin >> n1 >> n2;
			dl.update(n1, n2);
		}
	}
}