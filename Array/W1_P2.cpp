#include<iostream>
#include<string>
using namespace std;


int arr[1000];
int arrSize;

void print() {
	for (int i = 0; i < arrSize; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

void shift() {
	int tmp = arr[arrSize - 1];

	for (int i=arrSize-1; i > 0; i--) {
		arr[i] = arr[i-1];
	}

	arr[0] = tmp;
}

void reverse(int a, int b) {

	for (int i = 0; i < (b-a+1) / 2; i++) {
		int tmp = arr[a+i];
		arr[a+i] = arr[b-i];
		arr[b - i] = tmp;
	}
}

int main() {
	int order_num;
	cin >> order_num >> arrSize;

	for (int i = 0; i < arrSize; i++) {
		int a;
		cin >> a;
		arr[i] = a;
	}
	
	for (int i = 0; i < order_num; i++) {
		string order;
		cin >> order;

		if (order == "print") {
			print();
		}
		else if (order == "shift") {
			int a;
			cin >> a;
			for (int i = 0; i < a; i++) {
				shift();
			}
		}
		else if (order == "reverse") {
			int a, b;
			cin >> a >> b;
			reverse(a, b);
		}
	}
}