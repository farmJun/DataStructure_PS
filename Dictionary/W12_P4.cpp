#include<iostream>
#include<string>
using namespace std;
#define NOITEM 0
#define ISITEM 1
#define AVALABLE 2

struct Entry {
    int id;
    int name;
    int valid;
    string realname;
    bool present;
    Entry() {
        id = 0;
        name = 0;
        valid = 0;
        realname = "";
        present = false;
    }
    Entry(int i, int n,string realn) {
        id = i;
        name = n;
        valid = ISITEM;
        realname = realn;
        present = false;
    }
    void erase() {
        valid = AVALABLE;
    }
};

class hashTable {
private:
    Entry* id_table;
    Entry* name_table;
    int capacity;
public:
    hashTable() {
        capacity = 250000;
        id_table = new Entry[capacity];
        name_table = new Entry[capacity];
    }
    int hash_func(int k) {
        return k % capacity;
    }
    void add(int i, int n,string realn) {
        //id_table로의 삽입
        int index = hash_func(i);
        int probing = 1;
        while (id_table[index].valid != NOITEM && probing <= capacity) {
            index = hash_func(index + 1);
            probing++;
        }
        if (probing > capacity) {
            return;
        }
        id_table[index] = Entry(i, n,realn);
        //name_table로의 삽입
        index = hash_func(n);
        probing = 1;
        while (name_table[index].valid != NOITEM && probing <= capacity) {
            index = hash_func(index + 1);
            probing++;
        }
        if (probing > capacity) {
            return;
        }
        name_table[index] = Entry(i, n,realn);
    }
    void erase(int i) {
        //name을 저장할 공간
        int n = -1;
        //id_table에 저장된 데이터 삭제
        int index = hash_func(i);
        int probing = 1;
        while (id_table[index].valid != NOITEM && probing <= capacity) {
            if (id_table[index].id == i && id_table[index].valid == ISITEM) {
                //name을 n에 저장
                n = id_table[index].name;
                id_table[index].erase();
                break;
            }
            probing++;
            index = hash_func(index + 1);
        }
        // n값이 할당되지 않았을때 함수 종료
        if (n == -1) {
            return;
        }
        //name_table에 저장된 데이터 삭제
        index = hash_func(n);
        probing = 1;
        while (name_table[index].valid != NOITEM && probing <= capacity) {
            if (name_table[index].name == n && name_table[index].valid == ISITEM) {
                name_table[index].erase();
                break;
            }
            probing++;
            index = hash_func(index + 1);
        }
    }
    void name(int i) {
        int index = hash_func(i);
        int probing = 1;
        while (id_table[index].valid != NOITEM && probing <= capacity) {
            if (id_table[index].id == i && id_table[index].valid==ISITEM) {
                cout << id_table[index].realname << endl;
                break;
            }
            probing++;
            index = hash_func(index + 1);
        }
    }
    void present(int n) {
        // name_table의 출석상태를 변경
        int i = -1;
        int index = hash_func(n);
        int probing = 1;
        while (name_table[index].valid != NOITEM && probing <= capacity) {
            if (name_table[index].name == n && name_table[index].valid == ISITEM) {
                //id를 i에 저장
                i = name_table[index].id;
                name_table[index].present = true;
                cout << name_table[index].id << endl;
                break;
            }
            probing++;
            index = hash_func(index + 1);
        }
        if (i == -1) {
            cout << "Invalid\n";
            return;
        }
        //id_table의 출석상태를 변경
        index = hash_func(i);
        probing = 1;
        while (id_table[index].valid != NOITEM && probing <= capacity) {
            if (id_table[index].id == i && id_table[index].valid == ISITEM) {
                id_table[index].present = true;
                break;
            }
            probing++;
            index = hash_func(index + 1);
        }
    }
    void absent(int n) {
        // name_table의 출석상태를 변경
        int i = -1;
        int index = hash_func(n);
        int probing = 1;
        while (name_table[index].valid != NOITEM && probing <= capacity) {
            if (name_table[index].name == n && name_table[index].valid == ISITEM) {
                //id를 i에 저장
                i = name_table[index].id;
                name_table[index].present = false;
                cout << name_table[index].id << endl;
                break;
            }
            probing++;
            index = hash_func(index + 1);
        }
        if (i == -1) {
            cout << "Invalid\n";
            return;
        }
        //id_table의 출석상태를 변경
        index = hash_func(i);
        probing = 1;
        while (id_table[index].valid != NOITEM && probing <= capacity) {
            if (id_table[index].id == i && id_table[index].valid == ISITEM) {
                id_table[index].present = false;
                break;
            }
            probing++;
            index = hash_func(index + 1);
        }
    }
    void absentnow() {
        int cnt = 0;
        for (int i = 0; i < capacity; i++) {
            if (id_table[i].present == true && id_table[i].valid == ISITEM) {
                cnt++;
            }
        }
        cout << cnt << endl;
    }
};
int stringtoint(string s) {
    int key = 0;
    int t = 1;
    for (int i = 0; i < 6; i++, t *= 26) {
        key += (s[i] - 'a') * t;
    }
    return key;
}

int main() {
    int t;
    cin >> t;
    string cmd;
    hashTable ht;
    for (int i = 0; i < t; i++) {
        cin >> cmd;
        if (cmd == "add") {
            int i;
            string n;
            cin >> i >> n;
            int n_ = stringtoint(n);
            ht.add(i, n_, n);
        }
        else if (cmd == "delete") {
            int i;
            cin >> i;
            ht.erase(i);
        }
        else if (cmd == "name") {
            int i;
            cin >> i;
            ht.name(i);
        }
        else if (cmd == "present") {
            string n;
            cin >>  n;
            int n_ = stringtoint(n);
            ht.present(n_);
        }
        else if (cmd == "absent") {
            string n;
            cin >> n;
            int n_ = stringtoint(n);
            ht.absent(n_);
        }
    }
    ht.absentnow();
}