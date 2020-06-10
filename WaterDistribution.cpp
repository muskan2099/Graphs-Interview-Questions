#include <bits/stdc++.h>
using namespace std;
void prims(vector<vector<pair<int, int>>> graph){
    int n = graph.size();
    bool *visited = new bool(n);
    for(int i = 0; i < n; i++){
        visited[i] = 0;
    }
    int *key = new int[n];
    for(int i = 0; i < n; i++){
        key[i] = INT_MAX;
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;
    heap.push(make_pair(0, 0));
    key[0] = 0;
    
    while(!heap.empty()){
        pair<int, int> front = heap.top();
        heap.pop();
        int node = front.second;
        int weight = front.first;
        
        visited[node] = 1;
        
        for(int i = 0; i < graph[node].size(); i++){
            
            int ver = graph[node][i].first;
            int cost = graph[node][i].second;
            
            if(!visited[ver] && key[ver] > cost){
                key[ver] = cost;
                heap.push(make_pair(key[ver], ver));
            }
        }
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
       ans += key[i];
    }
    cout << ans << endl;
    
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
    
    int *input = new int[n];
    for(int i = 0; i < n; i++){
        cin >> input[i];
    }
    int k;
    cin >> k;
    int s;
    int f;
    int val;
    vector<vector<pair<int, int>>> graph(n+1);
    
    for(int i = 0; i < k; i++){
        
        cin >> s >> f >> val;
        graph[s-1].push_back(make_pair(f-1, val));
        graph[f-1].push_back(make_pair(s-1, val));
    }
    for(int i = 0; i < n; i++){
        graph[i].push_back(make_pair(n, input[i]));
    }
    for(int i = 0; i < n; i++){
        graph[n].push_back(make_pair(i, input[i]));
    }
    
    printgraph(graph);
    return 0;
}