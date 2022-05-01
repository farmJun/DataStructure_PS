#include<iostream>
#include<string>
using namespace std;


class stack {
private:
	int arr[100];
	int size = 0;
public:

	bool empty() {
		if (size == 0) {
			return true;
		}
		else {
			return false;
		}
	}

	void push(int x) {
		arr[size] = x;
		size++;
	}

	int pop() {
		size--;
		return arr[size];
	}
};


int main() {
	int time;

	cin >> time;

	while (time--) {
		string order;
		cin >> order;
		stack st;

		for (int i = 0; i < order.length(); i++) {
			if (9 >= order[i] - '0' && order[i] - '0' >= 0) {
				st.push(order[i] - '0');
			}
			else {
				int a = st.pop();
				int b = st.pop();


				if (order[i] == '+') {
					st.push(a + b);
				}
				else if (order[i] == '-') {
					st.push(b - a);
				}
				else if (order[i] == '*') {
					st.push(a * b);
				}

			}

		}
		cout << st.pop() << endl;


	}






}