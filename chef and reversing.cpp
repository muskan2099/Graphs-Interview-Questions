#include <bits/stdc++.h>
using namespace std;
void dijkstra(vector<vector<pair<int, int>>> graph){
	priority_queue<pair<int, int>, vector<pair< int, int>>, greater<pair<int, int>>> heap;

	int *key = new int[graph.size()];
	for(int i = 0; i < graph.size(); i++){
		key[i] = INT_MAX;
	}

	heap.push(make_pair(0, 0));
	//vertex, count
	key[0] = 0;

	while(!heap.empty()){
		pair<int, int> front = heap.top();
		heap.pop();
		int node = front.second;
		int cost = front.first;

		for(int i = 0; i < graph[node].size(); i++){
			pair<int, int> child = graph[node][i];
			int ver = child.first;
			int weight = child.second;

			if(key[ver] > weight + cost){
				key[ver] = weight + cost;
				heap.push(make_pair(key[ver], ver));
			}
		}
	}
	cout << key[graph.size() - 1] << endl;
}
void printgraph(vector<vector<pair<int, int>>> graph){
    for(int i = 0; i < graph.size(); i++){
        for(int j = 0; j < graph[i].size(); j++){
            cout << graph[i][j].first << "," << graph[i][j].second << " ";
        }
        
        cout << endl;
    }
}
int main(){
	int n;
	cin >> n;
	int m;
	cin >> m;

	vector<vector<pair<int, int>>> graph(n);
	for(int i = 0; i < m; i++){
		int s;
		int f;
		cin >> s >> f;

		graph[s - 1].push_back(make_pair(f - 1, 0));
		graph[f - 1].push_back(make_pair(s - 1, 1));
	}
	
//	printgraph(graph);

    dijkstra(graph);

	//cout << ans << endl;
	return 0;
}