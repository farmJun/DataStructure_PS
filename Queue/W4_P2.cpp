#include<iostream>
#include<string>
using namespace std;

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

	void enqueue(int x) {
		Node* newNode = new Node();
		newNode->value = x;

		if (size == 0) {
			head = tail = newNode;
		}
		else {
			tail->next = newNode;
			tail = newNode;
		}
		size++;
	}

   int dequeue() {
	   if (size == 0) {
		   cout << "Empty" << endl;
		   return -1;
	   }
		Node* newNode = head;


		int a= newNode->value;

		head = head->next;
		delete newNode;
		
		size--;
		
		return a;

	}

};


int main() {
	int order;
	cin >> order;

	for (int i = 0; i < order; i++) {

		Queue q1 = Queue();
		Queue q2 = Queue();
		int h1 = 0;
		int h2 = 0;

		int win1 = 0;
		int win2 = 0;

		int round = 0;

		int num;
		cin >> num;

		for (int i = 0; i < num; i++) {
			int a;
			cin >> a;
			q1.enqueue(a);
		}

		for (int i = 0; i < num; i++) {
			int a;
			cin >> a;
			q2.enqueue(a);
		}

		for (int i = 0; i < num; i++) {
			int card1 = q1.dequeue() + h1;
			int card2 = q2.dequeue() + h2;


			if (card1 > card2) {
				round++;
				h1 = card1 - card2;
				h2 = 0;
				win1++;
				cout << "Round" << round << " " << win1 << ":" << win2 << endl;

			}
			else if (card1 < card2) {
				round++;
				h2 = card2 - card1;
				h1 = 0;
				win2++;
				cout << "Round" << round << " " << win1 << ":" << win2 << endl;
			}

			else if (card1 == card2) {
				round++;
				h2 = 0;
				h1 = 0;
				cout << "Round" << round << " " << win1 << ":" << win2 << endl;
			}
		}

		if (win1 > win2) {
			cout << "Winner P1" << endl;
		}
		else if (win1 < win2) {
			cout << "Winner P2" << endl;
		}
		else if (win1 == win2) {
			cout << "Draw" << endl;
		}



	}

}