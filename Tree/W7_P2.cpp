#include<iostream>
#include<vector>
using namespace std;

class Node {
	Node* parent;
	vector<Node*>child;
	int value;

	Node() {
		parent = nullptr;
		value = 0;
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

	int preOrder(int x) {
		//숫자 입력하면 거기에 맞는 노드 찾고
		Node* p = find(x);

		int file = 0;

		//내 자식의 크기가 0 이다 = external노드 니까 file 1추가
		if (p->child.size() == 0) {
			file++;
		}

		//전위 순회하면서 file에 더해주기
		for (Node* a : p->child) {
			file += preOrder(a->value);
		}

		return file;

	}

};

int main() {
	int tree_num, order;
	Tree* t = new Tree();
	
	cin >> tree_num >> order;

	for (int i = 1; i < tree_num; i++) {
		int a, b;
		cin >> a >> b;
		t->insert(a, b);
	}

	for (int i = 0; i < order; i++) {
		int a;
		cin >> a;
		cout << t->preOrder(a) << endl;
	}






}