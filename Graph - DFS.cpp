#include<bits/stdc++.h>
using namespace std;
void DFS(int **graph, int v, bool *visited, int sv){

	cout << sv << endl;
	visited[sv] = true;
	for(int i = 0; i < v; i++){
		if(i == sv){
			continue;
		}
		if(graph[sv][i] == 1 && visited[i] == 0){
			DFS(graph, v, visited, i);
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

	// do activity
	bool *visited = new bool[v];
	for(int i = 0; i < v; i++){
		visited[i] = 0;
	}
	cout << "_________________________" << endl;
	DFS(graph, v, visited, 0);
	return 0;
}