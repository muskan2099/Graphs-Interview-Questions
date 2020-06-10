#include <bits/stdc++.h>
using namespace std;
    int find(int* &parent, int nodes, int x){
        //cout << "THIS IS FIND" << endl;
        if(parent[x] == x){
            return x;
        }
        int px = find(parent,nodes, parent[x]);
        parent[x] = px;
        return px;
    }
    
    void unionofdsu(int * &parent, int* &rank, int nodes, int a, int b){
        //cout << "THIS IS UNION" << endl;
        int la = find(parent, nodes, a);
        int lb = find(parent, nodes, b);
        
        if(la != lb){
            if(rank[la] > rank[lb]){
                parent[lb] = la;
            }
            else if(rank[la] < rank[lb]){
                parent[la] = lb;
            }
            else{
                parent[la] = lb;
                rank[lb]++;
            }
        }
    }
    void printdsu(int *parent, int nodes){
        
        //cout << "THIS IS PRINT" << endl;
        for(int i = 0; i < nodes; i++){
            cout << parent[i] << " ";
        }
        
    }
int main(){
    
    int nodes;
    cin >> nodes;
    
    int *parent = new int[nodes];
    int *rank = new int[nodes];
    
     for(int i = 0; i < nodes; i++){
        parent[i] = i;
     }
     for(int i = 0; i < nodes; i++){
        rank[i] = 1;
     }
    
    unionofdsu(parent, rank, nodes, 0 , 1);
    unionofdsu(parent, rank, nodes, 1 , 2);
    unionofdsu(parent, rank, nodes, 2 , 3);
    unionofdsu(parent, rank, nodes, 3 , 4);
    unionofdsu(parent, rank, nodes, 4 , 5);
    unionofdsu(parent, rank, nodes, 5 , 6);
    unionofdsu(parent, rank, nodes, 6 , 7);
    unionofdsu(parent, rank, nodes, 7 , 8);
    
    printdsu(parent, nodes);
    
    return 0;
}

