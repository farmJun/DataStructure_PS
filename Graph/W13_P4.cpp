#include<iostream>
#include<vector>

using namespace std;

int n,m,k,f;
int graph[501][501];

int main(){
    cin>>n>>m;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>graph[i][j];
        }
    }

    for(int i=0;i<m;i++){
        cin>>k>>f;

        vector<int> groupF;
        vector<int> groupP;
        vector<int> groupA;

        for(int j=1;j<=n;j++){
            if(k==j){
                continue;
            }
            if(graph[k][j]==2){
                groupP.push_back(j);
            }
            else if(graph[k][j]==1){
                groupF.push_back(j);
            }
            else if(graph[k][j]==0){
                groupA.push_back(j);
            }
        }

        int result=0;
        int result1=0;
        if(f==0){
            for(int b=0;b<groupA.size();b++){
                for(int a=0;a<groupP.size();a++) {
                    if (graph[groupP[a]][groupA[b]] == 2) {
                        result1 = 1;
                        result = 1;
                    }
                }
                if(result1==1){
                    cout << groupA[b] << " ";
                }
                result1=0;
            }
            if(result==0){
                cout<<"None\n";
            }
            else{
                cout<<"\n";
            }
        }
        else if(f==1){
            for(int b=0;b<groupA.size();b++){
                for(int a=0;a<groupP.size();a++) {
                    if (graph[groupP[a]][groupA[b]] == 1) {
                        result1 = 1;
                        result = 1;
                    }
                }
                if(result1==1){
                    cout << groupA[b] << " ";
                }
                result1=0;
            }
            if(result==0){
                cout<<"0\n";
            }
            else{
                cout<<"\n";
            }
        }

    }
    return 0;
}