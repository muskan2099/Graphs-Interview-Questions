#include <bits/stdc++.h> 

using namespace std; 

void findcost(int n, vector<vector<int>> graph){
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
        
        for(int i = 0; i < n; i++){
            int ver = i;
            int cost = graph[node][i];
            
            if(!visited[ver] && key[ver] > cost && cost != 0){
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
int main() { 

// Input 1 
int n1 = 5; 
vector<vector<int>> city1 = {{0, 1, 2, 3, 4}, 
							{1, 0, 5, 0, 7}, 
							{2, 5, 0, 6, 0}, 
							{3, 0, 6, 0, 0}, 
							{4, 7, 0, 0, 0}}; 
findcost(n1, city1); 

// Input 2 
int n2 = 6; 
vector<vector<int>> city2 = {{0, 1, 1, 100, 0, 0}, 
							{1, 0, 1, 0, 0, 0}, 
							{1, 1, 0, 0, 0, 0}, 
							{100, 0, 0, 0, 2, 2}, 
							{0, 0, 0, 2, 0, 2}, 
							{0, 0, 0, 2, 2, 0}}; 
findcost(n2, city2); 

return 0; 
} 
