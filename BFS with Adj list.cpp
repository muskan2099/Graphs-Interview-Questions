#include <bits/stdc++.h>
using namespace std; 

class Graph 
{ 
	int V; 
	list<int> *adj; 
	
public: 
	Graph(int V);  
	void addEdge(int v, int w); 

	void BFS(int s); 
}; 

Graph::Graph(int V) 
{ 
	this->V = V; 
	adj = new list<int>[V]; 
} 

void Graph::addEdge(int v, int w) 
{ 
	adj[v].push_back(w);
} 

void Graph::BFS(int s) 
{ 
	bool *visited = new bool[V];
	memset(visited, 0, V);
	
	queue<int> pending;
	pending.push(s);
	visited[s] = 1;
	list<int> :: iterator it; 
	while(!pending.empty()){
	    int front = pending.front();
	    pending.pop();
	    
	    cout << front << endl;
	 
	    for(it = adj[front].begin(); it != adj[front].end(); it++){
	        if(visited[*it] == 0){
	            pending.push(*it);
	            visited[*it] = 1;
	        }
	    }
	}
} 

// Driver program to test methods of graph class 
int main() 
{ 
	// Create a graph given in the above diagram 
/*	 Graph g(4); 
    g.addEdge(0, 1); 
    g.addEdge(0, 2); 
    g.addEdge(1, 2); 
    g.addEdge(2, 0); 
    g.addEdge(2, 3); 
    g.addEdge(3, 3);*/
	Graph g(7); 
	g.addEdge(0, 1); 
	g.addEdge(0, 3); 
	g.addEdge(1, 0); 
	g.addEdge(1, 2); 
	g.addEdge(2, 3); 
	g.addEdge(2, 1); 
	g.addEdge(3, 0); 
	g.addEdge(3, 2); 
	g.addEdge(1, 4); 
	g.addEdge(4, 5); 
	g.addEdge(4, 6); 
	g.addEdge(4, 1); 
	g.addEdge(5, 4); 
	g.addEdge(5, 6); 
	g.addEdge(6, 4); 
	g.addEdge(6, 5); 	

	cout << "Following is Breadth First Traversal "
		<< "(starting from vertex 2) \n"; 
	g.BFS(2); 

	return 0; 
} 
