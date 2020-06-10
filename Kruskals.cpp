#include <bits/stdc++.h>
using namespace std;
int find(vector<int> &parent, int nodes, int x){
        //cout << "THIS IS FIND" << endl;
        if(parent[x] == x){
            return x;
        }
        int px = find(parent, nodes, parent[x]);
        parent[x] = px;
        return px;
    }
    
    bool unionofdsu(vector<int> &parent, vector<int> &rank, int nodes, int a, int b){
        //cout << "THIS IS UNION" << endl;
        int la = find(parent, nodes, a);
        int lb = find(parent, nodes, b);
        if(la == lb){
        	return false;
        }
        else if(la != lb){
            if(rank[la] > rank[lb]){
                parent[lb] = la;
            }
            else if(rank[la] < rank[lb]){
                parent[la] = lb;
            }
            else{
                parent[la] = lb;
                rank[lb]++;
            }
        }
        return true;
    }
bool compare(pair<int, pair<int, int>> p1, pair<int, pair<int, int>> p2){
	return p1.first < p2.first;
}
void kruskals(vector<vector<pair<int, int>>> graph){
	
	vector<pair<int, pair<int, int>>> sortedgraph;
	for(int i = 0; i < graph.size(); i++){
		for(int j = 0; j < graph[i].size(); j++){
			int w = graph[i][j].second;
			int des = graph[i][j].first;
			sortedgraph.push_back(make_pair(w, make_pair(i, des)));
		}
	}
	sort(sortedgraph.begin(), sortedgraph.end(), compare);

	vector<int> parent(graph.size());
	vector<int> rank(graph.size());
	vector<pair<int, int>> mst;
	int ans = 0;
	for(int i = 0; i < graph.size(); i++){
		parent[i] = i;
		rank[i] = 1;
	}
	for(int i = 0; i < sortedgraph.size(); i++){
		int s = sortedgraph[i].second.first;
		int des = sortedgraph[i].second.second;
		int w = sortedgraph[i].first;

		if(unionofdsu(parent, rank, parent.size(), s, des)){
			ans += w;
			mst.push_back(make_pair(s, des));
		}
	}
	//print ans
	cout << ans << endl;
	cout << "The MST is as follows" << endl;

	for(int i = 0; i < mst.size(); i++){
		cout << mst[i].first << "," << mst[i].second << endl;
	}
}
int main(){

	vector<vector<pair<int, int>>> graph(4);

	graph[0].push_back(make_pair(1, 8));
	graph[0].push_back(make_pair(3, 16));
	graph[1].push_back(make_pair(0, 8));
	graph[1].push_back(make_pair(2, 10));
	graph[1].push_back(make_pair(3, 14));
	graph[2].push_back(make_pair(1, 10));
	graph[2].push_back(make_pair(3, 12));
	graph[3].push_back(make_pair(1, 14));
	graph[3].push_back(make_pair(2, 12));
	graph[3].push_back(make_pair(0, 16));

	kruskals(graph);
	return 0;
}