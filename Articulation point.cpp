// A C++ program to find articulation points in an undirected graph 
#include<iostream> 
#include <list> 
#define NIL -1 
using namespace std; 

// A class that represents an undirected graph 
class Graph 
{ 
	int V; // No. of vertices 
	list<int> *adj; // A dynamic array of adjacency lists 
	void APUtil(int v, bool visited[], int disc[], int low[], 
				int parent[], bool ap[]); 
public: 
	Graph(int V); // Constructor 
	void addEdge(int v, int w); // function to add an edge to graph 
	void AP(); // prints articulation points 
}; 

Graph::Graph(int V) 
{ 
	this->V = V; 
	adj = new list<int>[V]; 
} 

void Graph::addEdge(int v, int w) 
{ 
	adj[v].push_back(w); 
	adj[w].push_back(v); // Note: the graph is undirected 
} 

// A recursive function that find articulation points using DFS traversal 
// u --> The vertex to be visited next 
// visited[] --> keeps tract of visited vertices 
// disc[] --> Stores discovery times of visited vertices 
// parent[] --> Stores parent vertices in DFS tree 
// ap[] --> Store articulation points 
void Graph::APUtil(int u, bool visited[], int disc[], 
									int low[], int parent[], bool point[]) 
{ 
	visited[u] = 1;
	int children = 0;
	static int time = 0;

	low[u] = ++time;
	disc[u] = ++time;

	list<int> :: iterator it;
	for(it = adj[u].begin(); it != adj[u].end(); it++){
		if(visited[*it] == 0){
			children++;
			parent[*it] = u;

			APUtil(*it, visited, disc, low, parent, point);

			low[u] = min(low[*it], low[u]);

			if(parent[u] == -1 && children > 1){
				point[u] = 1;
			}
			if(parent[u] != -1 && disc[u] <= low[*it]){
				point[u] = 1;
			}
		}
		else if(*it != parent[u]){
			low[u] = min(low[u], disc[*it]);
		}
	}
} 
 
void Graph::AP() 
{ 
	bool *visited = new bool[V];
	bool *point = new bool[V];
	int *parent = new int[V];
	int *low = new int[V];
	int *disc = new int[V];

	for(int i = 0; i < V; i++){
		visited[i] = 0;
		point[i] = 0;
		parent[i] = -1;
	}

	for(int i = 0; i < V; i++){
		if(visited[i] == 0){
			APUtil(i, visited, disc, low, parent, point);
		}
	}
	for(int i = 0; i < V; i++){
		if(point[i] == 1){
			cout << i << " ";
		}
	}
	cout << endl;
} 

int main() 
{ 
	// Create graphs given in above diagrams 
	cout << "\nArticulation points in first graph \n"; 
	Graph g1(5); 
	g1.addEdge(1, 0); 
	g1.addEdge(0, 2); 
	g1.addEdge(2, 1); 
	g1.addEdge(0, 3); 
	g1.addEdge(3, 4); 
	g1.AP(); 

	cout << "\nArticulation points in second graph \n"; 
	Graph g2(4); 
	g2.addEdge(0, 1); 
	g2.addEdge(1, 2); 
	g2.addEdge(2, 3); 
	g2.AP(); 

	cout << "\nArticulation points in third graph \n"; 
	Graph g3(7); 
	g3.addEdge(0, 1); 
	g3.addEdge(1, 2); 
	g3.addEdge(2, 0); 
	g3.addEdge(1, 3); 
	g3.addEdge(1, 4); 
	g3.addEdge(1, 6); 
	g3.addEdge(3, 5); 
	g3.addEdge(4, 5); 
	g3.AP(); 

	return 0; 
} 
