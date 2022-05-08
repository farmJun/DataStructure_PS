#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Node {
private:
	Node* parent;
	vector<Node*> child;
	int value;
	int depth;

public:
	Node() {
		parent = nullptr;
		value = 0;
		depth = 0;
	}

	friend class Tree;
};

class Tree {

public:
	Node* root;
	vector<Node*> nodeList;

	Tree() {
		root = new Node();
		root->value = 1;
		root->depth = 0;
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
		//문제 보고 예외처리
		Node* p = find(x);
		for (int i = 0; i < nodeList.size(); i++) {
			if (nodeList[i]->value == y) {
				return;
			}
		}

		Node* c = new Node();
		//자식의 깊이 = 부모 깊이 +1
		c->depth = p->depth + 1;
		c->parent = p;
		c->value = y;
		p->child.push_back(c);
		nodeList.push_back(c);
		

	}


	void preOrder(Node* n) {
		Node* p = n;

		cout << p->depth << " ";

		for (Node* a : p->child) {
			preOrder(a);
		}

	}


};


int main() {
	int order_num;


	cin >> order_num;

	

	for (int i = 0; i < order_num; i++) {
		//트리 꼭 for문 안에 넣어서 트리 초기화 시키기
		Tree* t = new Tree();
		int tree_num;
		cin >> tree_num;
		//트리 입력할 때 10개 입력해도 9개만 입력받기
		//루트는 이미 포함?
		for (int j = 1; j < tree_num; j++) {
			int a, b;
			cin >> a >> b;
			t->insert(a, b);
		}
		t->preOrder(t->root);
		cout << endl;
	}
}