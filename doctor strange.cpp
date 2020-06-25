#include <bits/stdc++.h>
using namespace std;
void APUtil(vector<int> graph[], int u, bool visited[], int disc[], 
									int low[], int parent[], bool point[], int &timee) 
{ 
	visited[u] = 1;
	int children = 0;
	//static int time = 0;

	low[u] = ++timee;
	disc[u] = ++timee;

	for(int i = 0; i < graph[u].size(); i++){
		if(visited[graph[u][i]] == 0){
			children++;
			parent[graph[u][i]] = u;

			APUtil(graph, graph[u][i], visited, disc, low, parent, point, timee);

			low[u] = min(low[graph[u][i]], low[u]);

			if(parent[u] == -1 && children > 1){
				point[u] = 1;
			}
			else if(parent[u] != -1 && disc[u] <= low[graph[u][i]]){
				point[u] = 1;
			}
		}
		else if(graph[u][i] != parent[u]){
			low[u] = min(low[u], disc[graph[u][i]]);
		}
	}
} 
 
int AP(vector<int> graph[], int V) 
{ 
	bool *visited = new bool[V + 1];
	bool *point = new bool[V + 1];
	int *parent = new int[V + 1];
	int *low = new int[V + 1];
	int *disc = new int[V + 1];

	for(int i =1; i <= V; i++){
		visited[i] = 0;
		point[i] = 0;
		parent[i] = -1;
	}
	int timee = 0;
	for(int i = 1; i <= V; i++){
		if(visited[i] == 0){
			APUtil(graph, i, visited, disc, low, parent, point, timee);
		}
	}
	int count = 0;
	for(int i = 1; i <= V; i++){
		if(point[i] == 1){
			count++;
		}
	}
	return count;
} 
int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<int> graph[n + 1];
		int m;
		cin >> m;
		for(int i = 0; i < m; i++){
			int p, q;
			cin >> p >> q;

			graph[p].push_back(q);
			graph[q].push_back(p);
		}
		cout << AP(graph, n) << endl;
		//printgraph(graph);
	}

	return 0;
}