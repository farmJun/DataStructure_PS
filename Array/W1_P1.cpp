#include<iostream>
#include<string>
using namespace std;

int arr[1000];
int arrSize;


void add(int a, int b) {

	for (int i = arrSize - 1; i > a; i--) {
		arr[i ] = arr[i-1];
	}

	arr[a] = b;
}

void remove(int x) {
	// 범위 잘 생각하기
	for (int i = x; i < arrSize - 1; i++) {
		arr[i] = arr[i + 1];
	}
	arr[arrSize - 1] = 0;
}

void set(int x, int z) {
	arr[x] = z;
}

void print() {
	for (int i = 0; i < arrSize; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

int find(int x) {
	
	for (int i = 0; i < arrSize; i++) {
		if (x == arr[i]) {
			return i;
		}
	}

	return -1;
}

int main() {
	int order_num;
	cin >> order_num >> arrSize;

	for (int i = 0; i < order_num; i++) {
		string order;
		cin >> order;
		if (order == "add") {
			int a, b;
			cin >> a >> b;
			add(a, b);
		}
		else if (order == "remove") {
			int a;
			cin >> a;
			remove(a);
		}
		else if (order == "set") {
			int a, b;
			cin >> a >>b;
			set(a, b);
		}
		else if (order == "print") {
			print();
		}
		else if (order == "find") {
			int a;
			cin >> a;
			cout << find(a) << endl;
		}
	}
}