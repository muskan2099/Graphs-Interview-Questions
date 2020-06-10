#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> reversegraph, int start, bool*visited){
    
    visited[start] = 1;
    for(int i = 0; i < reversegraph[start].size(); i++){
        if(visited[reversegraph[start][i]] == 0){
            dfs(reversegraph, reversegraph[start][i], visited);
        }
    }
}
void helperkosa(vector<vector<int>> graph, int start, bool *visited, stack<int> &kosa){
    
    visited[start] = 1;
    
    for(int i = 0; i < graph[start].size(); i++){
        if(visited[graph[start][i]] == 0){
            helperkosa(graph, graph[start][i], visited, kosa);
        }
    }
    
    kosa.push(start);
}
/*void printgraph(vector<vector<int>> graph){
    for(int i = 0; i < graph.size(); i++){
        for(int j = 0; j < graph[i].size(); j++){
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
}*/
int kosaraju(vector<vector<int>> graph){
    //step 1 : run the topological sort

    stack<int> kosa;
    bool *visited =  new bool[graph.size()];
    for(int i = 0; i < graph.size(); i++){
        visited[i] = 0;
    }
    for(int i = 0; i < graph.size(); i++){
        if(visited[i] == 0){
            helperkosa(graph, i, visited, kosa);
        }
    }
    
    //step 2: make a reverse graph
    
    vector<vector<int>> reversegraph(graph.size());
    for(int i = 0; i < graph.size(); i++){
        for(int j = 0; j < graph[i].size(); j++){
            reversegraph[graph[i][j]].push_back(i);
        }
    }
    //print reversegraph
    //printgraph(reversegraph);
    
    //step 3: call for the dfs using the elements of the stack
    
    int count = 0;
    //cout << "stack" << endl;
    for(int i = 0; i < reversegraph.size(); i++){
        visited[i] = 0;
    }
    while(!kosa.empty()){
        int start = kosa.top();
        kosa.pop();
        //cout << start << endl;
        if(visited[start] == 0){
            dfs(reversegraph, start, visited);
            count++;
        }
    }
    return count;
}
int main(){
	int n;
	cin >> n;
	int m;
	cin >> m;

	vector<vector<int>> graph(n);
	for(int i = 0; i < m; i++){
		int s;
		int f;
		cin >> s >> f;

		graph[s].push_back(f);
	}
	/*cout << "original" << endl;
	
	printgraph(graph);*/
	
	int ans = kosaraju(graph);
	
	cout << ans << endl;
	return 0;
}