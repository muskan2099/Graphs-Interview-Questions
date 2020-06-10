class Solution {
public:
	//topological sort
void topologicalSortUtil(vector<vector<int>> graph, int v, bool* visited, stack<int> &st){ 
	visited[v] = 1;

	for(int i = 0; i < graph[v].size(); i++){

		if(!visited[graph[v][i]]){
			topologicalSortUtil(graph, graph[v][i], visited, st);
		}
	}
	st.push(v);
} 

stack<int> topologicalSort(vector<vector<int>> graph, int V) 
{ 
	stack<int> st;
	bool *visited = new bool[V];
	for(int i = 0; i < V; i++){
		visited[i] = 0;
	}

	for(int i = 0; i < V; i++){
		if(visited[i] == 0){
			topologicalSortUtil(graph, i, visited, st);
		}
	}
	return st;
} 
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        vector<vector<int>> graph(n + 2*m);
        for(int i = 0; i < n; i++){
        	if(group[i] == -1){
        		continue;
        	}
        	int gstart = n + 2*group[i];
        	int gend = n + 2*group[i] + 1;

        	graph[gstart].push_back(i);
        	graph[i].push_back(gend);
        }
        //handling neighbors
        for(int i = 0; i < beforeItems.size(); i++){
        	if(beforeItems[i].size() == 0){
        		continue;
        	}
        	for(int j = 0; j < beforeItems[i].size(); j++){
        		int before = beforeItems[i][j];
        		int groupofbefore = group[before];

        		int item = i;
        		int groupofitem = group[item];

        		//case 1:
        		if(groupofitem == -1 && groupofbefore == -1){
        			graph[before] = item;
        		}
        		//case 2:
        		else if(groupofitem != -1 && groupofbefore == -1){
        			int startofitem = n + 2*groupofitem;
        			graph[item] = startofitem;
        		}
        		//case 3:
        		else if(groupofitem == -1 && groupofbefore != -1){
        			int endofitem = n + 2*groupofitem + 1;
        			graph[endofitem] = item;
        		}
        		//case 4:
        		else if(groupofitem != -1 && groupofbefore 1= -1){
        			if(groupofitem == groupofbefore){
        				graph[before] = item;
        			}
        			else{
        				graph[n + 2*groupofbefore + 1] = n + 2*groupofitem;
        			}
        		}
        	}
        }
        stack<int> st;
        st = topologicalSort(graph, n + 2*m);

        vector<int> output;
        while(!st.empty()){
        	output.push_back(st.top());
        	st.pop();
        }
        return output;
    }
};