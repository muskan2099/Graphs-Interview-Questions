#include<bits/stdc++.h>
using namespace std;
void BFShelper(int **graph, int v, int sv, bool* visited){
    queue<int> q;
    q.push(sv);
    visited[sv] = 1;
    
    while(!q.empty()){
        int top = q.front();
        q.pop();
        cout << top << endl;
        for(int i = 0; i < v; i++){
            if(i == top){
                continue;
            }
            if(graph[top][i] == 1 && visited[i] == 0){
                q.push(i);
                visited[i] = 1;
            }
        }
    }
}
void BFS(int **graph, int v){
    
    bool *visited = new bool[v];
    for(int i = 0; i < v; i++){
        visited[i] = false;
    }
    for(int i = 0; i < v; i++){
        if(visited[i] == 0){
            BFShelper(graph, v, i, visited);
        }
    }
}
int main(){
	int v;
	cout << "Enter Number of Vertices : " << endl;
	cin >> v;
	int **graph = new int*[v];
	for(int i = 0; i < v; i++){
		graph[i] = new int[v];
		for(int j = 0; j < v; j++){
			graph[i][j] = 0;
		}
	}
	int e;
	cout << " Enter number of edges : " << endl;
	cin >> e;
	for(int i = 0; i < e; i++){
		cout << "Enter start and end : " << endl;
		int s; 
		int f;
		cin >> s >> f;

		graph[s][f] = 1;
		graph[f][s] = 1; 
	}

	BFS(graph, v);
	return 0;
}