#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Node {
private:
	Node* parent;
	vector<Node*> child;
	int value;

public:
	Node() {
		parent = nullptr;
		value = 0;
	}

	friend class Tree;
};

class Tree {
private:
	Node* root;
	vector<Node*> nodeList;


public:
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

		if (p == nullptr) {
			cout << "-1" << endl;
		}

		else {
			Node* c = new Node();
			c->parent = p;
			c->value = y;
			p->child.push_back(c);
			nodeList.push_back(c);
		}

	}


	void print(int x) {
		Node* p = find(x);

		while (p != root) {
			cout << p->parent->value << " ";
			p = p->parent;
		}
		cout << endl;
	}

	

};


int main() {
	int treeNum, depthNum;

	cin >> treeNum >> depthNum;

	Tree* t = new Tree();

	for (int i = 1; i < treeNum; i++) {
		int x, y;
		cin >> x >> y;
		t->insert(x, y);
	}


	for (int i = 0; i < depthNum; i++) {
		int x;
		cin >> x;
		t->print(x);
	}
}