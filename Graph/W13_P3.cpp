#include <iostream>
#include <string>

using namespace std;

// input
int t, n, vertex, s, d;
string cmd;
// variables
bool graph[2001][2001];

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> t >> n;

    for (int i = 0; i < n; i++) {
        cin >> vertex;
    }

    for (int i = 0; i < t; i++) {
        cin >> cmd;

        if(cmd == "insertEdge") {
            cin >> s >> d;
            if(graph[s][d]) {
                cout<<"Exist\n";
            } else {
                graph[s][d] = true;
                graph[d][s] = true;
            }
        } else if(cmd == "eraseEdge") {
            cin >> s >> d;
            if(!graph[s][d]) {
                cout<<"None\n";
            } else {
                graph[s][d] = false;
                graph[d][s] = false;
            }
        } else if(cmd == "SumAdjacentNode") {
            cin >> s;
            int total =0;

            for(int j=0; j < 2001;j++){
                if(graph[s][j]){
                    total += j;
                }
            }
            if(total==0){
                cout << "None\n";
            }
            else{
                cout <<total << endl;
            }
        }
    }

    return 0;
}