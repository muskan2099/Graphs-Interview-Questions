// A C++ program to print topological 
// sorting of a DAG 
#include<iostream> 
#include <list> 
#include <stack> 
using namespace std; 

// Class to represent a graph 
class Graph 
{ 
// No. of vertices' 
	int V;	 

	// Pointer to an array containing adjacency listsList 
	list<int> *adj; 

	// A function used by topologicalSort 
	void topologicalSortUtil(int v, bool visited[], 
stack<int> &Stack); 
public: 
// Constructor 
	Graph(int V); 

	// function to add an edge to graph 
	void addEdge(int v, int w); 

	// prints a Topological Sort of 
// the complete graph 
	void topologicalSort(); 
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

// A recursive function used by topologicalSort 
void Graph::topologicalSortUtil(int v, bool visited[], stack<int> &st) 
{ 
	visited[v] = 1;

	list<int> :: iterator it;
	for(it = adj[v].begin(); it != adj[v].end(); it++){

		if(!visited[*it]){
			topologicalSortUtil(*it, visited, st);
		}
	}

	st.push(v);
} 

void Graph::topologicalSort() 
{ 
	stack<int> st;
	bool *visited = new bool[V];
	for(int i = 0; i < V; i++){
		visited[i] = 0;
	}

	for(int i = 0; i < V; i++){
		if(visited[i] == 0){
			topologicalSortUtil(i, visited, st);
		}
	}
	while(!st.empty()){
		cout << st.top() << " ";
		st.pop();
	}
} 

int main() 
{ 
	/*Graph g(12); 
	g.addEdge(2, 11); 
	g.addEdge(3, 9); 
	g.addEdge(3, 4); 
	g.addEdge(4, 9); 
	g.addEdge(5, 11); 
	g.addEdge(5, 2); 

	g.addEdge(6, 9); 
	g.addEdge(6, 3); 
	g.addEdge(6, 4); 
	g.addEdge(8, 3); 
	g.addEdge(8, 4); 
	g.addEdge(8, 6); 

	g.addEdge(9, 1); 
	g.addEdge(10, 2); 
	g.addEdge(10, 5); */
	Graph g(6); 
    g.addEdge(5, 2); 
    g.addEdge(5, 0); 
    g.addEdge(4, 0); 
    g.addEdge(4, 1); 
    g.addEdge(2, 3); 
    g.addEdge(3, 1);
	
	cout << "Following is a Topological Sort of the given graph \n"; 
	g.topologicalSort(); 

	return 0; 
} 
