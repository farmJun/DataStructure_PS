#include<iostream>
#include<string>
using namespace std;

int t;

class stack {

private:
	int arr[100]{};
	int size;

public:
	stack() {
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
		if (t == size) {
			cout << "FULL" << endl;
			
		}
		else {
			arr[size] = x;
			size++;
		}
		
	}

	void top() {
		if (size == 0) {
			cout << -1 << endl;
			
		}
		else {
			cout << arr[size - 1] << endl;
		}
		
	}
	//pop에서 top쓰기 전 if문 처리하기
	void pop() {
		if (size == 0) {
			cout << "-1" << endl;
		}
		else {
			top();
			size--;
		}
		
	}
};

int main() {
	int n;
	cin >> t >> n;

	stack* st = new stack();

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
			st->top();
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