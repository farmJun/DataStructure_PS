#include <iostream>
#include <string>

using namespace std;

class Node {
private:
    int data;
    Node *par;
    Node *left;
    Node *right;

public:
    Node(int d) {
        data = d;
        par = nullptr;
        left = nullptr;
        right = nullptr;
    }

    void setLeft(Node *node) {
        this->left = node;
        if (node != nullptr) {
            node->par = this;
        }
    }

    void setRight(Node *node) {
        this->right = node;
        if (node != nullptr) {
            node->par = this;
        }
    }

    friend class BST;
};

class BST {
private:


public:
    Node *root;
    BST() {
        root = nullptr;

    }

    Node *search(int data) {
        Node *curNode = root;
        while (curNode != nullptr) {
            if (data == curNode->data) {
                return curNode;
            } else if (data < curNode->data) {
                curNode = curNode->left;
            } else if (data > curNode->data) {
                curNode = curNode->right;
            }
        }
        return nullptr;
    }

    void insert(int data) {
        Node *node = new Node(data);

        int depth =0;

        if (root == nullptr) {
            root = node;
            cout << depth << endl;
            return;
        }
        Node *parNode = root->par;
        Node *curNode = root;
        while (curNode != nullptr) {

            if (data < curNode->data) {
                parNode = curNode;
                curNode = curNode->left;
            } else if (data > curNode->data) {
                parNode = curNode;
                curNode = curNode->right;
            }
            depth ++;
        }


        if (data < parNode->data) {
            parNode->setLeft(node);
        } else if (data > parNode->data) {
            parNode->setRight(node);
        }

        cout << depth << endl;
    }
    int getDepth(int key) {
        Node* curNode = root;
        int depth = 0;

        while (curNode->data != key) {
            if (key < curNode->data) {
                curNode = curNode->left;
            }
            else if (key > curNode->data) {
                curNode = curNode->right;
            }
            depth++;
        }

        return depth;
    }
    void remove(int data) {
        Node *node = search(data);
        Node *parNode = node->par;

        cout << getDepth(data) << endl;
        if (node->left == nullptr && node->right == nullptr) {
            if (node == root) {
                this->root = nullptr;
            } else {
                if (node == parNode->left) {
                    parNode->setLeft(nullptr);
                } else if (node == parNode->right) {
                    parNode->setRight(nullptr);
                }
            }
        } else if (node->left == nullptr || node->right == nullptr) {
            Node *child = (node->left != nullptr) ? node->left : node->right;

            if (node == root) {
                this->root = child;
            } else {
                if (node == parNode->left) {
                    parNode->setLeft(child);
                } else if (node == parNode->right) {
                    parNode->setRight(child);
                }
            }
        } else if (node->left != nullptr && node->right != nullptr) {
            Node *succ = node->right;
            Node *succPar = node;

            while (succ->left != nullptr) {
                succPar = succ;
                succ = succ->left;
            }

            if (succ == succPar->left) {
                succPar->setLeft(succ->right);
            } else {
                succPar->setRight(succ->right);
            }

            node->data = succ->data;
            node = succ;
        }

        delete node;
    }



    int idx = 0;
    void min(Node* curNode, int k) {
        if (curNode == NULL) return;

        min(curNode->left, k);
        if (idx == k-1) {
            //cout << curNode->key << " " << ++idx << endl;
            cout << curNode->data << endl;
        }
        idx++;
        min(curNode->right, k);
    }

    int height(Node* curNode) {
        // base:
        if (curNode == NULL) return -1;

        // recurse:
        return max(height(curNode->left), height(curNode->right)) + 1;
    }

};

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    BST *bst = new BST();

    while (n--) {
        string cmd;
        int data;

        cin >> cmd >> data;

        if (cmd == "insert") {
            bst->insert(data);
        } else if (cmd == "delete") {
            bst->remove(data);
        } else if (cmd == "min") {
            bst->idx =0;

            bst->min(bst->root, data);
        }
        else if(cmd=="height"){
            cout << bst->height(bst->search(data)) << endl;
        }
    }

    return 0;
}