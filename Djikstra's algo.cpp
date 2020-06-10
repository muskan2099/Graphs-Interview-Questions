#include<bits/stdc++.h> 
using namespace std; 
# define INF 0x3f3f3f3f 
class Graph 
{ 
	int V; 
	list< pair<int, int> > *adj; 

public: 
	Graph(int V);  
	void addEdge(int u, int v, int w); 

	void shortestPath(int s); 
}; 

Graph::Graph(int V) 
{ 
	this->V = V; 
	adj = new list<pair<int, int>> [V]; 
} 

void Graph::addEdge(int u, int v, int w) 
{ 
	adj[u].push_back(make_pair(v, w)); 
	adj[v].push_back(make_pair(u, w)); 
} 
void Graph::shortestPath(int src) 
{ 
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;

	int *key = new int[V];
	for(int i = 0; i < V; i++){
		key[i] = INF;
	}
	
	heap.push(make_pair(0, 0));
	key[0] = 0;

	while(!heap.empty()){
		pair<int, int> front = heap.top();
		heap.pop();
		int node = front.second;
		int weight = front.first;

		list<pair<int, int>> :: iterator it;
		for(it = adj[node].begin(); it != adj[node].end(); it++){
			
			int v = it -> first;
			int cost = it -> second;

			if(key[v] > cost + weight){
				key[v] = cost + weight;
				heap.push(make_pair(key[v], v));
			}
		}
	}
	for(int i = 0; i < V; i++){
		cout << i << " -> " << key[i] << endl;
	}
}  
int main() 
{ 
	int V = 9; 
	Graph g(V); 

	g.addEdge(0, 1, 4); 
	g.addEdge(0, 7, 8); 
	g.addEdge(1, 2, 8); 
	g.addEdge(1, 7, 11); 
	g.addEdge(2, 3, 7); 
	g.addEdge(2, 8, 2); 
	g.addEdge(2, 5, 4); 
	g.addEdge(3, 4, 9); 
	g.addEdge(3, 5, 14); 
	g.addEdge(4, 5, 10); 
	g.addEdge(5, 6, 2); 
	g.addEdge(6, 7, 1); 
	g.addEdge(6, 8, 6); 
	g.addEdge(7, 8, 7); 

	g.shortestPath(0); 

	return 0; 
} 
