#include<iostream>
#include<string>
using namespace std;

class Node {
public:
	Node* next;
	Node* prev;
	int elem;

	Node() {
		prev = nullptr;
		next = nullptr;
		elem = 0;
	}

	friend class linkedList;
};

class linkedList {
public:
	Node* head;
	Node* tail;
	int size;

	linkedList() {
		head = nullptr;
		tail = nullptr;
		size = 0;
	}

	void print() {
		Node* newNode = head;

		if (size == 0) {
			cout << "empty" << endl;
			return;
		}


		for (int i = 0; i < size; i++) {
			cout << newNode->elem << " ";
			newNode = newNode->next;
		}
		cout << endl;
	}

	void Append(int x) {
		Node* newNode = new Node;
		newNode->elem = x;
		newNode->next = nullptr;

		if (size == 0) {
			head = newNode;
			tail = newNode;
		}
		else {
			tail->next = newNode;
			newNode->prev = tail;
			tail = newNode;
		}
		size++;
		print();
	}
	//삽입 삭제 함수 다시 이해하기
	int Delete(int index) {
		if (index >= this->size) {
			return -1;
		}

		Node* deleteNode = this->head;

		if (index == 0) {
			if (this->size == 1) {
				this->head = nullptr;
				this->tail = nullptr;
			}
			else {
				this->head = deleteNode->next;
				deleteNode->next->prev = nullptr;
			}
		}
		else {
			Node* prevNode = this->head;
			for (int i = 0; i < index; i++) {
				prevNode = deleteNode;
				deleteNode = deleteNode->next;
			}
			prevNode->next = deleteNode->next;
			if (deleteNode == this->tail) {
				this->tail = prevNode;
			}
			else {
				deleteNode->next->prev = prevNode;
			}
		}

		int deleteValue = deleteNode->elem;
		delete deleteNode;
		this->size--;
		return deleteValue;
	}

	void reverse() {
		if (size == 0) {
			cout << "empty" << endl;
			return;
		}
		Node* newNode = tail;

		while(newNode != nullptr){
			cout << newNode->elem << " ";
			newNode = newNode->prev;
		}

		cout << endl;
	}

	void Max() {
		if (size == 0) {
			cout << "empty" << endl;
			return;
		}

		Node* newNode = head;
		int max = 0;
			while (newNode != nullptr) {
				if (newNode->elem > max) {
				max = newNode->elem;
				}	
			newNode = newNode->next;
			}

		cout << max << endl;

	}

};

int main() {
	int order_num;
	cin >> order_num;
	linkedList* li = new linkedList();


	for (int i = 0; i < order_num; i++) {
		string s;
		cin >> s;
		if (s == "Append") {
			int a;
			cin >> a;
			li->Append(a);
		}
		else if (s == "Print") {
			li->print();
		}
		else if (s == "Delete") {
			int a;
			cin >> a;
			cout << li->Delete(a) << endl;
		}
		else if (s == "Print_reverse") {
			li->reverse();
		}
		else if (s == "Max") {
			
			li->Max();
		}
	}
}
