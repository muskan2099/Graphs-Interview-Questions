bool impossible = false;
    
    typedef unordered_map<int,vector<int>> Graph;
    
    const int NOT_VISITED = 0;
    const int VISITING = 1;
    const int VISITED = 2;
    
    void dfs(Graph& g, int v, unordered_map<int,int>& visit, vector<int>& result) {
        if (visit[v] == VISITING) {
            // we have a cycle here
            impossible = true;
            return;
        }
        if (visit[v] == VISITED) {
            return;
        }
        if (visit[v] == NOT_VISITED) {
            visit[v] = VISITING;
            for (auto& to: g[v]) {
                dfs(g, to, visit, result);
            }
            visit[v] = VISITED;
            result.push_back(v);
        }
    }
    
    vector<int> topSort(Graph &g) {
        int n = g.size();
        unordered_map<int,int> visit;
        vector<int> result;
        for (auto& v: g) {
            dfs(g, v.first, visit, result);
        }
        return result;
    }
    
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        // for items: 
        //      if item not in group -> create new one of one item
        //  create G - graph of groups using beforeItem as edges
        //  create an array of lil graphs for each group
        //  topsort G (groups and items without group)
        //  for v in G
        //      topsort group[v]
        //      insert result
        
        for (int i = 0; i < n; i++) {
            if (group[i] == -1) {
                group[i] = m++;
            }
        }
        // initialize graphs
        Graph G;
        vector<Graph> groupG(m);
        for (int gr = 0; gr < m; gr++) {
            G[gr] = vector<int>();
            groupG[gr] = Graph();    
        }
        for (int i = 0; i < n; i++) {
            groupG[group[i]][i] = vector<int>();
        }
        // add edges
        for (int from = 0; from < n; from++) {
            auto gr = group[from];
            for (auto& to: beforeItems[from]) {
                if (group[from] == group[to]) {
                    // add edge to lil graph
                    auto gr = group[from]; 
                    groupG[gr][from].push_back(to);
                    G[gr];
                } else {
                    // add edge to graph of groups
                    G[group[from]].push_back(group[to]);
                    // printf("G(%d -> %d)\n", group[from], group[to]);
                }
            }
        }
        vector<int> result;
        auto groupOrder = topSort(G);
    
        for (auto gr: groupOrder) {
            auto itemInGroupOrder = topSort(groupG[gr]);
            // printf("gr[%d]=[", gr); for(auto i: itemInGroupOrder) printf("%d,", i); printf("]\n");
            result.insert(result.end(), itemInGroupOrder.begin(), itemInGroupOrder.end());
        }
        
        if (impossible) {
            return vector<int>();
        } else {
            return result;
        }
    }