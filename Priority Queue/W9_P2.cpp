#include <iostream>
#include <vector>

using namespace std;

class PriorityQueue {
private:
    vector<int> v;

public:
    bool empty() {
        return v.size() == 0;
    }

    void push(int e) {
        if (empty()) {
            v.push_back(e);
        } else {
            vector<int>::iterator iter;
            for (iter = v.begin(); iter != v.end(); iter++) {
                if (e > *iter) {
                    v.insert(iter, e);
                    return;
                }
            }
            v.insert(v.end(), e);
        }
    }

    int pop() {
        if (!empty()) {
            int value = v.front();
            v.erase(v.begin());
            return value;
        } else {
            return 0;
        }
    }
};

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<int> a;
        vector<int> a2;
        PriorityQueue pq;
        PriorityQueue pq2;

        for (int i = 0; i < n; i++) {
            int num;
            cin >> num;
            if(num % 2 ==1){
                a.push_back(num);
            }
            else{
                a2.push_back(num);
            }


        }
        int s= a.size();
        int s2 = a2.size();

        for (int i = 0; i < s; i++) {
            pq.push(a.front());
            a.erase(a.begin());
        }

        for (int i = 0; i < s2; i++) {
            pq2.push(a2.front());
            a2.erase(a2.begin());
        }



        for (int i = 0; i <s; i++) {
            a.push_back(pq.pop());
        }
        for (int i = 0; i <s2; i++) {
            a2.push_back(pq2.pop());
        }


        for (int i = 0; i < s; i++) {
            cout << a[i] << " ";
        }
        for (int i = 0; i < s2; i++) {
            cout << a2[i] << " ";
        }
        cout << "\n";
    }

    return 0;
}