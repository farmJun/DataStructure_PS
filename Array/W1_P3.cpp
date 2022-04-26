#include<iostream>
#include<string>
using namespace std;

int arr[1000];
int n;

void add(int a, int b) {

	for (int i = n - 1; i > a; i--) {
		arr[i] = arr[i - 1];
	}

	arr[a] = b;
}

void remove(int a) {
	// i < n-1 ÀÌ¶û °°À½
	for (int i = a; i <= n - 2; i++) {
		arr[i] = arr[i + 1];
	}
	arr[n - 1] = 0;
}

void set(int a, int b) {
	arr[a] = b;
}

void print() {
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

int find(int x) {
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] == x) {
			cnt++;
		}
	}
	return cnt;
}

int main() {
	int order_num;
	cin >> order_num >> n;

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
			cin >> a >> b;
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