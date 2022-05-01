#include<iostream>
#include<string>
using namespace std;

class Node {
private:
    int value;
    Node* next;

public:
    Node() {
        this->value = 0;
        this->next = nullptr;
    }



    friend class LinkedList;
};

class LinkedList {
private:
    Node* head;
    Node* tail;
    int size;

public:
    LinkedList() {
        this->head = nullptr;
        this->tail = nullptr;
        this->size = 0;
    }



    bool empty() {
        if (this->size == 0) {
            return true;
        }
        else {
            return false;
        }
    }

    void print() {
        if (empty()) {
            cout << "empty" << endl;
            return;
        }

        Node* curNode = this->head;
        while (curNode != nullptr) {
            cout << curNode->value << " ";
            curNode = curNode->next;
        }
        cout << endl;
    }

    void Append(int x) {
        Node* appendNode = new Node;
        appendNode->value = x;

        if (empty()) {
            this->head = appendNode;
            this->tail = appendNode;
        }
        else {
            this->tail->next = appendNode;
            this->tail = appendNode;
        }

        this->size++;
        print();
    }

    int Delete(int index) {
        if (index >= this->size) {
            return -1;
        }

        Node* deleteNode = this->head;

        if (index == 0) {
            if (this->size == 1) {
                this->head = nullptr;
                this->tail = nullptr;
            }
            else {
                this->head = deleteNode->next;
            }
        }
        else {
            Node* prevNode = this->head;
            for (int i = 0; i < index; i++) {
                prevNode = deleteNode;
                deleteNode = deleteNode->next;
            }
            prevNode->next = deleteNode->next;
            if (deleteNode == this->tail) {
                this->tail = prevNode;
            }
        }

        int deleteValue = deleteNode->value;
        delete deleteNode;
        this->size--;
        return deleteValue;

    }

    void insert(int index, int x) {
        if (index > this->size) {
            cout << "Index Error" << endl;
            return;
        }

        if (index == 0) {
            Node* insertNode = new Node;
            insertNode->value = x;
            insertNode->next = this->head;
            this->head = insertNode;
            print();
        }
        else if (index == this->size) {
            Append(x);
        }
        else {
            Node* insertNode = new Node;
            insertNode->value = x;

            Node* curNode = this->head;
            for (int i = 1; i < index; i++) {
                curNode = curNode->next;
            }
            insertNode->next = curNode->next;
            curNode->next = insertNode;
            print();
        }

        this->size++;
    }

    void Sum() {

        Node* newNode = head;

        if (size == 0) {
            cout << "empty" << endl;
            return;
        }

        int sum = 0;

        //for일 때 안되다가 아 해결 포문에서 뉴노드가 테일일 때 넥스트를 시켜버리니까 안되지ㅡㅡ
        //while문은 됨 nullptr NULL 둘다 됨

        for (int i = 0; i < size; i++) {

            sum += newNode->value;

            if (newNode == tail) {
                break;
            }
            newNode = newNode->next;

        }

        cout << sum << endl;
    }


};

int main() {
    int order_num;
    cin >> order_num;
    LinkedList* li = new LinkedList();


    for (int i = 0; i < order_num; i++) {
        string s;
        cin >> s;
        if (s == "Append") {
            int a;
            cin >> a;
            li->Append(a);
        }
        else if (s == "Print") {
            li->print();
        }
        else if (s == "Delete") {
            int a;
            cin >> a;
            cout << li->Delete(a) << endl;
        }
        else if (s == "Insert") {
            int a, b;
            cin >> a >> b;
            li->insert(a, b);
        }
        else if (s == "Sum") {
            li->Sum();
        }
    }
}
