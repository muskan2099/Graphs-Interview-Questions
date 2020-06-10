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

	int primMST(); 
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

int Graph::primMST() 
{ 
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;
	bool *visited = new bool[V];
	for(int i = 0; i < V; i++){
		visited[i] = 0;
	}
	int *key = new int[V];
	for(int i = 0; i < V; i++){
		key[i] = INF;
	}

	int *parent = new int[V];
	for(int i = 0; i < V; i++){
		parent[i] = -1;
	}

	heap.push(make_pair(0, 0));
	key[0] = 0;

	while(!heap.empty()){
		pair<int, int> front = heap.top();
		heap.pop();
		int node = front.second;
		int weight = front.first;

		visited[node] = 1;

		list<pair<int, int>> :: iterator it;
		for(it = adj[node].begin(); it != adj[node].end(); it++){
			int v = it -> first;
			int cost = it -> second;

			if(!visited[v] && cost < key[v]){
				key[v] = cost;
				heap.push(make_pair(key[v], v));
				parent[v] = node;
			}
		}
	}
	int ans = key[0];
	for(int i = 1; i < V; i++){
		cout << parent[i] << " - > " << i << endl;
		ans += key[i];
	}
	return ans;
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

	int res = g.primMST(); 
    cout << "___________" << endl;
	cout << res << endl;
	return 0; 
} 
