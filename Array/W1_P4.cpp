#include<iostream>
#include<string>
using namespace std;

int arr[1000];
int n;

void print() {
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

void shift() {

	int tmp = arr[0];

	for (int i = 0; i <= n-2; i ++) {
		arr[i] = arr[i + 1];
	}
	arr[n-1] = tmp;
}

void reverse(int a, int b) {

	for (int i = 0; i < (b-a + 1) / 2; i++) {
		int tmp = arr[a + i];
		arr[a + i] = arr[b - i];
		arr[b - i] = tmp;
	}


}
int main() {
	int a;
	cin >> a >> n;

	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		arr[i] = a;
	}

	for (int i = 0; i < a; i++) {
		string o;
		cin >> o;
		if (o == "print") {
			print();
		}
		else if (o == "shift") {
			int a;
			cin >> a;
			for (int i = 0; i < a; i++) {
				shift();
			}
		}
		else if (o == "reverse") {
			int a, b;
			cin >> a >>b;
			reverse(a, b);
		}
	}

}