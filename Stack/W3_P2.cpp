#include <iostream>
using namespace std;

class arrayStack {
private:
	char* arr;
	int capacity; // 스택의 최대 크기
	int topIndex;

public:
	arrayStack(int capacity) {
		this->capacity = capacity;
		arr = new char[capacity];
		topIndex = -1;
	};

	bool empty() {
		return (topIndex == -1);
	};

	// 스택의 크기를 반환
	int size() {
		return topIndex + 1; // topIndex가 -1이므로
	};

	// 스택의 top에 저장된 원소를 반환
	char top() {
		return arr[topIndex]; // topIndex의 원소 반환
	};

	// 스택에 새로운 원소를 삽입
	void push(char data) {
		arr[++topIndex] = data; // topIndex 1 증가시키고 이 위치에 원소 삽입
	};

	// 스택의 top에 저장된 원소를 삭제
	void pop() {
		cout << arr[topIndex];
		topIndex--; // topIndex 1 감소
	};
};

int main() {
	int n;
	cin >> n;

	for (int k = 0; k < n; k++) {
		string data;
		cin >> data;
		arrayStack as(data.size());

		for (int i = 0; i < data.size(); i++) {
			if(data[i] >= '1' && data[i] <= '9') {
				cout << data[i];
			}
			else if (data[i] == '*' || data[i] == '/') {
				while (!(as.empty() || as.top() == '+' || as.top() == '-')) {
					as.pop();
				}
				as.push(data[i]);
			}
			else if (data[i] == '+' || data[i] == '-') {
				while (!as.empty()) {
					as.pop();
				}
				as.push(data[i]);
			}
		}
		while (!as.empty()) {
			as.pop();
		}
		cout << endl;

	}
}