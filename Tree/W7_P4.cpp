#include<iostream>
#include<vector>
using namespace std;

class Node {
public:
	Node* parent;
	vector<Node*>child;
	int value;
	int num;

	Node() {
		parent = nullptr;
		value = 0;
		num = 0;
	}

	friend class Tree;
};

class Tree {
public:
	Node* root;
	vector<Node*>nodeList;

	Tree() {
		root = new Node();
		root->value = 1;
		nodeList.push_back(root);
	}

	Node* find(int x) {
		for (int i = 0; i < nodeList.size(); i++) {
			if (nodeList[i]->value == x) {
				return nodeList[i];
			}
		}
		return nullptr;
	}

	void insert(int x, int y) {
		Node* p = find(x);

		Node* c = new Node();
		c->value = y;

		c->parent = p;
		p->child.push_back(c);
		nodeList.push_back(c);
	}

	void insert2(int x, int y) {
		Node* p = find(x);

		p->num = y;
	
	}

	int postOrder(int x) {
		Node* p = find(x);

		int sum = 0;
		sum += p->num;

		for (int i = 0; i < p->child.size();i++) {
			sum+= postOrder(p->child[i]->value);
		}

		return sum;

	}



};

int main() {
	int tree_num, order;

	cin >> tree_num >> order;


		Tree* t = new Tree();
		
	

		for (int j = 1; j < tree_num; j++) {
			int a, b;
			cin >> a >> b;
			t->insert(a, b);
		}
		for (int j = 0; j < tree_num; j++) {
			int a, b;
			cin >> a >> b;
			t->insert2(a, b);
		}
		for (int i = 0; i < order; i++) {
			int a;
			cin >> a;
			cout << t->postOrder(a);
			cout << endl;
		}


		


	
}