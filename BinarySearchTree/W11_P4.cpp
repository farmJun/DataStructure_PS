#include <iostream>
#include <string>
using namespace std;

struct node {
    int key;
    node* parent;
    node* left;
    node* right;

    // ��� ������
    node(int key) {
        this->key = key;
        parent = left = right = NULL;
    }
};

class BST {
private:
    node* root;
    int size;

public:
    BST() {
        root = NULL;
        size = 0;
    };

    node* search(node* curNode, int key) {
        if (curNode == NULL) return NULL;

        if (curNode->key == key) {
            return curNode;
        }
        else if (curNode->key < key) {
            return search(curNode->right, key);
        }
        else {
            return search(curNode->left, key);
        }
    };


    void insert(int key) {
        int depth = 0;
        if (search(root, key) != NULL) {
            return;
        }

        node* newNode = new node(key);
        if (root == NULL) { // ����ִ� Ʈ���� ���
            root = newNode;
            cout << 0 << endl;
            return;
        }

        node* parNode = NULL; // ���� ������ ����� �θ���
        node* curNode = root;  // ���� ������ ����� ��ġ Ž��

        while (curNode != NULL) { // �������� ���� ����
            parNode = curNode;
            if (curNode->key < key) {
                curNode = curNode->right;
            }
            else {
                curNode = curNode->left;
            }
            depth++;
        }

        newNode->parent = parNode;
        if (parNode->key < key) {
            parNode->right = newNode;
        }
        else {
            parNode->left = newNode;
        }

        size++;
        cout << depth << endl;
    }

    int getDepth(int key) {
        node* curNode = root;
        int depth = 0;

        while (curNode->key != key) {
            if (key < curNode->key) {
                curNode = curNode->left;
            }
            else if (key > curNode->key) {
                curNode = curNode->right;
            }
            depth++;
        }

        return depth;
    }

    void remove(int key) {
        node* delNode = search(root, key);
        if (delNode == NULL) return; // �����Ϸ��� ��尡 ���� ��� �������� �ʰ� ����

        cout << getDepth(key) << endl; // �����Ϸ��� ����� ���� ���

        node* parNode = delNode->parent; // ������ ����� �θ�
        node* childNode; // ������ ����� �ڽ� ������, ���߿� parNode�� �ڽ����� ����

        if (delNode->left == NULL && delNode->right == NULL) {
            // case1 : ������� ����� �ڽ��� ���� x
            childNode = NULL;
        }
        else if (delNode->left == NULL && delNode->right != NULL) {
            // case2 : ������� ����� �ڽ��� �����ʸ� ����
            childNode = delNode->right;

        }
        else if (delNode->left != NULL && delNode->right == NULL) {
            // case3 : ������� ����� �ڽ��� ���ʸ� ����
            childNode = delNode->left;
        }
        else {
            // �ڽ��� �� �� ����
            childNode = delNode->right;
            while (childNode->left != NULL) {
                childNode = childNode->left;
            }

            // ������ ��忡 childNode�� ����
            delNode->key = childNode->key;
            delNode = childNode;
            parNode = delNode->parent;
            childNode = delNode->right;
        }

        if (parNode == NULL) { // ��Ʈ�� �����ϴ� ���
            root = childNode;
            if (childNode != NULL) {
                root->parent = NULL;
            }
        }
        else if (delNode == parNode->left) { // ������ ��尡 �θ��� ���� �ڽ�
            parNode->left = childNode;
            if (childNode != NULL) childNode->parent = parNode;
        }
        else { // ������ ��尡 �θ��� ������ �ڽ�
            parNode->right = childNode;
            if (childNode != NULL) childNode->parent = parNode;
        }

        delete delNode;
        size--;
    };

    int idx = 0;
    void printMax(node* curNode, int k) {
        if (curNode == NULL) return;

        printMax(curNode->left, k);
        if (idx == size - (k-1)) {
            cout << curNode->key << endl;
        }
        idx++;
        printMax(curNode->right, k);
    }

    //  curNode�� ��Ʈ�� subtree�� height
    int height(node* curNode) {
        // base:
        if (curNode == NULL) return -1;

        // recurse:
        return max(height(curNode->left), height(curNode->right)) + 1;
    }

    node* getRoot() {
        return root;
    }

};

int main() {
    BST* bst = new BST;
    int t, x;
    string cmd;

    cin >> t;
    while (t--) {
        cin >> cmd;
        if (cmd == "insert") {
            cin >> x;
            bst->insert(x);
        } else if (cmd == "delete") {
            cin >> x;
            bst->remove(x);
        } else if (cmd == "max") {
            cin >> x;
            bst->idx = 0;
            bst->printMax(bst->getRoot(), x);

        } else if (cmd == "height") {
            cin >> x;
            node* curNode = bst->search(bst->getRoot(),x);
            cout << bst->height(curNode) << endl;
        }
    }
    delete bst;
}