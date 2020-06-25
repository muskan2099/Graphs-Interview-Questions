#include<bits/stdc++.h>
using namespace std; 

#define V 6 

bool bfs(int rGraph[V][V], int s, int t, int parent[]) 
{ 
	bool visited[V]; 
    memset(visited, 0, sizeof(visited)); 
  
	queue<int> pending;
	pending.push(s);
	visited[s] = 1;
	parent[s] = -1;
	while(!pending.empty()){
		int front = pending.front();
		pending.pop();

		for(int i = 0; i < V; i++){
			if(!visited[i] && rGraph[front][i] > 0){
				pending.push(i);
				visited[i] = 1;
				parent[i] = front;
			}
		}
	}
	return (visited[t] == 1);
} 

int fordFulkerson(int graph[V][V], int s, int t) 
{ 
	int tempgraph[V][V];

	for(int i = 0; i < V; i++){
		for(int j = 0; j < V; j++){
			tempgraph[i][j] = graph[i][j];
		}
	}
	int parent[V];

	int output = 0;
	while(bfs(tempgraph, s, t, parent)){
	
		int mincap = INT_MAX;
		for(int v = t; v != s; v = parent[v]){
			int u = parent[v];
			mincap = min(mincap, tempgraph[u][v]);
		}

		for(int v = t; v != s; v = parent[v]){
			int u = parent[v];
			tempgraph[u][v] = tempgraph[u][v] - mincap;
			tempgraph[v][u] = tempgraph[v][u] + mincap; 
		}

		output += mincap;
	}
	return output;
} 

int main() 
{ 
	// Let us create a graph shown in the above example 
	int graph[V][V] = { {0, 16, 13, 0, 0, 0}, 
						{0, 0, 10, 12, 0, 0}, 
						{0, 4, 0, 0, 14, 0}, 
						{0, 0, 9, 0, 0, 20}, 
						{0, 0, 0, 7, 0, 4}, 
						{0, 0, 0, 0, 0, 0} 
					}; 

	cout << "The maximum possible flow is " << fordFulkerson(graph, 0, 5); 

	return 0; 
} 
