class Solution {
public:
    bool helper(vector<vector<int>>& graph, int start, int *visited){
         bool flag = 0;
         queue<int> pending;
        //for group A == 10 
        //for group B == 20
        pending.push(start);
        visited[start] = 10;
        
        while(!pending.empty()){
            int front = pending.front();
            int group = visited[front];
            pending.pop();
            
            vector<int> neighbours = graph[front];
            
            for(int i = 0; i < neighbours.size(); i++){
                if(visited[neighbours[i]] == -1){
                    if(group == 10){
                        pending.push(neighbours[i]);
                        visited[neighbours[i]] = 20;
                    }
                    else{
                        pending.push(neighbours[i]);
                        visited[neighbours[i]] = 10;
                    }
                }
                else{
                    int ngroup = visited[neighbours[i]];
                    if(ngroup != group){
                        continue;
                    }
                    else if(ngroup == group){
                        flag = 1;
                    }
                }
            }
        }
        //printing
        for(int i = 0; i < graph.size(); i++){
            cout << visited[i] << " ";
        }
        cout << endl;
        if(flag == 0){
            return true;
        }
        else{
            return false;
        }
    }
    bool isBipartite(vector<vector<int>>& graph) {
       
        int *visited = new int[graph.size()];
        for(int i = 0; i < graph.size(); i++){
            visited[i] = -1;
        }
        bool flag = 0;
        for(int i = 0; i < graph.size(); i++){
            if(visited[i] == -1){
                if(!helper(graph, i, visited)){
                    return false;
                }
            }
        }
       return true;
    }
};